#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define CHECK_SIZE 1024

/**
 * check_arguments - checks if the number of arguments is correct
 * @argc: number of command-line arguments
 */
void check_arguments(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * open_files - open the input and output files
 * @argv: array of command-line arguments
 * @i_from: pointer to input file descriptor
 * @i_to: pointer to output file descriptor
 */
void open_files(char *argv[], int *i_from, int i_to)
{
	mode_t mode;

	*i_from = open(argv[1], O_RDONLY);
	if (*i_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	*i_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (*i_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(*i_from);
		exit(99);
	}
}

/**
 * copy_file - copies the content of one file to another file
 * @i_from: input file descriptor
 * @i_to: output file descriptor
 */
void copy_file(int i_from, int i_to)
{
	ssize_t r_read, w_written;
	char check[CHECK_SIZE];

	while ((r_read = read(i_from, check, CHECK_SIZE)) > 0)
	{
		w_written = write(i_to, check, r_read);
		if (w_written == -1 || w_written != r_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file\n");
			close(i_from);
			close(i_to);
			exit(99);
		}
	}

	if (r_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file\n");
		close(i_from);
		close(i_to);
		exit(98);
	}
}

/**
 * close_files - closes the input and output files
 * @i_from: input file descriptor
 * @i_to: output file descriptor
 */
void close_files(int i_from, int i_to)
{
	if (close(i_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", i_from);
		close(i_to);
		exit(100);
	}

	if (close(i_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", i_to);
		exit(100);
	}
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 (Success), 1-100 on error
 */
int main(int argc, char *argv[])
{
	int i_from, i_to;

	check_arguments(argc);
	open_files(argv, &i_from, &i_to);
	copy_file(i_from, i_to);
	close_files(i_from, i_to);

	return (0);
}

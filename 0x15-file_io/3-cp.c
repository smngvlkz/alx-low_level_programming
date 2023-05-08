#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define CHECK_SIZE 1024

/**
 * main - copies the content of one file to another file
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Retun: 0 on success, 1-100 on error
 */
int main(int argc, char *argv[])
{
	int i_from, i_to;
	ssize_t r_read, w_written;
	char check[CHECK_SIZE];
	mode_t mode;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	i_from = open(argv[1], O_RDONLY);
	if (i_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	i_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (i_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(i_from);
		exit(99);;;
	}

	while ((r_read = read(i_from, check, CHECK_SIZE)) > 0)
	{
		w_written = write(i_to, check, r_read);
		if (w_written == -1 || w_written != r_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write %s\n", argv[2]);
			close(i_from);
			close(i_to);
			exit(99);
		}
	}

	if (r_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(i_from);
		close(i_to);
		exit(98);
	}

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

	return (0);
}

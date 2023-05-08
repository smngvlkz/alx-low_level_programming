#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/**
 * read_textfile - reads a text file and prints it to to the POSIX stanard output
 * @filename: name of the file to read
 * @letters: number of leters to be read and printed
 *
 * Return: actual number of letters it could read and print
 */
size_t read_textfile(const char *filename, size_t letters)
{
	int i;
	ssize_t r_read, w_written;
	char *check;

	if (filename == NULL)
		return (0);

	i = open(filename, O_RDONLY);
	if (i == -1)
		return (0);

	check = malloc(sizeof(char) * letters);
	if (check == NULL)
		return (0);

	r_read = read(i, check, letters);
	if (r_read == -1)
		return (0);

	w_written = write(STDOUT_FILENO, check, r_read);
	if (w_written == -1 || w_written != r_read)
		return (0);

	close(i);
	free(check);

	return (w_written);
}

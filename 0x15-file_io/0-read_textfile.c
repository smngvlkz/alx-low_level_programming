#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * read_textfile - reads a text file and prints it to to the POSIX
 * standard output
 * @filename: name of the file to read
 * @letters: number of leters to be read and printed
 *
 * Return: actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_i;
	ssize_t n, r;
	char *buffer;

	if (filename == NULL)
		return (0);
	file_i = open(filename, O_RDONLY);
	if (file_i == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(file_i);
		return (0);
	}
	n = read(file_i, buffer, letters);
	close(file_i);
	if (n == -1)
	{
		free(buffer);
		return (0);
	}
	r = write(STDOUT_FILENO, buffer, n);
	free(buffer);
	if (n != r)
		return (0);
	return (n);
}

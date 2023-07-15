#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - read text file print to STDOUT
 * @filename: the text file being read
 * @letters: the number of letters to be read
 *
 * Return: the actual number of letters it could be read
 * and printed
 * 0 if function fails or filename is NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *fp;
	ssize_t n_read, n_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	fp = fopen(filename, "r");
	if (fp == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	n_read = fread(buffer, sizeof(char), letters, fp);
	if (n_read == 0 && ferror(fp))
		return (0);

	n_written = fwrite(buffer, sizeof(char), n_read, stdout);
	if (n_written != n_read || ferror(stdout))
		return (0);

	fclose(fp);
	free(buffer);

	return (n_written);
}

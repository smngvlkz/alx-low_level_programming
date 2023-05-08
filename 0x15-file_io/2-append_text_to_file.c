#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * append_text_to_file - appends text to file to the end of a file
 * @filename: name of the file
 * @text_content: NULL-terminnated string to add at the end of the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int i;
	ssize_t w_written;

	if (filename == NULL)
		return (-1);

	i = open(filename, O_WRONLY | O_APPEND);
	if (i == -1)
		return (-1);

	if (text_content != NULL)
	{
		w_written = write(i, text_content, strlen(text_content));
		if (w_written == -1)
			return (-1);
	}

	close(i);
	return (1);
}

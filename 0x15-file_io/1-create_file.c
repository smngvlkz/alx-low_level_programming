#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

/**
 * create_file - creates a file with the specified name and writes the
 * specified text content to it
 * @filename: name of the file to create
 * @text_content: NULL-terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int i;
	ssize_t w_written;
	mode_t mode;

	if (filename == NULL)
		return (-1);

	mode = S_IRUSR | S_IWUSR;
	i = open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);
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

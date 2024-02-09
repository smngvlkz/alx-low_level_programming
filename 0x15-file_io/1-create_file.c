#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * create_file - creates a file
 * @filename: a pointer to the name of the file
 * @text_content: pointer to a string to write
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fn;
	ssize_t w_written;
	mode_t mode = S_IRUSR | S_IWUSR;

	if (filename == NULL)
		return (-1);

	fn = open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fn == -1)
		return (-1);

	if (text_content != NULL)
	{
		w_written = write(fn, text_content, strlen(text_content));
		if (w_written == -1)
			return (-1);
	}

	close(fn);

	return (1);
}

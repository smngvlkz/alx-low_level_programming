#include "main.h"
#include <unistd.h>
#include <string.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: pointer to the name of the file
 * @text_content: string to add to the end of the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fn;
	ssize_t w_written;

	if (filename == NULL)
		return (-1);

	fn = open(filename, O_WRONLY | O_APPEND);
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

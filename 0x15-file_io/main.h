#include <stddef.h>
#ifndef MAIN_H
#define MAIN_H

size_t read_textfile(const char *filename, size_t lettersi);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif

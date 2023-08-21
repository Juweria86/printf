#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFF_SIZE 1024




int _printf(const char *format, ...);
int _putchar(char c);
int print_string(char *s);
void print_number(int count);
int _strlen(char *s);
void print_binary(unsigned int n);
#endif

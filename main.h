#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#define BUFF_SIZE 1024

int _printf(const char *format, ...);
int _strlen(char *s);
int _putchar(char c);
int print_string(char *s);
void print_number(int n);
#endif

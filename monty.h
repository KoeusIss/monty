#ifndef _MONTY_H
#define _MONTY_H

/* Libraries */
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/**
 * struct data_instance - data instance
 * @line: the readed line
 * @args: the arguments
 * Description: data instance, line, args
 * 
 */
typedef struct instance_s
{
	char *line;
	char **args;
} data_t;
/* Prototypes */
int process_line(data_t *data);
#endif /* _MONTY_H */

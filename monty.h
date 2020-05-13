#ifndef _MONTY_H
#define _MONTY_H

/* Libraries */
#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct data_instance - data instance
 * @line: the readed line
 * @args: the arguments
 * Description: data instance, line, args
 * 
 */
typedef struct instance_s
{
	int line_number;
	char *line;
	char **args;
        FILE *fp;
        char *filename;
} data_t;

extern data_t data;

/* Prototypes */
int process_line(stack_t **stack);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void add_dnodeint(stack_t **stack, unsigned int line_number);
void push_error(short int err_code);
void free_data(void);
void print_dlistint(stack_t **stack, unsigned int line_number);
#endif /* _MONTY_H */

#ifndef _MONTY_H
#define _MONTY_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
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

typedef struct glo_s
{
	FILE *fp;
	char *line_buff;
	char *bigb;
	int node_data;
} glo_t;
extern glo_t glo;

char token(unsigned int c, stack_t *head);
void integer_error(unsigned int c, stack_t *head);

#endif
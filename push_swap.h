#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
#include <limits.h>
#include <stdlib.h>
/* Stack structures */

typedef struct s_node
{
    int             value;
    struct s_node   *next;
}   t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
}   t_stack;

/* Parsing */

int     parse_number(const char *str, int *number);
int     parse_args(int argc, char **argv, int **numbers, int *size);

/* Input validation */

int     has_duplicates(const int *numbers, int size);
int     is_sorted(const int *numbers, int size);

/* Stack initialization */

int     stack_init(t_stack *stack, const int *numbers, int size);
void    stack_clear(t_stack *stack);

#endif
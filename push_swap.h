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

typedef enum e_operation
{
    OP_SA,
    OP_SB,
    OP_SS,
    OP_PA,
    OP_PB,
    OP_RA,
    OP_RB,
    OP_RR,
    OP_RRA,
    OP_RRB,
    OP_RRR,
    OP_COUNT
}   t_operation;

typedef struct s_op_count
{
    int operations[OP_COUNT];
    int total;
}   t_op_count;

typedef enum e_strategy
{
    STRATEGY_SIMPLE,
    STRATEGY_MEDIUM,
    STRATEGY_COMPLEX,
    STRATEGY_ADAPTIVE
}   t_strategy;

/* Parsing */
double  compute_disorder(const t_stack *a);
int     parse_number(const char *str, int *number);
int     parse_args(int argc, char **argv, int **numbers, int *size);

/* Input validation */

int     has_duplicates(const int *numbers, int size);
int     is_sorted(const int *numbers, int size);

/* Stack initialization */

int     stack_init(t_stack *stack, const int *numbers, int size);
void    stack_clear(t_stack *stack);
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

/* Benchmark */

void    operation_count_init(t_op_count *count);
void    operation_count_add(t_op_count *count, t_operation op);

#endif
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>


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

/* Push_swap operations */

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

/* Operation counters */

typedef struct s_op_count
{
    int operations[OP_COUNT];
    int total;
}   t_op_count;

/* Sorting strategies */

typedef enum e_strategy
{
    STRATEGY_SIMPLE,
    STRATEGY_MEDIUM,
    STRATEGY_COMPLEX,
    STRATEGY_ADAPTIVE
}   t_strategy;

/* Benchmark data */

typedef struct s_bench
{
    double      disorder;
    t_strategy  requested_strategy;
    t_strategy  strategy;
    t_op_count  count;
}   t_bench;

/* Benchmark options */

typedef struct s_bench_options
{
    int         bench_enabled;
    t_strategy  requested_strategy;
    int         numbers_start;
    int strategy_selected;
}   t_bench_options;

/* Parsing */

int     parse_number(const char *str, int *number);
int     parse_args(int argc, char **argv, int **numbers, int *size);

/* Input validation */

int     has_duplicates(const int *numbers, int size);
int     is_sorted(const int *numbers, int size);

/* Stack management */

int     stack_init(t_stack *stack, const int *numbers, int size);
void    stack_clear(t_stack *stack);

/* Stack operations: Swap */

void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    operation_output(t_operation op);

/* Stack operations: Push */

void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);

/* Stack operations: Rotate */

void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);

/* Stack operations: Reverse rotate */

void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

/* Benchmark: Disorder and strategy */

double      compute_disorder(const t_stack *a);
t_strategy  select_strategy(t_strategy requested, double disorder);

/* Benchmark: Operation counting */

void    operation_count_init(t_op_count *count);
void    operation_count_add(t_op_count *count, t_operation op);

/* Benchmark: Execution */

void    benchmark_init(t_bench *bench, const t_stack *a,
            t_strategy requested);
void    benchmark_execute(t_bench *bench, t_stack *a,
            t_stack *b, t_operation op);
void    benchmark_finish(const t_bench *bench);

/* Benchmark: Report */

void    benchmark_report(double disorder, t_strategy strategy,
            const t_op_count *count);

/* Benchmark: Options */

void    benchmark_options_init(t_bench_options *options);
int     benchmark_options_parse(int argc, char **argv,
            t_bench_options *options);

/* Sorting strategies */

void    strategy_execute(t_bench *bench, t_stack *a, t_stack *b);
void    simple_sort(t_bench *bench, t_stack *a, t_stack *b);
void    medium_sort(t_bench *bench, t_stack *a, t_stack *b);
void    complex_sort(t_bench *bench, t_stack *a, t_stack *b);

#endif
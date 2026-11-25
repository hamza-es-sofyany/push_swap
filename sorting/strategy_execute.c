
#include "../push_swap.h"

void    strategy_execute(t_bench *bench, t_stack *a, t_stack *b)
{
    if (!bench || !a || !b)
        return ;
    if (bench->strategy == STRATEGY_SIMPLE)
        simple_sort(bench, a, b);
    else if (bench->strategy == STRATEGY_MEDIUM)
        medium_sort(bench, a, b);
    else if (bench->strategy == STRATEGY_COMPLEX)
        complex_sort(bench, a, b);
}
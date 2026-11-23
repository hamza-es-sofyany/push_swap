#include "../push_swap.h"

void    operation_count_init(t_op_count *count)
{
    int i;
    
    if (!count)
        return ;
    i = 0;
    while (i < OP_COUNT)
    {
        count->operations[i] = 0;
        
        i++;
    }
    count->total = 0;
}

void    operation_count_add(t_op_count *count, t_operation op)
{
    if (!count || op < 0 || op >= OP_COUNT)
        return ;
    count->operations[op]++;
    count->total++;
}

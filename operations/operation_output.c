#include "../push_swap.h"

void    operation_output(t_operation op)
{
    static const char *operation_names[OP_COUNT] = {
        "sa",
        "sb",
        "ss",
        "pa",
        "pb",
        "ra",
        "rb",
        "rr",
        "rra",
        "rrb",
        "rrr"
    };
    if(op < OP_SA || op >= OP_COUNT)
        return;
    ft_printf("%s\n",operation_names[(int)op]);
}
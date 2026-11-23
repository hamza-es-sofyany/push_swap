
#include "../push_swap.h"


void    rra(t_stack *a)
{
    t_node  *tmp;
    t_node  *prev;
    if (!a || !a->top || !a->top->next)
        return ;
    prev = NULL;
    tmp = a->top;
    while (tmp->next)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = NULL;
    tmp->next = a->top;
    a->top = tmp;
}

void    rrb(t_stack *b)
{
    t_node  *tmp;
    t_node  *prev;
    if (!b || !b->top || !b->top->next)
        return ;
    prev = NULL;
    tmp = b->top;
    while (tmp->next)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = NULL;
    tmp->next = b->top;
    b->top = tmp;
}

void    rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
}

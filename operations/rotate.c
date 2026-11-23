#include "../push_swap.h"

void    ra(t_stack *a)
{
    t_node *first;
    t_node  *last;
    if (!a || !a->top || !a->top->next)
        return ;
    first = a->top;
    a->top = first->next;
    last = a->top;
    while (last->next)
        last = last->next;
    first->next = NULL;
    last->next = first;
}

void    rb(t_stack *b)
{
    t_node *first;
    t_node  *last;
    if (!b || !b->top || !b->top->next)
        return ;
    first = b->top;
    b->top = first->next;
    last = b->top;
    while (last->next)
        last = last->next;
    first->next = NULL;
    last->next = first;
}

void    rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
}



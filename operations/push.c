#include "../push_swap.h"

void    pa(t_stack *a, t_stack *b)
{
    t_node *tmp;
    if (!a || !b || !b->top)
        return ;
    tmp = b->top;
    b->top = b->top->next;
    tmp->next = a->top;
    a->top = tmp;
    a->size++;
    b->size--;
}

void    pb(t_stack *a, t_stack *b)
{
    t_node *tmp;
    if (!a || !b || !a->top)
        return ;
    tmp = a->top;
    a->top = a->top->next;
    tmp->next = b->top;
    b->top = tmp;
    b->size++;
    a->size--;
}

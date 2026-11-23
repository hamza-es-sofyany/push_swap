#include "../push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	if (!a || !a->top || !a->top->next)
		return ;
	tmp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = tmp;
}

void	sb(t_stack *b)
{
	int	tmp;

	if (!b || !b->top || !b->top->next)
		return ;
	tmp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = tmp;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

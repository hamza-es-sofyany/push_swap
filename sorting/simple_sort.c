
#include "../push_swap.h"


static int	find_min_position(const t_stack *a)
{
	t_node	*current;
	int		min_value;
	int		min_pos;
	int		pos;

	current = a->top;
	min_value = current->value;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

static void	move_min_to_top(t_bench *bench, t_stack *a, t_stack *b)
{
	int	min_pos;
	int	i;

	min_pos = find_min_position(a);
	i = 0;
	if (min_pos <= a->size / 2)
	{
		while (i < min_pos)
		{
			benchmark_execute(bench, a, b, op_ra);
			i++;
		}
	}
	else
	{
		while (i < a->size - min_pos)
		{
			benchmark_execute(bench, a, b, op_rra);
			i++;
		}
	}
	benchmark_execute(bench, a, b, op_pb);
}

void	simple_sort(t_bench *bench, t_stack *a, t_stack *b)
{
	if (!bench || !a || !b)
		return ;
	while (a->size > 0)
		move_min_to_top(bench, a, b);
	while (b->size > 0)
		benchmark_execute(bench, a, b, op_pa);
}
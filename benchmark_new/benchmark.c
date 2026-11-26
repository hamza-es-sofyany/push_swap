
#include "../push_swap.h"

static double	compute_disorder(const t_stack *a)
{
	unsigned long long	mistakes;
	const t_node		*current;
	const t_node		*next;

	if (!a || a->size < 2)
		return (0.0);
	mistakes = 0;
	current = a->top;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (current->value > next->value)
				mistakes++;
			next = next->next;
		}
		current = current->next;
	}
	return ((double)mistakes
		/ ((double)a->size * (a->size - 1) / 2));
}

static void	execute_operation(t_stack *a, t_stack *b,
		t_operation op)
{
	if (op == op_sa)
		sa(a);
	else if (op == op_sb)
		sb(b);
	else if (op == op_ss)
		ss(a, b);
	else if (op == op_pa)
		pa(a, b);
	else if (op == op_pb)
		pb(a, b);
	else if (op == op_ra)
		ra(a);
	else if (op == op_rb)
		rb(b);
	else if (op == op_rr)
		rr(a, b);
	else if (op == op_rra)
		rra(a);
	else if (op == op_rrb)
		rrb(b);
	else if (op == op_rrr)
		rrr(a, b);
}

void	benchmark_init(t_bench *bench, const t_stack *a,
		t_strategy requested)
{
	if (!bench || !a)
		return ;
	bench->disorder = compute_disorder(a);
	bench->requested_strategy = requested;
	bench->strategy = requested;
	if (requested == strategy_adaptive)
	{
		if (bench->disorder < 0.2)
			bench->strategy = strategy_simple;
		else if (bench->disorder < 0.5)
			bench->strategy = strategy_medium;
		else
			bench->strategy = strategy_complex;
	}
	ft_bzero(bench->operations, sizeof(bench->operations));
	bench->total = 0;
}

void	benchmark_execute(t_bench *bench, t_stack *a,
		t_stack *b, t_operation op)
{
	if (!bench || !a || !b || op < op_sa || op >= op_count)
		return ;
	execute_operation(a, b, op);
	operation_output(op);
	bench->operations[op]++;
	bench->total++;
}

void	benchmark_finish(const t_bench *bench)
{
	if (!bench)
		return ;
	benchmark_report(bench);
}

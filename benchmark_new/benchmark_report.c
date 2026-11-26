
#include "../push_swap.h"

static const char	*get_strategy_name(t_strategy strategy)
{
	if (strategy == strategy_simple)
		return ("Simple");
	else if (strategy == strategy_medium)
		return ("Medium");
	else if (strategy == strategy_complex)
		return ("Complex");
	else if (strategy == strategy_adaptive)
		return ("Adaptive");
	return (NULL);
}

static const char	*get_complexity_name(t_strategy strategy)
{
	if (strategy == strategy_simple)
		return ("O(n^2)");
	else if (strategy == strategy_medium)
		return ("O(n * sqrt(n))");
	else if (strategy == strategy_complex)
		return ("O(n log n)");
	return (NULL);
}

static void	print_disorder(double disorder)
{
	int	value;

	value = (int)(disorder * 10000 + 0.5);
	if (value % 100 < 10)
		ft_dprintf(2, "[bench] disorder: %d.0%d%%\n",
			value / 100, value % 100);
	else
		ft_dprintf(2, "[bench] disorder: %d.%d%%\n",
			value / 100, value % 100);
}

static void	print_operation_counts(const int *operations)
{
	ft_dprintf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		operations[op_sa], operations[op_sb], operations[op_ss],
		operations[op_pa], operations[op_pb]);
	ft_dprintf(2, "[bench] ra: %d rb: %d rr: %d rra: %d "
		"rrb: %d rrr: %d\n",
		operations[op_ra], operations[op_rb], operations[op_rr],
		operations[op_rra], operations[op_rrb], operations[op_rrr]);
}

void	benchmark_report(const t_bench *bench)
{
	const char	*strategy_name;
	const char	*complexity_name;

	if (!bench)
		return ;
	strategy_name = get_strategy_name(bench->requested_strategy);
	complexity_name = get_complexity_name(bench->strategy);
	if (!strategy_name || !complexity_name)
		return ;
	print_disorder(bench->disorder);
	ft_dprintf(2, "[bench] strategy: %s / %s\n",
		strategy_name, complexity_name);
	ft_dprintf(2, "[bench] total_ops: %d\n", bench->total);
	print_operation_counts(bench->operations);
}

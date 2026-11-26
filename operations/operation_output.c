
#include "../push_swap.h"

void	operation_output(t_operation op)
{
	static const char	*operation_names[op_count] = {
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

	if (op < op_sa || op >= op_count)
		return ;
	ft_printf("%s\n", operation_names[(int)op]);
}

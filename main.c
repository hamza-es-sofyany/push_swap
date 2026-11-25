#include "push_swap.h"
#include <unistd.h>

static int print_error(void)
{
    write(2, "Error\n", 6);
    return (1);
}

static int prepare_input(int ac, char **av,
    t_bench_options *options, int **numbers, int *size, int *sorted)
{
    if (!benchmark_options_parse(ac, av, options))
        return (0);
    if(options->numbers_start == ac)
        return (0);
    if(!parse_args(ac - options->numbers_start + 1,
        &av[options->numbers_start - 1], numbers, size))
        return (0);
    if (has_duplicates(*numbers, *size))
    {
        free(*numbers);
        *numbers = NULL;
        return (0);
    }
    *sorted = is_sorted(*numbers, *size);
    return (1);
}

static int init_stacks(int *numbers, int size, t_stack *a, t_stack *b)
{
    if (!stack_init(a, numbers, size))
    {
        free(numbers);
        return (0);
    }
    free(numbers);
    if (!stack_init(b, NULL, 0))
    {
        stack_clear(a);
        return (0);
    }
    return (1);   
}

static void run_program(t_bench *bench, t_bench_options *option,
    t_stack *a, t_stack *b, int sorted)
{
    benchmark_init(bench, a, option->requested_strategy);
    if (!sorted)
        strategy_execute(bench, a, b);
    if (option->bench_enabled)
        benchmark_finish(bench);
}

static int	process_input(int ac, char **av)
{
	int				*numbers;
	int				size;
	int				sorted;
	t_stack			a;
	t_stack			b;
	t_bench_options	options;
	t_bench			bench;

	numbers = NULL;
	size = 0;
	if (!prepare_input(ac, av, &options, &numbers, &size, &sorted))
		return (print_error());
	if (sorted && !options.bench_enabled)
		return (free(numbers), 0);
	if (!init_stacks(numbers, size, &a, &b))
		return (print_error());
	run_program(&bench, &options, &a, &b, sorted);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	return (process_input(argc, argv));
}

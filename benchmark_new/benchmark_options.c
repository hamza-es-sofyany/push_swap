
#include "../push_swap.h"

static void	benchmark_options_init(t_bench_options *options)
{
	if (!options)
		return ;
	options->bench_enabled = 0;
	options->numbers_start = 1;
	options->requested_strategy = strategy_adaptive;
}

static int	parse_strategy_option(const char *arg,
		t_strategy *strategy)
{
	int			i;
	static const char	*strategy_names[4] = {
		"--simple",
		"--medium",
		"--complex",
		"--adaptive"
	};

	if (!arg || !strategy)
		return (0);
	i = 0;
	while (i < 4)
	{
		if (ft_strncmp(arg, strategy_names[i],
				ft_strlen(strategy_names[i]) + 1) == 0)
		{
			*strategy = (t_strategy)i;
			return (1);
		}
		i++;
	}
	return (0);
}

static int	parse_option(const char *arg, t_bench_options *options,
		int *strategy_count)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		options->bench_enabled = 1;
		return (1);
	}
	if (!parse_strategy_option(arg, &options->requested_strategy))
		return (0);
	(*strategy_count)++;
	if (*strategy_count > 1)
		return (-1);
	return (1);
}

static int	scan_options(int argc, char **argv,
		t_bench_options *options)
{
	int	i;
	int	strategy_count;
	int	status;

	i = 1;
	strategy_count = 0;
	while (i < argc)
	{
		status = parse_option(argv[i], options, &strategy_count);
		if (status < 0)
			return (0);
		if (status == 0)
		{
			options->numbers_start = i;
			break ;
		}
		i++;
	}
	if (i == argc)
		options->numbers_start = argc;
	return (1);
}

int	benchmark_options_parse(int argc, char **argv,
		t_bench_options *options)
{
	if (argc < 1 || !argv || !options)
		return (0);
	benchmark_options_init(options);
	return (scan_options(argc, argv, options));
}

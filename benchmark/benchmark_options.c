

#include "../push_swap.h"



void    benchmark_options_init(t_bench_options *options)
{
    if (!options)
        return ;
    options->bench_enabled = 0;
    options->numbers_start = 1;
    options->requested_strategy = STRATEGY_ADAPTIVE;
}


static int parse_strategy_option(const char *arg, t_strategy *strategy)
{
    int i;
    static const char *strategy_names[4] = {
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
        if (ft_strncmp(arg, strategy_names[i], ft_strlen(strategy_names[i]) + 1) == 0)
        {
            *strategy = (t_strategy)i;
            return (1);
        }
        i++;
    }
    return (0);
}

int     benchmark_options_parse(int argc, char **argv, t_bench_options *options)
{
    int i;

    if (argc < 1 || !argv || !options)
        return (0);

    benchmark_options_init(options);
    i = 1;
    while (i < argc)
    {
        if (ft_strncmp(argv[i], "--bench", 8) == 0)
            options->bench_enabled = 1;
        else if (!parse_strategy_option(argv[i], &options->requested_strategy))
        {
            options->numbers_start = i;
            break;
        }
        
        i++;
    }
    if (i == argc)
        options->numbers_start = argc;
        
    return (1);
}

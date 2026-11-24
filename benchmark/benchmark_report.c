
#include "../push_swap.h"

static const char *get_complexity_name(t_strategy strategy, double disorder)
{

    if (strategy == STRATEGY_SIMPLE)
        return ("O(n^2)");
    else if (strategy == STRATEGY_MEDIUM)
        return ("O(n * sqrt(n))");
    else if (strategy == STRATEGY_COMPLEX)
        return ("O(n log n)");
    else if (strategy == STRATEGY_ADAPTIVE)
    {
        if (disorder < 0.2)
            return ("O(n^2)");
        else if (disorder < 0.5)
            return ("O(n * sqrt(n))");
        else
            return ("O(n log n)");
    }
    return (NULL);
}

static void print_total_operations(const t_op_count *count)
{
    ft_dprintf(2, "[bench] total_ops: %d\n", count->total);
}

static void print_disorder(double disorder)
{
    int disorder_hundredths;

    disorder_hundredths = (int)(disorder * 10000 + 0.5);
    if (disorder_hundredths % 100 < 10)
        ft_dprintf(2, "[bench] disorder: %d.0%d%%\n",
            disorder_hundredths / 100, disorder_hundredths % 100);
    else
        ft_dprintf(2, "[bench] disorder: %d.%d%%\n",
            disorder_hundredths / 100, disorder_hundredths % 100);
}

void    benchmark_report(double disorder, t_strategy strategy,
            const t_op_count *count)
{
    const char *complexity_name;
    const char *strategy_name;
    const char *strategy_names[4] = {
        "Simple",
        "Medium",
        "Complex",
        "Adaptive"
    };
    if ((int)strategy < STRATEGY_SIMPLE || (int)strategy > STRATEGY_ADAPTIVE)
        return ;
    strategy_name = strategy_names[strategy];
    complexity_name = get_complexity_name(strategy, disorder);
    if (!count)
        return ;
    print_disorder(disorder);
    ft_dprintf(2, "[bench] strategy: %s / %s\n",
    strategy_name, complexity_name);
    print_total_operations(count);
}

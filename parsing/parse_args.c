
#include "../push_swap.h"

static void ft_free(char **av)
{
    int i;

    i = 0;
    while (av[i])
    {
        free(av[i]);
        i++; 
    }
    free(av);
}

static int fill_numbers(int argc, char **argv, int *numbers)
{
    int i;
    int j;
    int index;
    char **tokens;

    i = 1;
    index = 0;
    while (i < argc)
    {
        j = 0;
        tokens = ft_split(argv[i], ' ');
        if (!tokens)
            return (0);
        while (tokens[j])
        {
            if (!parse_number(tokens[j], &numbers[index]))
            {
                ft_free(tokens);
                return (0);
            }
            j++;
            index++;
        }
        ft_free(tokens);
        i++;
    }
    return (1);
}

static int count_one_arg(char *arg, int *count)
{
    int i;
    char    **tokens;

    i = 0;
    tokens = ft_split(arg, ' ');
    if (!tokens)
        return (0);
    while (tokens[i])
        i++;
    if (i == 0)
    {
       ft_free(tokens);
       return (0); 
    }
    *count += i;
    ft_free(tokens);
    return (1);
}

static int count_args(int argc, char **argv, int *count)
{
    int i;
    int ret;

    i = 1;
    while (i < argc)
    {
        ret = count_one_arg(argv[i], count);
        if (ret == 0)
            return (0);
        i++;
    }
    return (1);
}


int     parse_args(int argc, char **argv, int **numbers, int *size)
{
    int count;

    if (!numbers || !size)
        return (0);
    *numbers = NULL;
    *size = 0;
    if (!argv)
        return (0);
    if (argc == 1)
        return (1);
    count = 0;
    if (!count_args(argc, argv, &count))
        return (0);
    if (count == 0)
        return (0);
    *numbers= malloc(sizeof(int) * count);
    if (!*numbers)
        return (0);
    if (!fill_numbers(argc, argv, *numbers))
    {
        free(*numbers);
        *numbers = NULL;
        return (0);
    }
    *size = count;
    return (1);
}

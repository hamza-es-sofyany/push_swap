
#include "../push_swap.h"

int     parse_args(int argc, char **argv, int **numbers, int *size)
{
    int count;
    int i;

    if (!numbers || !size)
        return (0);
    *numbers = NULL;
    *size = 0;
    if (!argv)
        return (0);
    if (argc == 1)
        return (1);
    count = argc - 1;
    *numbers = malloc(sizeof(int *) * count);
    if (!*numbers)
        return (0);
    i = 0;
    while (i < count)
    {
        if (!parse_number(argv[i + 1], &(*numbers)[i]))
        {
            free(*numbers);
            *numbers = NULL;
            return (0);
        }
        i++;
    }
    *size = count;
    return (1);
}
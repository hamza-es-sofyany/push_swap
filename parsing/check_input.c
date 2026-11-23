#include "../push_swap.h"

int has_duplicates(const int *numbers, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 1;
        while (i + j < size)
        {
            if (numbers[i] == numbers[i + j])
            return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int is_sorted(const int *numbers, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (i + 1 < size && numbers[i] > numbers[i + 1])
            return (0);
        i++;
    }
    return (1);
}
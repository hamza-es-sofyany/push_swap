#include "push_swap.h"
#include <unistd.h>

int main(int argc, char **argv)
{
    int     *numbers;
    int     size;
    t_stack a;
    t_stack b;

    if (argc == 1)
        return (0);
    numbers = NULL;
    size = 0;
    if (!parse_args(argc, argv, &numbers, &size))
        return (write(2, "Error\n", 6), 1);
    if (has_duplicates(numbers, size))
    {
        free(numbers);
        write(2, "Error\n", 6);
        return (1);
    }
    if (is_sorted(numbers, size))
    {
        free(numbers);
        return (0);
    }
    if (!stack_init(&a, numbers, size))
    {
        free(numbers);
        write(2, "Error\n", 6);
        return (1);
    }
    free(numbers);
    if (!stack_init(&b, NULL, 0))
    {
        stack_clear(&a);
        write(2, "Error\n", 6);
        return (1);
    }
    stack_clear(&a);
    stack_clear(&b);
    return (0);
}
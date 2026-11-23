#include "../push_swap.h"

/* Counts pairs where a larger value appears before a smaller value. */

static unsigned long long count_mistakes(const t_stack *a)
{
    unsigned long long mistakes;
    const t_node *current;
    const t_node *next;
    if (!a || !a->top)
        return (0);
    
    mistakes = 0;
    current = a->top;
    while (current)
    {
        next = current->next;
        while (next)
        {
            if (next->value < current->value)
                mistakes++;
            next = next->next;
        }
        current = current->next;
    }
    return (mistakes);
}

/* Calculates the disorder ratio of the stack. */

double compute_disorder(const t_stack *a)
{
    unsigned long long mistakes;
    unsigned long long total_pairs;
    double  tout;
    if (!a || a->size < 2)
        return (0.0);
    total_pairs = (a->size * (a->size - 1)) / 2;
    mistakes = count_mistakes (a);
    tout = (double)mistakes / total_pairs;
    return (tout);
}

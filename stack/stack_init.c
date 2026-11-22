
#include "../push_swap.h"

void stack_clear(t_stack *stack)
{
    t_node *current;
    t_node *next;

    if (!stack)
        return ;
    current = stack->top;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    stack->top = NULL;
    stack->size = 0;
}


int stack_init(t_stack *stack, const int *numbers, int size)
{
    int i;
    t_node  *new_node;
    t_node  *last;

    if (!stack || size < 0 || (size > 0 && !numbers))
        return (0);

    stack->top = NULL;
    stack->size = 0;
    if (size == 0)
        return (1);    
    i = 0;    
    while (i < size)
    {
        new_node = malloc(sizeof(t_node));
        if (!new_node)
        {
            stack_clear(stack);
            return (0);
        }
        new_node->value = numbers[i];
        new_node->next = NULL;
        if (i == 0)
        {
            stack->top = new_node;
            last = new_node;
        }
        else
        {
            last->next = new_node;
            last = new_node;
        }
        stack->size++;
        i++;
    }
    return (1);
}

#include "../push_swap.h"

void	stack_clear(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

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

static int	stack_fill(t_stack *stack, t_node **last, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = NULL;
	if (!stack->top)
	{
		stack->top = new_node;
		*last = new_node;
	}
	else
	{
		(*last)->next = new_node;
		*last = new_node;
	}
	stack->size++;
	return (1);
}

int	stack_init(t_stack *stack, const int *numbers, int size)
{
	int		i;
	t_node	*last;

	if (!stack || size < 0 || (size > 0 && !numbers))
		return (0);
	stack->top = NULL;
	stack->size = 0;
	if (size == 0)
		return (1);
	i = 0;
	last = NULL;
	while (i < size)
	{
		if (!stack_fill(stack, &last, numbers[i]))
		{
			stack_clear(stack);
			return (0);
		}
		i++;
	}
	return (1);
}


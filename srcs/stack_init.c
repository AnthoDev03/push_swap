#include "../includes/push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->head = NULL;
	return (stack);
}

void	stack_a_init(int *data, t_stack *stack_a, int argc)
{
	int	i;

	i = argc - 2;
	while (i >= 0)
	{
		push(stack_a, data[i]);
		i--;
	}
}

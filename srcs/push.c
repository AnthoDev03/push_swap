#include "../includes/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->head != NULL)
	{
		push(stack_a, pop(stack_b));
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->head != NULL)
	{
		push(stack_b, pop(stack_a));
		write(1, "pb\n", 3);
	}
}

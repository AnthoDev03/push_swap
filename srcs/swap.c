#include "../includes/push_swap.h"

void	swap_first_two(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->head != NULL && stack->head->next != NULL)
	{
		first = stack->head;
		second = stack->head->next;
		first->next = second->next;
		second->next = first;
		stack->head = second;
	}
}

void	sb(t_stack *stack_b)
{
	swap_first_two(stack_b);
	write(1, "sb\n", 3);
}

void	sa(t_stack *stack_a)
{
	swap_first_two(stack_a);
	write(1, "sa\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_first_two(stack_a);
	swap_first_two(stack_b);
	write(1, "ss\n", 3);
}

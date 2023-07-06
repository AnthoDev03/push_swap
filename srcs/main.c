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

void	sort_3_elements(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->head->data;
	second = stack_a->head->next->data;
	third = stack_a->head->next->next->data;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && third < second && first > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (second < first && first > third && second < third)
		ra(stack_a);
	else if (second > third && third > first && second > first)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (third < first && first < second && second > third)
		rra(stack_a);
}

void	sort_5_elements(t_stack *stack_a, t_stack *stack_b)
{
	push_two_smallest(stack_a, stack_b);
	sort_3_elements(stack_a);
	if (stack_b->head->data < stack_b->head->next->data)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack_init();
	stack_b = stack_init();
	if (test(argc, argv) == 0)
	{
		write(1, "ERROR\n", 6);
		exit(EXIT_FAILURE);
	}
	stack_a_init(transform(argc, argv), stack_a, argc);
	if (issorted(stack_a) == true)
	{
		exit(EXIT_SUCCESS);
	}
	if (argc == 4)
		sort_3_elements(stack_a);
	if (argc == 6)
		sort_5_elements(stack_a, stack_b);
	else if (argc > 6)
	{
		radix_sort(stack_a, stack_b);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:34:03 by anthrodr          #+#    #+#             */
/*   Updated: 2023/07/10 14:34:08 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	sort_stacks(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	stack_a_init(transform(argc, argv), stack_a, argc);
	if (issorted(stack_a) == true)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(EXIT_SUCCESS);
	}
	if (argc == 3)
	{
		if (stack_a->head->data < stack_a->head->next->data)
			sa(stack_a);
	}
	else if (argc == 4)
		sort_3_elements(stack_a);
	else if (argc == 5)
		radix_sort(stack_a, stack_b);
	else if (argc == 6)
		sort_5_elements(stack_a, stack_b);
	else if (argc > 6)
		radix_sort(stack_a, stack_b);
	if (issorted(stack_a) == true)
		exit(EXIT_SUCCESS);
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 2)
	{
		stack_a = stack_init();
		stack_b = stack_init();
		if (test(argc, argv) == 0)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		sort_stacks(argc, argv, stack_a, stack_b);
	}
	write(2, "Error\n", 6);
}

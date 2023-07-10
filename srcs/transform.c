/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:35:24 by anthrodr          #+#    #+#             */
/*   Updated: 2023/07/10 14:35:25 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	perform_pushes(t_stack *stack_a, t_stack *stack_b, int smallest1,
		int smallest2)
{
	int		count;
	t_node	*current;
	t_node	*next_node;

	count = 0;
	current = stack_a->head;
	while (current != NULL && count < 2)
	{
		next_node = current->next;
		if (current->data == smallest1 || current->data == smallest2)
		{
			pb(stack_a, stack_b);
			count++;
		}
		else
			ra(stack_a);
		current = next_node;
	}
}

void	find_two_smallest(t_stack *stack_a, int *smallest1, int *smallest2)
{
	int		data;
	t_node	*current;

	*smallest1 = INT_MAX;
	*smallest2 = INT_MAX;
	current = stack_a->head;
	while (current != NULL)
	{
		data = current->data;
		if (data < *smallest1)
		{
			*smallest2 = *smallest1;
			*smallest1 = data;
		}
		else if (data < *smallest2 && data != *smallest1)
			*smallest2 = data;
		current = current->next;
	}
}

void	push_two_smallest(t_stack *stack_a, t_stack *stack_b)
{
	int	smallest1;
	int	smallest2;

	find_two_smallest(stack_a, &smallest1, &smallest2);
	perform_pushes(stack_a, stack_b, smallest1, smallest2);
}

void	calculate_new_data_array(int *data, int *data2, int size)
{
	int	idx2;
	int	idx;
	int	newdata;

	idx2 = 0;
	while (idx2 < size)
	{
		idx = 0;
		newdata = 0;
		while (idx < size)
		{
			if (data[idx2] > data[idx])
				newdata++;
			idx++;
		}
		data2[idx2] = newdata;
		idx2++;
	}
}

void	fill_data_array(int argc, char **argv, int *data)
{
	int	idx;

	idx = 1;
	while (idx < argc)
	{
		data[idx - 1] = ft_atoi(argv[idx]);
		idx++;
	}
}

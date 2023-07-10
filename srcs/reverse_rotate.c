/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:34:42 by anthrodr          #+#    #+#             */
/*   Updated: 2023/07/10 14:34:44 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*prev;
	t_node	*temp;

	last = NULL;
	prev = NULL;
	temp = stack->head;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	last = temp;
	prev->next = NULL;
	last->next = stack->head;
	stack->head = last;
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}

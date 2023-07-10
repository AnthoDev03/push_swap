/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:34:48 by anthrodr          #+#    #+#             */
/*   Updated: 2023/07/10 14:34:49 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*temp;

	first = stack->head;
	second = first->next;
	stack->head = second;
	temp = second;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 2);
}

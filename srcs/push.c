/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:34:25 by anthrodr          #+#    #+#             */
/*   Updated: 2023/07/10 14:34:27 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

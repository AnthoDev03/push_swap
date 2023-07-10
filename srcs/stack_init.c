/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anthrodr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:35:02 by anthrodr          #+#    #+#             */
/*   Updated: 2023/07/10 14:35:04 by anthrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

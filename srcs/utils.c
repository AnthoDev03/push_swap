#include "../includes/push_swap.h"

void	push(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->next = stack->head;
	stack->head = new_node;
}

int	pop(t_stack *stack)
{
	int		data;
	t_node	*temp;

	if (stack->head == NULL)
		return (0);
	temp = stack->head;
	data = temp->data;
	stack->head = stack->head->next;
	free(temp);
	return (data);
}

int	ft_lstsize2(t_stack *stack)
{
	int		count;
	t_node	*current;

	current = stack->head;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

bool	issorted(t_stack *stack_a)
{
	t_node	*current;

	current = stack_a->head;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
		{
			return (false);
		}
		current = current->next;
	}
	return (true);
}
void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack->head;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(stack);
}

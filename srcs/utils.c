#include "../includes/push_swap.h"

void	push(Stack *stack, int data)
{
	Node	*new_node;

	new_node = (Node *)malloc(sizeof(Node));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->next = stack->head;
	stack->head = new_node;
}

int	pop(Stack *stack)
{
	int		data;
	Node	*temp;

	if (stack->head == NULL)
		return (0);
	temp = stack->head;
	data = temp->data;
	stack->head = stack->head->next;
	free(temp);
	return (data);
}

int	ft_lstsize2(Stack *stack)
{
	int		count;
	Node	*current;

	current = stack->head;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

bool	issorted(Stack *stack_a)
{
	Node	*current;

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

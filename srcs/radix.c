#include "../includes/push_swap.h"

int get_max_bits(Stack *stack)
{
    Node *head = stack->head;
    int max = 0;
    int max_bits = 0;

    while (head)
    {
        if (head->data > max)
            max = head->data;
        head = head->next;
    }

    while ((max >> max_bits) != 0)
        max_bits++;

    return max_bits;
}
void radix_sort(Stack *stack_a, Stack *stack_b)
{
	Node	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = stack_a->head;
	size = ft_lstsize2(stack_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = stack_a->head;
			if (((head_a->data >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize2(stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}

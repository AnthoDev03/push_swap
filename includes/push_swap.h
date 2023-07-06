#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct Node
{
	int			data;
	int			index;
	struct Node	*next;
}				Node;

typedef struct Stack
{
	Node		*head;
}				Stack;

void			push(Stack *stack, int data);
int				pop(Stack *stack);
int				ft_lstsize2(Stack *stack);
void			pa(Stack *stack_a, Stack *stack_b);
void			pb(Stack *stack_a, Stack *stack_b);
int				get_max_bits(Stack *stack);
void			radix_sort(Stack *stack_a, Stack *stack_b);
void			rotate(Stack *stack);
void			ra(Stack *stack_a);
void			rb(Stack *stack_b);
void			rr(Stack *stack_a, Stack *stack_b);
bool			issorted(Stack *stack_a);
void			reverse_rotate(Stack *stack);
void			rra(Stack *stack_a);
void			rrb(Stack *stack_b);
void			rrr(Stack *stack_a, Stack *stack_b);

void			swap_first_two(Stack *stack);
void			sa(Stack *stack);
void			sb(Stack *stack);
void			ss(Stack *stack_A, Stack *stack_B);
Stack			*stack_init(void);
int				test(int argc, char **argv);
int				*transform(int argc, char **argv);
void			fill_data_array(int argc, char **argv, int *data);
void			calculate_new_data_array(int *data, int *data2, int size);
void			push_two_smallest(Stack *stack_a, Stack *stack_b);
void			find_two_smallest(Stack *stack_a, int *smallest1,
					int *smallest2);
void			perform_pushes(Stack *stack_a, Stack *stack_b, int smallest1,
					int smallest2);

#endif

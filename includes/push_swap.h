#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *head;
} Stack;

void push(Stack *stack, int value);
int pop(Stack *stack);
void pa(Stack *stack_a, Stack *stack_b);
void pb(Stack *stack_a, Stack *stack_b);
void ra(Stack *stack);
void rb(Stack *stack);
void rr(Stack *stack_a, Stack *stack_b);
void rra(Stack *stack);
void rrb(Stack *stack);
void rrr(Stack *stack_a, Stack *stack_b);
void swap_first_two(Stack *stack);
void sa(Stack *stackA);
void sb(Stack *stackB);
void ss(Stack *stackA, Stack *stackB);

#endif

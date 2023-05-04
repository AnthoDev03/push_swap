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

void push(Stack *stack, int data);
int pop(Stack *stack);

void pa(Stack *stack_a, Stack *stack_b);
void pb(Stack *stack_a, Stack *stack_b);

void rotate(Stack *stack);
void ra(Stack *stack_a);
void rb(Stack *stack_b);
void rr(Stack *stack_a, Stack *stack_b);

void reverse_rotate(Stack *stack);
void rra(Stack *stack_a);
void rrb(Stack *stack_b);
void rrr(Stack *stack_a, Stack *stack_b);

void swap_first_two(Stack *stack);
void sa(Stack *stack);
void sb(Stack *stack);
void ss(Stack *stack_A, Stack *stack_B);
Stack *stack_init();

#endif

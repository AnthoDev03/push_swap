#include "../includes/push_swap.h"

void rotate(Stack *stack) {
    if (stack == NULL || stack->head == NULL || stack->head->next == NULL)
        return;
    
    
    Node *first = stack->head;
    Node *second = first->next;

    stack->head = second;
    Node *temp = second;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = first;
    first->next = NULL;
}

void ra(Stack *stack_a) {
    rotate(stack_a);
    write(1, "ra\n", 3);
}

void rb(Stack *stack_b) {
    rotate(stack_b);
    write(1, "rb\n", 3);
}

void rr(Stack *stack_a, Stack *stack_b) {
    ra(stack_a);
    rb(stack_b);
    write(1, "rr\n", 2);
}


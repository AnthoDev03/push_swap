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
}

void rb(Stack *stack_b) {
    rotate(stack_b);
}

void rr(Stack *stack_a, Stack *stack_b) {
    ra(stack_a);
    rb(stack_b);
}


#include "../includes/push_swap.h"

void sa(Stack *stack) {
    if (stack->head != NULL && stack->head->next != NULL) {
        Node *first = stack->head;
        Node *second = stack->head->next;

        first->next = second->next;
        second->next = first;
        stack->head = second;
    }
}


void sb(Stack *stack) {
    sa(stack);
}

void ss(Stack *stack_a, Stack *stack_b) {
    sa(stack_a);
    sb(stack_b);
}

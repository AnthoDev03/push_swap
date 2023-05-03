#include "../includes/push_swap.h"

void rra(Stack *stack) {
    if (stack->head != NULL && stack->head->next != NULL) {
        Node *current = stack->head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        Node *last = current->next;
        current->next = NULL;
        last->next = stack->head;
        stack->head = last;
    }
}

void rrb(Stack *stack) {
    rra(stack);
}

void rrr(Stack *stack_a, Stack *stack_b) {
    rra(stack_a);
    rra(stack_b);
}


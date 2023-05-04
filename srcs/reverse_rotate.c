#include "../includes/push_swap.h"

void reverse_rotate(Stack *stack) {
    if (stack == NULL || stack->head == NULL || stack->head->next == NULL) {
        return;
    }
    
    Node *last = NULL;
    Node *prev = NULL;
    Node *temp = stack->head;
    
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    last = temp;
    prev->next = NULL;
    last->next = stack->head;
    stack->head = last;
}

void rra(Stack *stack_a) {
    reverse_rotate(stack_a);
}

void rrb(Stack *stack_b) {
    reverse_rotate(stack_b);
}

void rrr(Stack *stack_a, Stack *stack_b) {
    rra(stack_a);
    rrb(stack_b);
}

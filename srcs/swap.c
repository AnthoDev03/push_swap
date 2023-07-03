#include "../includes/push_swap.h"

void swap_first_two(Stack *stack) {
    if (stack->head != NULL && stack->head->next != NULL) {
        Node *first = stack->head;
        Node *second = stack->head->next;

        first->next = second->next;
        second->next = first;
        stack->head = second;
    }
}


void sb(Stack *stack) {
    swap_first_two(stack);
    write(1, "sb\n", 3);
}

void sa(Stack *stack){
    swap_first_two(stack);
    write(1, "sa\n", 3);
}

void ss(Stack *stack_a, Stack *stack_b) {
    sa(stack_a);
    sb(stack_b);
    write(1, "ss\n", 3);
}

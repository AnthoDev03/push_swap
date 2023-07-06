#include "../includes/push_swap.h"

void swap_first_two(Stack *stack) {
    if (stack->head != NULL && stack->head->next != NULL) {
        Node *first;
        Node *second;
       
        first = stack->head;
        second = stack->head->next;

        first->next = second->next;
        second->next = first;
        stack->head = second;
    }
}


void sb(Stack *stack_b) {
    swap_first_two(stack_b);
    write(1, "sb\n", 3);
}

void sa(Stack *stack_a){
    swap_first_two(stack_a);
    write(1, "sa\n", 3);
}

void ss(Stack *stack_a, Stack *stack_b) {
    swap_first_two(stack_a);
    swap_first_two(stack_b);
    write(1, "ss\n", 3);
}

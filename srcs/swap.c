#include "../includes/push_swap.h"

void swap_first_two(Stack *stack) {
    if (stack->head != NULL && stack->head->next != NULL) {
        int temp = stack->head->value;
        stack->head->value = stack->head->next->value;
        stack->head->next->value = temp;
    }
}

void sa(Stack *stackA) {
    swap_first_two(stackA);
}

void sb(Stack *stackB) {
    swap_first_two(stackB);
}

void ss(Stack *stackA, Stack *stackB) {
    sa(stackA);
    sb(stackB);
}

#include "../includes/push_swap.h"

void pa(Stack *stack_a, Stack *stack_b) {
    if (stack_b->head != NULL) {
        push(stack_a, pop(stack_b));
    }
}

void pb(Stack *stack_a, Stack *stack_b) {
    if (stack_a->head != NULL) {
        push(stack_b, pop(stack_a));
    }
}

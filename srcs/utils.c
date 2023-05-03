#include "../includes/push_swap.h"

void push(Stack *stack, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = stack->head;
    stack->head = new_node;
}

int pop(Stack *stack) {
    if (stack->head == NULL) {
        return -1;
    }

    int value = stack->head->value;
    Node *temp = stack->head;
    stack->head = stack->head->next;
    free(temp);
    return value;
}

Stack *create_stack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

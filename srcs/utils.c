#include "../includes/push_swap.h"

void push(Stack *stack, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
        return;

    new_node->data = data;
    new_node->next = stack->head;
    stack->head = new_node;
}

int pop(Stack *stack)
{
    if (stack->head == NULL)
        return (0);

    Node *temp = stack->head;
    int data = temp->data;
    stack->head = stack->head->next;
    free(temp);

    return data;
}



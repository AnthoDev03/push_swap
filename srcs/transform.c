#include "../includes/push_swap.h"

void performPushes(Stack *stack_a, Stack *stack_b, int smallest1, int smallest2)
{
    int count = 0;
    Node *current = stack_a->head;

    while (current != NULL && count < 2)
    {
        Node *nextNode = current->next;
        if (current->data == smallest1 || current->data == smallest2)
        {
            pb(stack_a, stack_b);
            count++;
        }
        else
        {
            ra(stack_a);
        }
        current = nextNode;
    }
}
void findTwoSmallest(Stack *stack_a, int *smallest1, int *smallest2)
{
    *smallest1 = INT_MAX;
    *smallest2 = INT_MAX;
    Node *current = stack_a->head;

    while (current != NULL)
    {
        int data = current->data;
        if (data < *smallest1)
        {
            *smallest2 = *smallest1;
            *smallest1 = data;
        }
        else if (data < *smallest2 && data != *smallest1)
        {
            *smallest2 = data;
        }
        current = current->next;
    }
}
void pushTwoSmallest(Stack *stack_a, Stack *stack_b)
{
    int smallest1;
    int smallest2;

    findTwoSmallest(stack_a, &smallest1, &smallest2);
    performPushes(stack_a, stack_b, smallest1, smallest2);
}

void calculateNewDataArray(int *data, int *data2, int size)
{
    int idx2 = 0;

    while (idx2 < size)
    {
        int idx = 0;
        int newdata = 0;

        while (idx < size)
        {
            if (data[idx2] > data[idx])
                newdata++;
            idx++;
        }

        data2[idx2] = newdata;
        idx2++;
    }
}

void fillDataArray(int argc, char **argv, int *data)
{
    int idx = 1;

    while (idx < argc)
    {
        data[idx - 1] = ft_atoi(argv[idx]);
        idx++;
    }
}

#include "../includes/push_swap.h"

Stack *stack_init() {
    Stack *stack;

    stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL)
        return (NULL);

    stack->head = NULL;

    return stack;
}

void    stack_a_init(int *data, Stack *stack_a, int argc)
{
    int     i;
    i = argc -2;
    while (i >= 0)
    {
        push(stack_a, data[i]);
        i--;
    }
}
void sort_3_elements(Stack *stack_a) {

    int first;
    int second;
    int third;

    first = stack_a->head->data;
    second = stack_a->head->next->data;
    third = stack_a->head->next->next->data;
    if (first > second && second < third && first < third) {
        sa(stack_a);
    }
    else if (first > second && third < second && first > third) {
        sa(stack_a);
        rra(stack_a);
    }
    else if (second < first && first > third && second < third) {
        ra(stack_a);
    }
    else if (second > third && third > first && second > first) {
        sa(stack_a);
        ra(stack_a);
    }
    else if (third < first && first < second && second > third) {
        rra(stack_a);
    }
}

void sort_5_elements(Stack *stack_a, Stack *stack_b) {

    pushTwoSmallest(stack_a, stack_b);
    sort_3_elements(stack_a);
    if (stack_b->head->data < stack_b->head->next->data)
        sb(stack_b);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}

int main(int argc, char **argv) {
    Stack *stack_a;
    Stack *stack_b;

    stack_a = stack_init();
    stack_b = stack_init();

    if (test(argc, argv) == 0)
    {
        ft_printf("ERROR\n");
        exit(EXIT_FAILURE);
    }
    stack_a_init(transform(argc, argv), stack_a, argc);
    if (issorted(stack_a) == true) {
        exit(EXIT_SUCCESS);
    }
    if (argc == 4)
        sort_3_elements(stack_a);
    if (argc == 6)
        sort_5_elements(stack_a, stack_b);
    else if (argc > 6) {
        radix_sort(stack_a, stack_b);
    }
     return (0);
}

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    Node *stack_a;
    Node *stack_b;
    int     i;
    int     num;

    stack_a = NULL;
    stack_b = NULL;
    i = 1;
    while(i < argc)
    {
        num = ft_atoi(argv[i]);
        push(&stack_a, num);
    }

}

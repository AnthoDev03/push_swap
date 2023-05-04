#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void print_stack(Stack *stack) {
    if (stack == NULL) {
        printf("La pile est NULL.\n");
        return;
    }

    Node *current = stack->head;
    printf("Contenu de la pile : ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

Stack *stack_init() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (stack == NULL)
        return (NULL);

    stack->head = NULL;

    return stack;
}

void    stack_a_init(int argc, char **argv, Stack *stack_a)
{
    int     i;
    int     data;

    i = 1;
    while (i < argc)
    {
        data = ft_atoi(argv[i]);
        push(stack_a, data);
        i++;
    }
}

int     test(int argc, char **argv)
{
    int     i;
    int     j;

    i = 1;
    j = 0;

    while (i < argc)
    {  
        while(argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}


int main(int argc, char **argv) {
    Stack *stack_a;
    Stack *stack_b;

    stack_a = stack_init();
    stack_b = stack_init();

    if (test(argc, argv) == 1)
    {
        printf("ERROR FDP");
        exit(EXIT_FAILURE);
    }

    stack_a_init(argc, argv, stack_a);
    print_stack(stack_a);
    print_stack(stack_b);

    pa(stack_a, stack_b);
    print_stack(stack_a);
    print_stack(stack_b);




    return 0;
}


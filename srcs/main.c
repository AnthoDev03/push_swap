#include "../includes/push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

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
    Stack *stack;

    stack = (Stack *) malloc(sizeof(Stack));
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

bool is_integer(const char *str) {
    if (*str == '-' || *str == '+') {
        str++;
    }
    while (*str) {
        if (*str < '0' || *str > '9') {
            return (false);
        }
        str++;
    }
    return (true);
}

bool has_duplicates(int argc, char **argv) {
    int i;
    int j;
    int max_length;

    i = 1;
    while (i < argc) {
        j = i + 1;
        while (j < argc) {
            if (ft_strlen(argv[i]) > ft_strlen(argv[j])) {
                max_length = ft_strlen(argv[i]);
            } else {
                max_length = ft_strlen(argv[j]);
            }

            if (ft_strncmp(argv[i], argv[j], max_length) == 0) {
                return true;
            }
            j++;
        }
        i++;
    }
    return false;
}

long long str_to_ll(const char *str) {
    long long number;
    int sign;

    number = 0;
    sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    while (*str) {
        number = number * 10 + (*str - '0');
        str++;
    }

    return number * sign;
}

int test(int argc, char **argv) {
    if (has_duplicates(argc, argv)) {
        return 0;
    }

    int     i; 

    i = 1;
    while (i < argc) {
        if (!is_integer(argv[i])) {
            return 0;
        }

        long long   number;

        number = str_to_ll(argv[i]);

        if (number > INT_MAX || number < INT_MIN) {
            return 0;
        }
        i++;
    }
    return 1;
}


int main(int argc, char **argv) {
    Stack *stack_a;
    Stack *stack_b;

    stack_a = stack_init();
    stack_b = stack_init();

    if (test(argc, argv) == 0)
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


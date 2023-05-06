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

    i = argc - 1;
    while (i > 0)
    {
        data = ft_atoi(argv[i]);
        push(stack_a, data);
        i--;
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

void sort_3_elements(Stack *stack_a) {

    int first = stack_a->head->data;
    int second = stack_a->head->next->data;
    int third = stack_a->head->next->next->data;

    // Cas 1: première permutation (2 1 3)
    if (first > second && second < third && first < third) {
        sa(stack_a);
    }
    // Cas 2: deuxième permutation (3 2 1)
    else if (first > second && third < second && first > third) {
        sa(stack_a);
        rra(stack_a);
    }
    // Cas 3: troisième permutation (3 1 2)
    else if (second < first && first > third && second < third) {
        ra(stack_a);
    }
    // Cas 4: quatrième permutation (1 3 2)
    else if (second > third && third > first && second > first) {
        sa(stack_a);
        ra(stack_a);
    }
    // Cas 5: cinquième permutation (2 3 1)
    else if (third < first && first < second && second > third) {
        rra(stack_a);
    }
}

void find_two_smallest(Stack *stack_a, int *min_idx, int *second_min_idx) {

    Node *current = stack_a->head;
    int min = current->data;
    int second_min = INT_MAX;
    *min_idx = 0;
    *second_min_idx = -1;
    int idx = 0;

    while (current != NULL) {
        if (current->data < min) {
            second_min = min;
            *second_min_idx = *min_idx;
            min = current->data;
            *min_idx = idx;
        } else if (current->data < second_min && current->data != min) {
            second_min = current->data;
            *second_min_idx = idx;
        }
        current = current->next;
        idx++;
    }
}

void push_two_smallest_to_stack_b(Stack *stack_a, Stack *stack_b) {

    int min_idx, second_min_idx;
    find_two_smallest(stack_a, &min_idx, &second_min_idx);

    for (int i = 0; i < 2; i++) {
        int target_idx = (i == 0) ? min_idx : second_min_idx;
        int counter = target_idx;

        // Rotate stack_a until the smallest element is at the top
        while (counter > 0) {
            ra(stack_a);
            counter--;
        }

        // Push the smallest element to stack_b
        pb(stack_a, stack_b);

        // Update the index of the second smallest element
        if (i == 0 && second_min_idx > min_idx) {
            second_min_idx--;
        }
    }
}


void sort_5_elements(Stack *stack_a, Stack *stack_b) {

    push_two_smallest_to_stack_b(stack_a, stack_b);
    sort_3_elements(stack_a);
    if (stack_b->head->data > stack_b->head->next->data)
        sb(stack_b);

    pa(stack_b, stack_a);
    pa(stack_b, stack_a);
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

    if (argc == 4)
        sort_3_elements(stack_a);
    if (argc == 6)
        sort_5_elements(stack_a, stack_b);

    print_stack(stack_a);
    print_stack(stack_b);

    return 0;
}

#include "../includes/push_swap.h"

void print_stack(Stack *stack) {
    if (stack == NULL) {
        ft_printf("La pile est NULL.\n");
        return;
    }

    Node *current = stack->head;
    ft_printf("Contenu de la pile : ");
    while (current != NULL) {
        ft_printf("%d ", current->data);
        current = current->next;
    }
    ft_printf("\n");
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
void pushTwoSmallest(Stack *stack_a, Stack *stack_b) {

    int smallest1 = INT_MAX;  
    int smallest2 = INT_MAX; 

    Node *current = stack_a->head;
    while (current != NULL) {
        int data = current->data;
        if (data < smallest1) {
            smallest2 = smallest1;
            smallest1 = data;
        } else if (data < smallest2 && data != smallest1) {
            smallest2 = data;
        }
        current = current->next;
    }

    int count = 0;
    current = stack_a->head;
    while (current != NULL && count < 2) {
        Node *nextNode = current->next;
        if (current->data == smallest1 || current->data == smallest2) {
            pb(stack_a, stack_b);
            count++;
        } else {
            ra(stack_a);
        }
        current = nextNode;
    }
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
        ft_printf("ERROR FDP");
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

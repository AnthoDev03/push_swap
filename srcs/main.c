#include "../includes/push_swap.h"
#include <stdlib.h>

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
int* decimalToBinary(int* decimalArray, int size) {
    int* binaryArray = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        int decimalNum = decimalArray[i];
        int binaryNum = 0;
        int base = 1;

        while (decimalNum > 0) {
            int remainder = decimalNum % 2;
            binaryNum += remainder * base;
            decimalNum /= 2;
            base *= 10;
        }

        binaryArray[i] = binaryNum;
    }

    return binaryArray;
}
bool issorted(Stack *stack_a)
{
     Node *current = stack_a->head;
    int data;
    int data2;
    data = current->data;
    data2 = current->next->data;
    while (current != NULL) {
        if (data < data2) {
            return false;
        }
        data = current->data;
        data2 = current->next->data;
        current = current->next;
    }
    return true;
}

int *transform(int argc, char **argv)
{
    int idx;
    int *data;
    int *data2;

    idx = 1;
    data = (int *)malloc(sizeof(int) * (argc - 1));
    if (!data)
        return NULL;
    data2 = (int *)malloc(sizeof(int) * (argc - 1));
    if (!data2)
        return NULL;


    while (idx < (argc))
    {
        data[idx - 1] = ft_atoi(argv[idx]);
        idx++;
    }
    int idx2 = 0;
    int newdata =0;
    int number = 0;
    idx = 0;
    while (idx2 < argc) {
        while (idx < argc - 1) {
            if (data[number] > data[idx]) {
                newdata++;
            }
            idx++;
        }
        data2[number] = newdata;
        newdata = 0;
        number++;
        idx2++;
        idx= 0;

    }

    return (decimalToBinary(data2, argc -1));
}


void sort_3_elements(Stack *stack_a) {

    int first = stack_a->head->data;
    int second = stack_a->head->next->data;
    int third = stack_a->head->next->next->data;

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
        ft_printf("ERROR");
        exit(EXIT_FAILURE);
    }
    stack_a_init(transform(argc, argv), stack_a, argc);
    if (issorted(stack_a) == true) {
        exit(EXIT_SUCCESS);
    }
 //   print_stack(stack_a);
    if (argc == 4)
        sort_3_elements(stack_a);
    if (argc == 6)
        sort_5_elements(stack_a, stack_b);
 //print_stack(stack_a);
     return 0;
}

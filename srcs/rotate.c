#include "../includes/push_swap.h"

// Function to perform 'ra' operation (rotate A)
void ra(int *stack, int top) {
    if (top > 0) {
        int temp = stack[0];
        for (int i = 0; i < top; i++) {
            stack[i] = stack[i + 1];
        }
        stack[top] = temp;
    }
}

// Function to perform 'rb' operation (rotate B)
void rb(int *stack, int top) {
    ra(stack, top);
}

// Function to perform 'rr' operation (rotate A and B)
void rr(int *stackA, int topA, int *stackB, int topB) {
    ra(stackA, topA);
    rb(stackB, topB);
}


#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct Stack {
    int* elements;
    int size; // current number of elements
    int capacity; // max number of elements
} Stack;

Stack* new_stack(int); //θ(1)
void destroy_stack(Stack*); //θ(1)
void push(Stack*, int); //θ(1)
int pop(Stack*); //θ(1)
int top(Stack*); //θ(1)
int length(Stack*); //θ(1)
bool is_empty(Stack*); //θ(1)
bool is_full(Stack*); //θ(1)
void clear(Stack*); //θ(1)
void print_stack(Stack*); //θ(N)

#endif

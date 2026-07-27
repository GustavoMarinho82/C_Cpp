#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

Stack* new_stack(int capacity) {
	// Creates a stack with the specified capacity and returns a pointer to it [θ(1)]
	if (capacity <= 0)
		return NULL;

	Stack* S = malloc(sizeof(Stack));
	S->size = 0;
	S->capacity = capacity;
	S->elements = malloc(sizeof(int) * capacity);
	
	return S;
}

void destroy_stack(Stack* S) {
	// Destroys the stack and frees its memory [θ(1)]
	free(S->elements);
	free(S);
}

void push(Stack* S, int value) {
	// Inserts a element into the stack [θ(1)]
	if (S->size == S->capacity) {
		fprintf(stderr, "Stack overflow!\n");
		exit(EXIT_FAILURE);
	}
	
	S->elements[(S->size)++] = value;
}

int pop(Stack* S) {
	// Removes and returns the top element from the stack [θ(1)]
	if (S->size == 0) {
		fprintf(stderr, "Stack underflow!\n");
		exit(EXIT_FAILURE);
	}
	
	return S->elements[--(S->size)];
}

int top(Stack *S) {
	// Returns the top element from the stack [θ(1)]
	if (S->size == 0) {
		fprintf(stderr, "Trying to acess the top of an empty stack!\n");
		exit(EXIT_FAILURE);
	}
	
	return S->elements[S->size - 1];
}

int length(Stack* S) {
	// Returns the current number of elements in the stack [θ(1)]
	return S->size;
}

int max_length(Stack* S) {
	// Returns the capacity (maximum number of elements) of the stack [θ(1)]
	return S->capacity;
}

bool is_empty(Stack* S) {
	// Returns true if the stack is empty, false otherwise [θ(1)]
	return (S->size == 0);
}

bool is_full(Stack* S) {
	// Returns true if the stack is full, false otherwise [θ(1)]
	return (S->size == S->capacity);
}

void clear(Stack* S) {
	// Clears the stack by setting its size to 0 [θ(1)]
	S->size = 0;
}

void print_stack(Stack* S) {
	// Prints each element from top to the bottom of the stack [θ(N)]
	for (int i = S->size - 1; i >= 0; i--)
		printf("|%d| ", S->elements[i]);
		
	printf("\n");
}

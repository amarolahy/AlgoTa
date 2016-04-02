/*******************************************************
*   ---------------- clist.c -------------------       *
********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int stack_push(Stack *stack, const void *data) {
	// Push the data onto the stack.
	return list_ins_next(stack, NULL, data);
}

int stack_pop(Stack *stack, void **data) {
	// Pop the data off the stack.
	return list_rem_next(stack, NULL, data);
}
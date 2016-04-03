/*******************************************************
*   ---------------- stack.h -------------------       *
********************************************************/
#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#include "list.h"

// Implement stack as a linked list.
typedef List Stack;

/*******************************************************
*   ------------- Public Interface ------------------- *
********************************************************/

/**
 * void stack_init(Stack *stack, void (*destroy)(void *data));
 * Initializes the stack specified by stack. This operation must be 
 * called for a stack before the stack can be used with any other operation.
 * The destroy argument provides a way to free dynamically allocated data when
 * stack_destroy is called. For example, if the ctack dontains data dynamically allocated
 * using malloc, destroy should be set to free() to free the data as the stack is
 * destroyed. For structured data containing several dynamiclly allocated members, 
 * destroy should set to a user-defined function that calls free for each dynamically
 * allocated member as well as for the structure itself. For a stack containing
 * data that should not be freed, destroy should be set to NULL.
 * @complexity O(1) 
 */
#define stack_init list_init


/**
 *  void stack_destroy(Stack *stack);
 *  Destroys the stack specified by stack. No other operations are
 *  permitted after calling stack_destroy unless stack_init is called again. The stack_destroy
 *  operation removess all elements from a stack and calls the function passed
 *  as destroy to stack_init once for each element as it is removed, provided
 *  destroy was not set to NULL.
 *  @complexity O(n), where n is the number of elements in the stack.
 * 
 */
#define stack_destroy list_destroy

/**
 * Pushes an element onto the stack specified by stack. The new 
 * element contains a pointer to data, so the memory referenced by data should 
 * remain valid as long as the element remains in the stack. It is the responsibility of 
 * the caller to manage the storage associated with data
 * @param  stack The stack on which the element will be added
 * @param  data  Data to add to the stack
 * @return       0 if pushing the element is successful, or -1 otherwise.
 * @complexity O(1)
 */
int stack_push(Stack *stack, const void *data);

/**
 * Pops an element off the stack specified by stack. Upon return, data points to the 
 * data stored in the element that was popped. It is the responsibility of the caller
 * to manage the storage associated with the data.
 * @param  stack 
 * @param  data  
 * @return       0 if popping the element is successful, or -1 otherwise.
 * @complexity O(1)
 */
int stack_pop(Stack *stack, void **data);

/**
 * void *stack_peed(const Stack *stack);
 * Macro that evaluates to the data stored in the element at the top of the stack
 * specified by stack
 * @return      Data stored in the element at the top of the stack, or NULL if 
 * the stack is empty
 * @complexity O(1)
 */
#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)


/**
 * int stack_size(const Stack *stack);
 * Macro that evaluates to the number of elements in the stack specified by stack
 * @param stack
 * @return Number of elements in the stack.
 * @complexity O(1)
 */
#define stack_size list_size

#endif

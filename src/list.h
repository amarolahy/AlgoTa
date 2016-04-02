/*******************************************************
*   ---------------- list.h -------------------        *
********************************************************/

// Implementation of linked list.

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/*******************************************************
*   Define a structure for linked list elements        *
********************************************************/
typedef struct ListElmt_ {
    void              *data;
    struct ListElmt_  *next ;

} ListElmt;

/*******************************************************
*   Define a structure for linked lists                *
********************************************************/

typedef struct List_{
    int         size;

    int         (*match)(const void *key1, const void *key2);
    void        (*destroy)(void *data);

    ListElmt    *head;
    ListElmt    *tail;

} List;

/*******************************************************
*   ------------- Public Interface ------------------- *
********************************************************/
// Return value : None 
//
// Descritption : Initializes the linked list specified by list. This operation must 
// be called for a linked list before the list can be used with any other operation.
// The destroy argument provides a way to free dynamically allocated data when 
// list_destroy is called. For example, if the list contains data dynamically allocated
// using malloc, destroy should be set to free to free the data as linked list is 
// destroyed. For structured data containing several dynamically allocated members, 
// cally allocated member as well as for the structure itself. For a linked list containing
// data that should not be freed, destroy should be set to NULL.
//
// Complexity : O(1).
void list_init(List *list, void (*destroy)(void *data));

// Return value : None
//
// Descritption : Destroys the linked list specified by list. No other operations
// are permitted after calling list_destroy unless list_init is called again. The
// list_destroy operation removes all elements from a linked list and calls the function
// passed as destroy to list_init once for each element as it is removed, provided
// destroy was not set to NULL.
//
// Complexity : O(n), where n is the number of the elements in the linked list.
void list_destroy(List *list);

// Return value : 0 if inserting the element is successful, or -1 otherwise
//
// Descritption : Inserts an element just after element in the linked list specified 
// by list. If element is NULL, th enew element is inserted at the head of the list.
// Yhe new element contains a pointer to data, so the memory referenced by data
// should remain valid as long as the element remians in the list. It is the responsibility
// of the caller to manage the storage associated with data.
//
// Complexity : 0(1)
int list_ins_next(List *list, ListElmt *element, const void *data);

// Return value : 0 if removing the element is successful, or -1 otherwise. 
//
// Descritption : Removes the element just after element from th e linked list specified
// by list. If th element is NULL, the element at the head of the list is removed. 
// Upon return, data points to the data stored in the element that was removed. It is
// the responsibility of the caller to manage the storage associated with the data.
//
// Complexity : O(1)
int list_rem_next(List *list, ListElmt *element, void **data);

//return the Number of elements in the list
#define list_size(list) ((list)->size)

//return Element at the head of the list
//ListElmt *list_head(const List *list);
#define list_head(list)  ((list)->head)

//return Element at the tail of the list
//ListElmt *list_tail(const List *list);
#define list_tail(list)  ((list)->tail)

//return 1 if the element is at the head of the list, or 0 otherwise.
//int list_is_head(const ListElmt *element);
#define list_is_head(list, element)  ((element) == (list)->head ? 1 : 0)

//return 1 if the element is at the tail of the list, 0 ohterwise.
//int list_is_tail(const ListElmt *element);
#define list_is_tail(element)  ((element)-> == NULL ? 1 : 0)

//return the Data stored in the element
//void *list_data(const ListElmt *element);
#define list_data(element)  ((element)->data)

//return Element following the specified element
//ListElmt *list_next(const ListElmt *element);
#define list_next(element)  ((element)->next)


#endif // LINKEDLIST_H_INCLUDED

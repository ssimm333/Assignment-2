/*****************************************************************//**
 * @file   doubleLinkedList.c
 * @brief  Implementation of double linked list operations
 *
 * @author Stanislav Simanovich
 * @author Calum Breen
 * @author Emilia Hildebrandt
 * @author Tiernan O'Shaughnessy
 * @author Jordi Roca
 * @author Bengisu Fansa

 * @date   11 November 2024
 *********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "functionDeclarations.h"
#include "structures.h"
#include "enum.h"

/**
 * @brief Creates a new double linked list.
 * 
 * @details Allocates memory for the list and its head 
 *          and tail nodes, and initializes their pointers.
 * 
 * @return A pointer to the newly created double-linked list, or NULL if memory allocation fails.
 */
dllist* createList() {
	// allocate memory for the list
	dllist* list = (dllist*)malloc(sizeof(dllist));

	// test for allocation error
	if (list == NULL) {
		return NULL;
	}

	// allocate memory for head node
	list->head = (dllNode*)malloc(sizeof(dllNode));

	// test for allocation error
	if (list->head == NULL) {
		free(list);
		return NULL;
	}

	list->tail = (dllNode*)malloc(sizeof(dllNode));

	// test for allocation error
	if (list->tail == NULL) {
		free(list->head);
		free(list);
		return NULL;
	}

	// set pointers
	list->head->next = list->tail;
	list->head->prev = NULL;
	list->tail->next = NULL;
	list->tail->prev = list->head;
	list->current = list->head;
}


/**
 * @brief Deletes a double-linked list.
 *
 * @details Frees the memory allocated for the list and its nodes.
 *
 * @param list The double linked list to be deleted.
 */
void deleteList(dllist* list) {
	if (list == NULL) {
		return;
	}

	dllNode* current = list->head;
	while (current != NULL) {
		dllNode* next = current->next;
		free(current);
		current = next;
	}
	free(list);
}

/**
 * @brief Retrieves the data at the current node in the list.
 *
 * @details Returns a pointer to the data at the current node.
 *
 * @param list The double-linked list.
 * 
 * @return A pointer to the data at the current node, or NULL if the list is empty.
 */
data* getData(dllist* list) {
	// ensure valid linked list exists
	if (list == NULL) {
		return NULL;
	}
	// return data at current node
	else {
		return &list->current->d;
	}
}

/**
 * @brief Moves to the next node in the list. 
 *
 * @details Updates the current node pointer to point to 
 *          the next node in the list.
 *
 * @param list The double-linked list.
 */
void gotoNextNode(dllist* list) {
	// ensure valid linked list exists
	if (list == NULL) {
		return;
	}
	else {
		list->current = list->current->next;
	}
}

/**
 * @brief Moves to the previous node in the list.
 *
 * @details Updates the current node pointer to point to 
 *          the previous node in the list.
 *
 * @param list The double-linked list.
 */
void gotoPrevNode(dllist* list) {
	// ensure valid linked list exists
	if (list == NULL) {
		return;
	}
	else {
		list->current = list->current->prev;
	}
}

/**
 * @brief Moves to the head of the list.
 *
 * @details Updates the current node pointer to point to 
 *          the head of the list.
 *
 * @param list The double-linked list.
 */
void gotoHead(dllist* list) {
	// ensure valid linked list exists
	if (list == NULL) {
		return;
	}
	else {
		list->current = list->head;
	}
}

/**
 * @brief Moves to the tail of the list.
 *
 * @details Updates the current node pointer to point to 
 *          the tail of the list.
 *
 * @param list The double-linked list.
 */
void gotoTail(dllist* list) {
	// ensure valid linked list exists
	if (list == NULL) {
		return;
	}
	else {
		list->current = list->tail;
	}
}

/**
 * @brief Inserts data after the current node in the list.
 *
 * @details Allocates a new node, inserts it after 
 *          the current node, and updates the list's pointers.
 *
 * @param1 list The double-linked list.
 * 
 * @param2 newdata The data to be inserted.
 * 
 * @return An allocation error if given an invalid list/node. 
 */
enum ReturnValue insertAfter(dllist* list, data newdata) {
	dllNode* newNode = (dllNode*)malloc(sizeof(dllNode));
	// ensure valid linked list exists
	if (list == NULL) {
		return AllocationError;
	}

	if (newNode == NULL) {
		return AllocationError;
	}

	newNode->d = newdata;

	// insert it into the list
	newNode->next = list->current->next;
	newNode->prev = list->current;
	list->current->next = newNode;
	list->current->next->prev = newNode;
}

/**
 * @brief Inserts data before the current node in the list.
 *
 * @details Allocates a new node, inserts it before
 *          the current node, and updates the list's pointers.
 *
 * @param1 list The double-linked list.
 *
 * @param2 newdata The data to be inserted.
 *
 * @return An allocation error if given an invalid list/node.
 */
enum ReturnValue insertBefore(dllist* list, data newdata) {
	dllNode* newNode = (dllNode*)malloc(sizeof(dllNode));
	// ensure valid list exists
	if (list == NULL) {
		return AllocationError;
	}

	if (newNode == NULL) {
		return AllocationError;
	}

	newNode->d = newdata;

	// insert it into the list
	newNode->next = list->current;
	newNode->prev = list->current->prev;
	list->current->prev = newNode;
	list->current->prev->next = newNode;
}

/**
 * @brief Deletes the current node from the list.
 *
 * @details Removes the current node from the list and 
 *          updates the list's pointers.If the current node 
 *          is the head or tail of the list, the list's head 
 *          or tail is updated accordingly.
 *
 * @param list The double-linked list.
 * 
 * @return An allocation error if given an invalid list
 */
enum ReturnValue deleteCurrent(dllist* list) {
	// ensure valid list exists
	if (list == NULL) {
		return AllocationError;
	}
	else {
		list->current->prev = list->current->next->prev;
		list->current->next->prev = list->current->prev;
		list->current->next = list->current->prev->next;
		list->current->prev->next = list->current->next;
	}
}

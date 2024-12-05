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

 // create a list
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

// delete a list
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
// get data at current node
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

// go to the next node
void gotoNextNode(dllist* list) {
	// ensure valid linked list exists
	if (list == NULL) {
		return;
	}
	else {
		list->current = list->current->next;
	}
}

// go to the previous node
void gotoPrevNode(dllist* list) {
	// ensure valid linked list exists
	if (list == NULL) {
		return;
	}
	else {
		list->current = list->current->prev;
	}
}

// go to head
void gotoHead(dllist* list) {
	// ensure valid linked list exists
	if (list == NULL) {
		return;
	}
	else {
		list->current = list->head;
	}
}

// go to tail
void gotoTail(dllist* list) {
	// ensure valid linked list exists
	if (list == NULL) {
		return;
	}
	else {
		list->current = list->tail;
	}
}


// insert data after current node
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

// insert data before current node
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

// delete the current node from the list
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
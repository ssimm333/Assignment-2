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

#include <stdio.h>
#include <stdlib.h>
#include "functionDeclarations.h"

typedef int data;

// defining the structure of a node in the double linked list
typedef struct Node {
	data d;
	struct Node* successor;			// pointer to the next node
	struct Node* predecessor;		// pointer to the previous node
} dllNode;


// defining the structure for the double linked list
typedef struct DoubleLinkedList {
	dllNode* head;
	dllNode* tail;
	dllNode* current;
} DoubleLinkedList;



// create a new empty double linked list
// consisting of only a head and tail
DoubleLinkedList* createDoubleLinkedList() {

	// Pre: None
	
	// allocating memory for double linked list
	DoubleLinkedList* doubleLinkedList = (DoubleLinkedList*) malloc(sizeof(DoubleLinkedList));

	// allocating memory for the head and tail node
	dllNode* head = (dllNode*) malloc(sizeof(dllNode));
	dllNode* tail = (dllNode*) malloc(sizeof(dllNode));

	// initialising head and tail nodes
	head -> predecessor = NULL;
	head -> successor = tail;
	tail-> predecessor = head;
	tail-> successor = NULL;

	// assigning head and tail nodes to the double linked list
	doubleLinkedList -> head = head;
	doubleLinkedList -> tail = tail;

	// Post: Empty double linked list is created
	return doubleLinkedList;
}
	
// delete a list, including all its elements
DoubleLinkedList* deleteDoubleLinkedList(DoubleLinkedList* list) {

	// Pre: valid double linked list exists
	if (list == NULL || list->head == NULL) {
		// pre condition not met
		printf("Error: Invalid double linked list\n");
		return NULL;
	}

	// go through the list and delete each node
	dllNode* current = list->head;
	while (current != NULL) {
		dllNode* next = current->successor;
		free(current);
		current = next;
	}

	// freeing the list structure
	free(list);

	// Post: The entire list is deleted
	return NULL;
}

// returns the data associated with current node
DoubleLinkedList* getData(DoubleLinkedList* list) {
	
	// Pre: valid double linked list exists
	if (list == NULL || list->head == NULL) {
		printf("Error: Invalid double linked list\n");
		return NULL;
	}

	// Post: data of current node is returned
	return list->current->d;
}

// sets current node to the successor of current
DoubleLinkedList* gotoNextNode(DoubleLinkedList* list) {

	// Pre: valid double linked list exists
	if (list == NULL || list->head == NULL) {
		printf("Error: INvalud double linked list\n");
		return NULL;
	}

	// Post: if current node is other than tail, current node is set to successor 
	// of current node. Otherwise, list remains unchanged.
	if (list->current != list->tail) {
		list->current = list->current->successor;
	}
	return list->current;
}

// sets current node to predeccessor of current
DoubleLinkedList* gotoPreviousNode(DoubleLinkedList* list) {
	// Pre: valid double linked list exists
	if (list == NULL || list->head == NULL) {
		printf("Error: Invalid doube linked list\n");
		return NULL;
	}

	// Post: if current node is other than head, current node is set to predeccessor 
	// of current node. Otherwise, list remains unchanged.
	if (list->current != list->head) {
		list->current = list->current->predecessor;
	}
	return list->current;
}

// sets current node to head
DoubleLinkedList* gotoHead(DoubleLinkedList* list) {
	// Pre: valid double linked list exists
	if (list == NULL || list->head == NULL) {
		printf("Error: Invalid double linked list\n");
		return NULL;
	}

	// Post: current node is set to head
	list->current = list->head;
	return list->current;
}

// sets current node to tail
DoubleLinkedList* gotoTail(DoubleLinkedList* list) {
	// Pre: valid double linked list exists
	if (list == NULL || list->head == NULL) {
		printf("Error: Invalid double linked list\n");
		return NULL;
	}

	// Post: current node is set to tail
	list->current = list->tail;
	return list->current;
}


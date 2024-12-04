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
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "functionDeclarations.h"

// create a new empty double linked list
// consisting of only a head and tail
DoubleLinkedList* createDoubleLinkedList() {
	// Pre: None

	   // Allocate memory for the doubly linked list structure
	DoubleLinkedList* doubleLinkedList = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
	if (doubleLinkedList == NULL) {
		printf("Error: memory allocation failed\n");
		return NULL;
	}

	// Allocate memory for the head and tail dummy nodes
	dllNode* head = (dllNode*)malloc(sizeof(dllNode));
	dllNode* tail = (dllNode*)malloc(sizeof(dllNode));
	if (head == NULL || tail == NULL) {
		printf("Error: memory allocation for head or tail failed\n");
		free(doubleLinkedList); // Clean up
		return NULL;
	}



	// Initialize dummy head and tail nodes
	head->successor = tail;  // Head points to tail
	head->predecessor = NULL; // Head has no predecessor
	tail->successor = NULL;   // Tail has no successor
	tail->predecessor = head; // Tail's predecessor is head

	// Assign the head and tail to the list
	doubleLinkedList->head = head;
	doubleLinkedList->tail = tail;
	doubleLinkedList->current = head; // Initialize current to head node (important for traversal)
	doubleLinkedList->size = 0;

	// Post: Empty doubly linked list is created with proper initialization
	return doubleLinkedList;
}

// delete a list, including all its elements
DoubleLinkedList* deleteDoubleLinkedList(DoubleLinkedList* list) {

	// Pre: valid double linked list exists
	if (list == NULL) {
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
	if (list == NULL) {
		printf("Error: Invalid double linked list\n");
		return NULL;
	}

	// Post: data of current node is returned
	return list->current->d;
}

// sets current node to the successor of current
DoubleLinkedList* gotoNextNode(DoubleLinkedList* list) {

	// Pre: valid double linked list exists and current is valid
	 // Check if the list or the current node is NULL
	if (list == NULL || list->current == NULL) {
		printf("Error: Invalid double linked list or current node is NULL.\n");
		return NULL;  // Exit if the list or current node is NULL
	}

	// If the current node does not have a successor, we should stop
	if (list->current->successor == NULL) {
		printf("Error: Current node does not have a successor.\n");
		return NULL;  // Exit if there is no successor
	}

	// Move to the next node
	list->current = list->current->successor;
	return list;
}

// sets current node to predeccessor of current
DoubleLinkedList* gotoPreviousNode(DoubleLinkedList* list) {
	// Pre: valid double linked list exists
	if (list == NULL) {
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
	// Check if the list is NULL or has no head
	if (list == NULL || list->head == NULL) {
		printf("Error: Invalid double linked list or head is NULL.\n");
		return NULL;  // Exit if the list or head is NULL
	}
	list->current = list->head->successor;  // Move to the first element
	return list;
}



// sets current node to tail
DoubleLinkedList* gotoTail(DoubleLinkedList* list) {
	// Pre: valid double linked list exists
	if (list == NULL) {
		printf("Error: Invalid double linked list\n");
		return NULL;
	}

	// Post: current node is set to tail
	list->current = list->tail;
	return list->current;
}

// creates a new node, associates newdata with it and 
// inserts it after the current node.
DoubleLinkedList* insertAfter(DoubleLinkedList* list, data newdata) {
	// Pre: valid double linked list exists and newdata is valid data
	if (list == NULL || newdata == NULL) {
		printf("Error: Invalid double linked list OR Invalid data\n");
		return NULL;
	}

	// allocating memory for new node
	dllNode* newNode = (dllNode*)malloc(sizeof(dllNode));

	// initialising new node
	if (newNode == NULL) {
		enum ReturnValue result = ALLOCATION_ERROR;
		printf("Error: memeory allocation failed\n");
		return NULL;
	} else {
		// initialising new node
		newNode->d = newdata;
	}

	// Post: if current is not tail, new node is inserted after
	// current node. Otherwise list remains unchanged and an error 
	// is returned.
	if (list->current != NULL && list->current != list->tail) {
		newNode->predecessor = list->current;
		newNode->successor = list->current->successor->successor;
	} else {
		printf("Error: current node is tail\n");
		return NULL;
	}
}

// creates a new node, associates newdata with it and inserts it 
// before the current node.
DoubleLinkedList* insertBefore(DoubleLinkedList* list, data newdata) {
	// Pre: valid double linked list exists and newdata is valid data
	if (list == NULL ||  newdata == NULL) {
		printf("Error: Invalid double linked list\n");
		return NULL;
	}

	// allocating memory for new node
	dllNode* newNode = (dllNode*)malloc(sizeof(dllNode));

	// initialising new node
	if (newNode == NULL) {
		enum ReturnValue result = ALLOCATION_ERROR;
		printf("Error: memeory allocation failed\n");
		return NULL;
	}
	else {
		// initialising new node
		newNode->d = newdata;
	}

	// Post: if current node is not head, new node is inserted 
	// before current node. Otherwise list remains unchanged and an 
	// error is returned.
	if (list->current != list->head) {
		newNode->predecessor = list->current->predecessor;
		newNode->successor = list->current;
		list->current->predecessor->successor = newNode;
		list->current->predecessor = newNode;
		return list;
	} else {
		printf("Error: Invalid double linked list\n");
		return NULL;
	}
}

DoubleLinkedList* deleteCurrentNode(DoubleLinkedList* list) {
	// Pre: valid double linked list exists
	if (list == NULL) {
		printf("Error: Invalid double linked list\n");
		return NULL;
	}

	// Post: if current node is other than head or tail,
	// current node is removed from list. Otherwise, an error is returned
	if (list->current != list->head && list->current != list->tail) {
		list->current->predecessor->successor = list->current->successor;
		list->current->successor->predecessor = list->current->predecessor;
		free(list->current);
		return list;
	} else {
		printf("Error: Invalid double linked list\n");
		return NULL;
	}
}


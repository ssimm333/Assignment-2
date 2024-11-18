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

	// allocating memory for double linked list
	DoubleLinkedList* doubleLinkedList = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));

	// allocating memory for the head and tail node
	dllNode* head = (dllNode*)malloc(sizeof(dllNode));
	dllNode* tail = (dllNode*)malloc(sizeof(dllNode));

	// initialising head and tail nodes
	head->predecessor = NULL;
	head->successor = tail;
	tail->predecessor = head;
	tail->successor = NULL;

	// assigning head and tail nodes to the double linked list
	doubleLinkedList->head = head;
	doubleLinkedList->tail = tail;

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

// creates a new node, associates newdata with it and 
// inserts it after the current node.
DoubleLinkedList* insertAfter(DoubleLinkedList* list, data newdata) {
	// Pre: valid double linked list exists and newdata is valid data
	if (list == NULL || list->head == NULL || newdata == NULL) {
		printf("Error: Invalid double linked list\n");
		return NULL;
	}

	// allocating memory for new node
	dllNode* newNode = (dllNode*)malloc(sizeof(dllNode));

	// initialising new node
	newNode->d = newdata;

	// setting current to new node
	list->current = newNode;

	// Post: if current is not tail, new node is inserted after
	// current node. Otherwise list remains unchanged and an error 
	// is returned.
	if (list->current != list->tail) {
		newNode->predecessor = list->current;
		newNode->successor = list->current->successor;
		list->current->successor->predecessor = newNode;
		list->current->successor = newNode;
		return list;
	}
	else {
		printf("Error: Invalid double linked list\n");
		return NULL;
	}
}

// creates a new node, associates newdata with it and inserts it 
// before the current node.
DoubleLinkedList* insertBefore(DoubleLinkedList* list, data newdata) {
	// Pre: valid double linked list exists and newdata is valid data
	if (list == NULL || list->head == NULL || newdata == NULL) {
		printf("Error: Invalid double linked list\n");
		return NULL;
	}

	// allocating memory for new node
	dllNode* newNode = (dllNode*)malloc(sizeof(dllNode));

	// initialising new node
	newNode->d = newdata;

	// Post: if current node is not head, new node is inserted 
	// before current node. Otherwise list remains unchanged and an 
	// error is returned.
	if (list->current != list->head) {
		newNode->predecessor = list->current->predecessor;
		newNode->successor = list->current;
		list->current->predecessor->successor = newNode;
		list->current->predecessor = newNode;
		return list;
	}
	else {
		printf("Error: Invalid double linked list\n");
		return NULL;

	}
}

DoubleLinkedList* deleteCurrentNode(DoubleLinkedList* list) {
	// Pre: valid double linked list exists
	if (list == NULL || list->head == NULL) {
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
	}
	else {
		printf("Error: Invalid double linked list\n");
		return NULL;
	}
}
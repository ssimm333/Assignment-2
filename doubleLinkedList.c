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

/**
 * @brief This function creates a double linked list
 * 
 * @details The function allocates memory for a double 
 *          linked list consisting of only a head and tail
 *          and initialises each of its fields. 
 * 
 * @return Empty double linked list
 */
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

/**
 * @brief This function deletes a double linked list
 *
 * @param list
 *
 * @details The function, once given a valid list, goes
 *          through the list and deletes each node and
 *          frees the list structure. 
 *  
 * @return NULL
 */
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

/**
 * @brief This function finds the data for a specific node.
 * 
 * @param list
 * 
 * @details The function returns the data associated 
 *          with the current node, so long as it is
 *          part of a valid double linked list.
 * 
 * @return Data of current node
 */
DoubleLinkedList* getData(DoubleLinkedList* list) {

	// Pre: valid double linked list exists
	if (list == NULL) {
		printf("Error: Invalid double linked list\n");
		return NULL;
	}

	// Post: data of current node is returned
	return list->current->d;
}

/**
 * @brief This function sets the current node to the successor of the current node
 * 
 * @param list
 * 
 * @details The function, once given a valid list, 
 *          sets the current node to the successor 
 *          of the current node
 * 
 * @return Current node
 */
DoubleLinkedList* gotoNextNode(DoubleLinkedList* list) {

	// Pre: valid double linked list exists
	if (list == NULL) {
		printf("Error: Invalid double linked list\n");
		return NULL;
	}

	// Post: if current node is other than tail, current node is set to successor 
	// of current node. Otherwise, list remains unchanged.
	if (list->current != list->tail) {
		list->current = list->current->successor;
	}
	return list->current;
}

/**
 * @brief This function sets the current node to the predecessor of the current node
 * 
 * @param list
 * 
 * @details The function, once given a valid list, 
 *          sets the current node to the predecessor 
 *          of the current node
 * 
 * @return Current node
 */
DoubleLinkedList* gotoPreviousNode(DoubleLinkedList* list) {
	// Pre: valid double linked list exists
	if (list == NULL) {
		printf("Error: Invalid double linked list\n");
		return NULL;
	}

	// Post: if current node is other than head, current node is set to predeccessor 
	// of current node. Otherwise, list remains unchanged.
	if (list->current != list->head) {
		list->current = list->current->predecessor;
	}
	return list->current;
}

/**
 * @brief This function sets the current node to the head
 * 
 * @param list
 * 
 * @details The function, once given a valid list,
 *          sets the current node to the head of the list
 * 
 * @return Current node
 */
DoubleLinkedList* gotoHead(DoubleLinkedList* list) {
	// Pre: valid double linked list exists
	if (list == NULL) {
		printf("Error: Invalid double linked list\n");
		return NULL;
	}

	// Post: current node is set to head
	list->current = list->head;
	return list->current;
}


/**
 * @brief This function sets the current node to the tail
 * 
 * @param list
 * 
 * @details The function, once given a valid list,
 *          sets the current node to the tail of the list
 * 
 * @return Current node
 */
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

/**
 * @brief This function creates a new node
 * 
 * @param list
 * @param newdata
 * 
 * @details The function, once given a valid list and valid data,
 *          creates a new node, associates newdata with it and 
 *          inserts it after the current node.
 * 
 * @return Double linked list
 */
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

/**
 * @brief This function creates a new node
 * 
 * @param list
 * @param newdata
 * 
 * @details The function, once given a valid list and valid data,
 *          creates a new node, associates newdata with it and 
 *          inserts it before the current node.
 * 
 * @return Double linked list
 */
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

/**
 * @brief This function deletes the current node.
 * 
 * @param list
 * 
 * @details The function, once given a valid list, 
 *          deletes the current node from the list
 * 
 * @return Double linked list
 */
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


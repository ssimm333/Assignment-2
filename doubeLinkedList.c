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

// defining the structure of a node in the double linked list
typedef struct Node {
	void* data;
	struct Node* successor;			// pointer to the next node
	struct Node* predecessor;		// pointer to the previous node
} Node;


// defining the structure for the double linked list
typedef struct DoubleLinkedList {
	Node* head;
	Node* tail;
} DoubleLinkedList;



// create a new empty double linked list
// consisting of only a head and tail
DoubleLinkedList* createDoubleLinkedList() {

	// Pre: None
	
	// allocating memory for double linked list
	DoubleLinkedList* doubleLinkedList = (DoubleLinkedList*) malloc(sizeof(DoubleLinkedList));

	// allocating memory for the head and tail node
	Node* head = (Node*) malloc(sizeof(Node));
	Node* tail = (Node*) malloc(sizeof(Node));

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
DoubleLinkedList* deleteDoubleLinkedList() {

	// Pre: valid double linked list exists
	if (list == NULL || list->head == NULL) {
		// pre condition not met
		printf("Error: Invalid double linked list\n");
		return NULL;
	}

	// go through the list and delete each node
	Node* current = list->head;
	while (current != NULL) {
		Node* next = current->successor;
		free(current);
		current = next;
	}

	// freeing the list structure
	free(list);

	// Post: The entire list is deleted
	return NULL;
}


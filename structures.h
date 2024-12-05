#pragma once

// defining the data stores in a node
typedef int data;

// defining the structure of a node within the list
typedef struct Node {
	data d;				// data stored in the node
	struct Node* next;		// pointer to the next node
	struct Node* prev;		// pointer to the previous node
} dllNode;

// defining the structure of the list
typedef struct List {
	dllNode* head;				// pointer to the head of the list
	dllNode* tail;				// pointer to the tail of the list
	dllNode* current;			// pointer to the current node
} dllist;

// defining the structure of an Ordered Set
typedef struct OrderedSet {
	dllNode* head;				// pointer to the head of the set
	dllNode* tail;				// pointer to the tail of the set
	dllNode* current;			// pointer to the current node
	int size;					// size of the set
} OrderedSet;
#pragma once

/*****************************************************************//**
 * @file	structures.h
 * @brief	file containing structure definitions for the list and ordered set for the program
 *
 * @author Stanislav Simanovich		23366109
 * @author Calum Breen				23368357
 * @author Emilia Hildebrandt		23356421
 * @author Tiernan O'Shaughnessy	23356642
 * @author Jordi Roca				24277215
 * @author Bengisu Fansa			24221104
 *
 * @date 05 December 2024
 *********************************************************************/

/**
 * @brief The data type of the elements in the list.
 * 
 * Data is to be of an integer value
 */
typedef int data;

/**
 * @brief The structure of a node in the list.
 * 
 * The node hold a value and pointers to the next and previous nodes.
 */
typedef struct Node {
	data d;					// data stored in the node
	struct Node* next;		// pointer to the next node
	struct Node* prev;		// pointer to the previous node
} dllNode;

/**
 * @brief The structure of a list.
 * 
 * The list contains a head, tail, and current node.
 */
typedef struct List {
	dllNode* head;				// pointer to the head of the list
	dllNode* tail;				// pointer to the tail of the list
	dllNode* current;			// pointer to the current node
} dllist;

/**
 * @brief The structure of an ordered set.
 * 
 * The ordered set contains a head, tail, and current node, 
 * along with a size representing the number of elements within the set.
 */
typedef struct OrderedSet {
	dllNode* head;				// pointer to the head of the set
	dllNode* tail;				// pointer to the tail of the set
	dllNode* current;			// pointer to the current node
	int size;					// size of the set
} OrderedSet;

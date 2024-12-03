/*****************************************************************//**
 * @file	main.c
 * @brief	main file used to implement the text menu driven application
 *
 * @author Stanislav Simanovich
 * @author Calum Breen
 * @author Emilia Hildebrandt
 * @author Tiernan O'Shaughnessy
 * @author Jordi Roca
 * @author Bengisu Fansa
 *
 *
 * @date 13 November 2024
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "functionDeclarations.h"

 /**
 * @brief Creates an empty ordered integer set.
 * 
 * Allocates memory for an ordered integer set and initializes its fields.
 * 
 * @return A pointer to the newly created ordered integer set.
 */
orderedIntSet* createOrderedIntSet() {
	orderedIntSet* set = (orderedIntSet*)malloc(sizeof(orderedIntSet));
	if (set == NULL) {
		// memory allocation failed
		enum ReturnValue result = ALLOCATION_ERROR;
		printf("Error: memory allocation failed\n");
		return NULL;
	} else {
		// set in not null. therefore wer can access its memebers
		set->head = NULL;
		set->tail = NULL;
		set->size = 0;
		return set;
	}
}

/**
 * @brief Deletes an ordered integer set and frees its memory.
 * 
 * @param s A pointer to the ordered integer set to delete.
 * @return NULL after the set is successfully deleted.
 */
orderedIntSet* deleteOrderedIntSet(orderedIntSet* s) {
	if (s == NULL) {
		printf("Error: Invalid ordered set\n");
		return NULL;
	}
	else {
		// delete the whole list except head and tail
		dllNode* current = s->head->successor;
		while (current != s->tail) {
			free(current);
			current = current->successor;
		}
		free(s);
		return NULL;
	}
}

/**
 * @brief Adds an element to the ordered set.
 * 
 * Checks for duplicates and inserts the element in its proper position to maintain order.
 * 
 * @param s Pointer to the double-linked list representing the set.
 * @param elem The integer element to add to the set. 
 * @return Enumeration value indicating the operation's outcome.
*/
enum ReturnValue addElement(DoubleLinkedList* s, int elem) {

    // checking for duplicates
    dllNode* current = s->head->successor;
    while (current != s->tail) {
        if (current->d == elem) {
            return NUMBER_ALREADY_IN_SET;
        }
        current = current->successor;
    }

    // Create a new node for the element
    dllNode* newNode = (dllNode*)malloc(sizeof(dllNode));
	if (newNode == NULL) {
		return ALLOCATION_ERROR;
	}
    newNode->d = elem;
	
	// inserting node into list
	insertAfter(s, elem);

    //newNode->successor = NULL;
    //newNode->predecessor = NULL;

    //// If the list is empty
    //if (s->head == NULL) {
    //    s->head = newNode;
    //    s->tail = newNode;
    //}
    //// If inserting at the end
    //else if (current == NULL) {
    //    s->tail->successor = newNode;
    //    newNode->predecessor = s->tail;
    //    s->tail = newNode;
    //}
    //// If inserting in the middle
    //else {
    //    if (current->predecessor) {
    //        current->predecessor->successor = newNode;
    //    } else {
    //        s->head = newNode;
    //    }
    //    newNode->predecessor = current->predecessor;
    //    newNode->successor = current;
    //    current->predecessor = newNode;
    //}

    //s->size++;
    //return NUMBER_ADDED;
}
/**
 * @brief Removes an element from the oredered set.
 * 
 * Locates the specified element and removes it while maintaining the List's integrity.
 * 
 * @param s Pointer to the double-linked list representing the set.
 * @param elem The integer element to remove from the set. 
 * @return Enumeration value indicating the operation's outcome.
*/
enum ReturnValue removeElement(DoubleLinkedList* s, int elem) {

	// find the element
	dllNode* current = s->head->successor;
	while (current != s->tail) {
		if (current->d == elem) {
			// remove the element
			deleteCurrentNode(s);
			return NUMBER_REMOVED;
		}
		current = current->successor;
	}
	return NUMBER_NOT_IN_SET;
}

/**
 * @brief Computes the intersection of two sets.
 * 
 * Creates a new set containing elements coomon to both input sets.
 * 
 * @param s1 Pointer to the first set.
 * @param s2 Pointer to the second set.
 *@return A pointer to the resulting set containing the intersections.
*/
orderedIntSet* setIntersection(orderedIntSet* s1, orderedIntSet* s2) {

	// Create interset
	orderedIntSet* interset = createOrderedIntSet();

	//Find first element of set 1
	s1 = gotoHead(s1);
	s1 = gotoNextNode(s1);

	// for each node in set1
	while (s1->current != s1->tail) {

		//Find first element of set 2
		s2 = gotoHead(s2);
		s2 = gotoNextNode(s2);

		// For each node in set 2
		while (s2->current != s2->tail) {

			// If set i1 == set i2
			if (s1->current->d == s2->current->d) {

				// add node i to interset
				interset = insertAfter(interset, s2->current->d);
			}

			s2 = gotoNextNode(s2);
		}

		s1 = gotoNextNode(s1);
	}
	return interset;
}

/**
 * @brief Computes the union of two sets.
 * 
 * Creates a new set containing all unique elements from both input sets.
 * 
 * @param s1 Pointer to the first set.
 * @param s2 pointer to the second set.
 * @return A pointer to the resulting set containing the union.
*/
orderedIntSet* setUnion(orderedIntSet * s1, orderedIntSet * s2) {

	// Create uniset
	orderedIntSet* uniset = createorderedIntSet();

	//Find first element of set 1
	s1 = gotoHead(s1);
	s1 = gotoNextNode(s1);

	//for each node in set1
	while (s1->current != s1->tail) {

		// Add node to uniset
		uniset = insertAfter(uniset, s1->current->d);
		s1 = gotoNextNode(s1);
	}

	// Find first element of set2
	s2 = gotoHead(s2);
	s2 = gotoNextNode(s2);

	// for each node in set2
	while (s2->current != s2->tail) {

		// for each node in uniset
		while (uniset->current != uniset->tail) {

			// if uniseti < set2i
			if (uniset->current->d < s2->current->d) {

				// go to next node
				uniset = gotoNextNode(uniset);

				// if uniseti == set2i
			}
			else if (uniset->current->d == s2->current->d) {

				// go to tail
				uniset = gotoTail(uniset);

				// if uniseti > set2i
			}
			else {

				//add node before current and go to tail
				uniset = insertBefore(uniset, s2->current->d);
				uniset = gotoTail(uniset);
			}
		}
		s2 = gotoNextNode(s2);
	}
	return uniset;
}
/**
 * @brief Computes the difference of two sets.
 * 
 * Creates a new set conaining elements present in the first set but not in the second set.
 * 
 * @param s1 Pointer to the first set.
 * @param s2 Pointer to the second set.
 * @return A pointer to the resulting set containing the difference.
*/
DoubleLinkedList* setDifference(DoubleLinkedList* s1, DoubleLinkedList* s2) {
	// Create diffset
	DoubleLinkedList* diffset = createDoubleLinkedList();

	// Find first element of set 1
	s1 = gotoHead(s1);
	s1 = gotoNextNode(s1);

	// for each node in set1
	while (s1->current->successor != NULL) {

		// Find first element of set 2
		s2 = gotoHead(s2);
		s2 = gotoNextNode(s2);

		// for each node in set 2
		while (s2->current->successor != NULL) {

			// if set1i == set2i
			if (s1->current->d == s2->current->d) {

				// go to next node
				s1 = gotoNextNode(s1);
				s2 = gotoNextNode(s2);

				// if set1i < set2i
			}
			else if (s1->current->d < s2->current->d) {

				// add node to diffset
				diffset = insertAfter(diffset, s1->current->d);
				s1 = gotoNextNode(s1);

				// if set1i > set2i
			}
			else {

				// go to next node
				s2 = gotoNextNode(s2);
			}
		}
	}
	return diffset;
}
/**
 * @brief Prints the contents of the set to stadard output.
 * 
 * Outputs the set in the format {num1,num2,num3}.
 * 
 * @param s Pointer to the set to print.
 * @return The same pointer passed as input.
*/

// print to stdout
//
// Prints the contents of the set s to stdout. in format {num1,num2,num3}
// empty set is {}
orderedIntSet* printToStdout(orderedIntSet* s) {
	printf("{");

	// Find first element of set
	s = gotoHead(s);
	s = gotoNextNode(s);

	// for each node in set
	while (s->current->successor != s->tail) {
		printf("%i,", s->current->d);
		s = gotoNextNode(s);
	}
	printf("}");
	return s;
}
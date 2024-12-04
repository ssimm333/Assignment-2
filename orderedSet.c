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
		set->list = createDoubleLinkedList();
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
		deleteDoubleLinkedList(s->list);
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
enum ReturnValue addElement(orderedIntSet* s, int elem) {
	
	// Find first element
	gotoHead(s->list);
	gotoNextNode(s->list);

	// Go through set
	while (s->list->current =! s->list->tail) {
		
		
		if (elem < s->list->current->d) {
			gotoNextNode(s->list);
		} else if (elem == s->list->current->d) {
			printf("\nElement already in set\n");
			return;
		} else {
			insertBefore(s->list, elem);
			return;
		}
	}
	
    
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
enum ReturnValue removeElement(orderedIntSet* s, int elem) {

	// Go to first element
	gotoHead(s->list);
	gotoNextNode(s->list);

	// find the element
	while (s->list->current =! s->list->tail) {
		if (s->list->current == elem) {
			// remove the element
			deleteCurrentNode(s);
			return NUMBER_REMOVED;
		}
		gotoNextNode(s->list);
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
void setIntersection(orderedIntSet* s1, orderedIntSet* s2, orderedIntSet* inter) {

	

	//Find first element of set 1
	gotoHead(s1);
	gotoNextNode(s1);

	// for each node in set1
	while (s1->list->current != s1->list->tail) {

		//Find first element of set 2
		gotoHead(s2);
		gotoNextNode(s2);

		// For each node in set 2
		while (s2->list->current != s2->list->tail) {

			// If set i1 == set i2
			if (s1->list->current->d == s2->list->current->d) {

				// add node i to interset
				insertAfter(inter, s2->list->current->d);
			}

			gotoNextNode(s2);
		}

		gotoNextNode(s1);
	}
	return;
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
void setUnion(orderedIntSet* s1, orderedIntSet* s2, orderedIntSet* uniset) {


	//Find first element of set 1
	gotoHead(s1);
	gotoNextNode(s1);

	//for each node in set1
	while (s1->list->current != s1->list->tail) {

		// Add node to uniset
		insertAfter(uniset, s1->list->current->d);
		gotoNextNode(s1);
	}

	// Find first element of set2
	gotoHead(s2);
	gotoNextNode(s2);

	// for each node in set2
	while (s2->list->current != s2->list->tail) {

		// for each node in uniset
		while (uniset->list->current != uniset->list->tail) {

			// if uniseti < set2i
			if (uniset->list->current->d < s2->list->current->d) {

				// go to next node
				gotoNextNode(uniset);

				// if uniseti == set2i
			}
			else if (uniset->list->current->d == s2->list->current->d) {

				// go to tail
				gotoTail(uniset);

				// if uniseti > set2i
			}
			else {

				//add node before current and go to tail
				insertBefore(uniset, s2->list->current->d);
				gotoTail(uniset);
			}
		}
		gotoNextNode(s2);
	}
	return;
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
	while (s->list->current->successor != s->list->tail) {
		printf("%i,", s->list->current->d);
		s = gotoNextNode(s);
	}
	printf("}");
	return s;
}
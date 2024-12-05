/*****************************************************************//**
 * @file	orderedSet.c
 * @brief	Function definitions for ordered set operations, such as creating and deleting ordered sets.
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

#include <stdlib.h>
#include <stdio.h>
#include "functionDeclarations.h"
#include "enum.h"

/**
 * @brief Allocates memory and creates an ordered set.
 * 
 * Sets appropriate pointers for a empty set consisting only of a head and tail node.
 * Size is set to 0 to indicate that the set is empty.
 * 
 * @return enumeration value indicating success or failure of the operation or the set itself if memory allocation was successful.
 */
OrderedSet* createOrderedSet() {
	// allocate memory
	OrderedSet* set = (OrderedSet*)malloc(sizeof(OrderedSet));

	// test for allocation error
	if (set == NULL) {
		return AllocationError;
	}

	// allocate memory for head node
	set->head = (dllNode*)malloc(sizeof(dllNode));

	// test for allocation error
	if (set->head == NULL) {
		free(set);
		return AllocationError;
	}

	// allocate memory for tail node
	set->tail = (dllNode*)malloc(sizeof(dllNode));

	// test for allocation error
	if (set->tail == NULL) {
		free(set->head);
		free(set);
		return AllocationError;
	}

	// set pointers
	set->head->next = set->tail;
	set->head->prev = NULL;
	set->tail->next = NULL;
	set->tail->prev = set->head;
	set->current = set->head;
	set->size = 0;
	return set;
}

/**
 * @brief Frees memory allocated for the ordered set.
 * 
 * The head and tail nodes are deleted, and any other dynamically allocated nodes.
 * Set is freed from memory.
 * 
 * @param set The ordered set to be deleted.
 */
void deleteOrderedSet(OrderedSet* set) {
	// check valid set exists
	if (set == NULL) {
		return;
	}
	dllNode* current = set->head;
	while (current != NULL) {
		dllNode* next = current->next;
		free(current);
		current = next;
	}
	free(set);
}

/**
 * @brief Adds an element to the ordered set.
 * 
 * Checks if the element is already in the set. If not, it is put into the correct position 
 * as to maintain ascending order of all the elements within the list.
 * 
 * @param set The ordered set to add the element to.
 * @param newdata The data to be added to the set, of an integer value.
 */
enum ReturnValue addElement(OrderedSet* set, data newdata) {
	// check valid set exists
	if (set == NULL) {
		return AllocationError;
	}

	// check if the new data is already in the set
	dllNode* current = set->head->next; // start from the first element
	while (current != set->tail) {
		if (current->d == newdata) {
			return NumberInSet;
		}
		current = current->next;

	}

	gotoHead(set);

	// find correct position for the node
	while (set->current->next != set->tail && set->current->next->d < newdata) {
		gotoNextNode(set);
	}

	insertAfter(set, newdata);
	set->size++;
	return NumberAdded;
}


/**
 * @brief Removes an element from the ordered set.
 * 
 * Checks if the element is in the set. If so, it is removed from the set.
 * Otherwise, the function returns a value indicating that the element is not in the set.
 * 
 * @param set The ordered set to remove the element from.
 * @param elem The element to be removed from the set, of an integer value.
 * 
 * @return Enumeration value indicating if the element was removed or doesnt exist..
 */
enum ReturnValue removeElement(OrderedSet* set, int elem) {
	// check valid set exists
	if (set == NULL) {
		return AllocationError;
	}

	// look if value is there 
	if (set->size == 0) {
		return NumberNotInSet;
	}

	gotoHead(set);
	while (set->current->d != elem) {
		gotoNextNode(set);
		if (set->current->d == elem) {
			deleteCurrent(set);
			return NumberRemoved;
			set->size--;
		}
		else {
			if (set->current->next == NULL) {
				return NumberNotInSet;
			}
		}
	}
}

/**
 * @brief Returns the intersection of two ordered sets. ie: the common elements .
 * 
 * @param set1 The first set
 * @param set2 The second set
 * 
 * @return A new ordered set with the common elements of set1 and set2.
 */
OrderedSet* setIntersection(OrderedSet* set1, OrderedSet* set2) {

	OrderedSet* interset = createOrderedSet();

	if (set1 == NULL && set2 == NULL) {
		return NULL;
	}

	else if (set1 == NULL) {
		return set2;
	}

	else if (set2 == NULL) {
		return set1;
	}

	dllNode* current1 = set1->head;
	while (current1 != NULL) {
		dllNode* current2 = set2->head;
		while (current2 != NULL) {
			if (current1->d == current2->d) {
				if (interset->head == NULL || interset->head->d != current1->d) {
					addElement(interset, current1->d);
				}
				break;
			}
			current2 = current2->next;
		}
		current1 = current1->next;
	}

	return interset;
}

/**
 * @brief Returns the union of two ordered sets, ie: the elements of both sets, with no duplicates.
 * 
 * @param set1 The first set
 * @param set2 The second set
 * 
 * @return A new ordered set with the union of set1 and set2
 */
OrderedSet* setUnion(OrderedSet* set1, OrderedSet* set2) {
	OrderedSet* unionset = createOrderedSet();

	if (set1 == NULL && set2 == NULL) {
		return unionset; // Return an empty set
	}

	if (set1 != NULL) {
		set1->current = set1->head->next; // Reset to head
		while (set1->current != set1->tail) { // Traverse set1
			addElement(unionset, set1->current->d);
			set1->current = set1->current->next;
		}
	}

	if (set2 != NULL) {
		set2->current = set2->head->next; // Reset to head
		while (set2->current != set2->tail) { // Traverse set2
			addElement(unionset, set2->current->d);
			set2->current = set2->current->next;
		}
	}

	return unionset;
}

/**
 * @brief Returns the difference of two ordered sets, ie: the elements of set1 that are not in set2.
 * 
 * @param set1 first set
 * @param set2 second set
 * 
 * @return a new ordered set with the difference of set1 and set2
 */
OrderedSet* setDifference(OrderedSet* set1, OrderedSet* set2) {
	OrderedSet* diffset = createOrderedSet();

	if (set1 == NULL) {
		diffset = NULL;
		return diffset;
	}

	if (set2 == NULL) {
		diffset = set1;
		return diffset;
	}

	dllNode* current1 = set1->head;
	while (current1 != NULL) {
		dllNode* current2 = set2->head;
		int found = 0;
		while (current2 != NULL) {
			if (current1->d == current2->d) {
				found = 1;
				break;
			}
			current2 = current2->next;
		}
		if (!found) {
			addElement(diffset, current1->d);
		}
		current1 = current1->next;
	}

	return diffset;
}

/**
 * @brief Prints the ordered set to stdout.
 * 
 * If the set is empty, it prints "{}".
 * Otherwise it prints "{element1,element2,...,elementn}"
 * 
 * @param set which is to be printed
 */
void printToStdout(OrderedSet* set) {
	if (set == NULL) {
		printf("{}");
		return;
	}

	if (set->head->next == set->tail) {
		printf("{}");
		return;
	}
	printf("{");
	gotoHead(set);

	if (set->current->next == set->tail) {
		printf("%d}", set->current->d);
		return;
	}

	gotoNextNode(set);

	while (set->current->next != set->tail) {
		printf("%d,", set->current->d);
		gotoNextNode(set);
	}
	printf("%d}", set->current->d);
}

/**
 * @brief Sorts the ordered set into ascending order.
 * 
 * @param set which is to be ordered
 * 
 * @return the sorted ordered set
 */
OrderedSet* sortSet(OrderedSet* set) {
	// create 
	createOrderedSet();
}

/**
 * @brief Prints the menu.
 * 
 * Menu is printed to stdout for the user.
 */
void printMenu() {
	printf("\nChoose from the following:");
	printf("\n1) Create empty ordered set");
	printf("\n2) Delete ordered set");
	printf("\n3) Add element to ordered set");
	printf("\n4) Remove element from ordered set");
	printf("\n5) Set intersection");
	printf("\n6) Set union");
	printf("\n7) Set difference");
	printf("\n8) Terminate program\n");
}
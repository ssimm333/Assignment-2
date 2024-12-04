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
		printf("Error: memory allocation failed for set\n");
		return NULL;
	}

	// Create head and tail nodes
	set->head = (dllNode*)malloc(sizeof(dllNode));
	set->tail = (dllNode*)malloc(sizeof(dllNode));

	if (set->head == NULL || set->tail == NULL) {
		printf("Error: memory allocation failed for head or tail\n");
		free(set); // Clean up
		return NULL;
	}

	// Initialize the head and tail nodes
	set->head->successor = set->tail;  // head points to tail
	set->head->predecessor = NULL;     // head has no predecessor
	set->tail->predecessor = set->head; // tail points back to head
	set->tail->successor = NULL;        // tail has no successor

	set->current = set->head;  // Ensure the current pointer starts at the head

	set->size = 0;
	return set;
}

/**
 * @brief Deletes an ordered integer set and frees its memory.
 * 
 * @param s A pointer to the ordered integer set to delete.
 * @return NULL after the set is successfully deleted.
 */
orderedIntSet* deleteOrderedIntSet(orderedIntSet* s) {
	if(s == NULL) {
		printf("Error: Invalid ordered set\n");
		return NULL;
	}

	// Delete the whole list except head and tail
	dllNode* current = s->head->successor;
	while (current != s->tail) {
		dllNode* temp = current;
		current = current->successor;
		free(temp); // Free each node in the list
	}

	free(s->head); // Free the head node
	free(s->tail); // Free the tail node
	free(s); // Free the set itself

	// Return NULL to indicate the set has been deleted
	return NULL;
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
enum ReturnValue addElement(DoubleLinkedList* set, int value) {

	// Pre-condition check: make sure the set is valid
	if (set == NULL) {
		printf("Error: Set is NULL\n");
		return ALLOCATION_ERROR; // Return allocation error if set is NULL
	}

	// Handle case where the set is empty (current node is at the tail)
	if (set->current == set->tail) {
		// If the set is empty, initialize it with the first element
		dllNode* newNode = (dllNode*)malloc(sizeof(dllNode));
		if (newNode == NULL) {
			printf("Error: Memory allocation failed\n");
			return ALLOCATION_ERROR; // Return allocation error if memory fails
		}
		newNode->d = value;
		newNode->predecessor = NULL;
		newNode->successor = set->tail;
		set->tail->predecessor = newNode;

		// Set the current node to the newly added node
		set->current = newNode;

		return NUMBER_ADDED;
	}

	// Now, if current is not tail, we can proceed to add an element in the appropriate order
	dllNode* currentNode = set->current;
	while (currentNode != set->tail && currentNode->d < value) {
		currentNode = currentNode->successor;
	}

	// Check if the element already exists
	if (currentNode != set->tail && currentNode->d == value) {
		return NUMBER_ALREADY_IN_SET; // Element is already in the set
	}

	// Add new node in the right place
	dllNode* newNode = (dllNode*)malloc(sizeof(dllNode));
	if (newNode == NULL) {
		printf("Error: Memory allocation failed\n");
		return ALLOCATION_ERROR; // Return allocation error if memory fails
	}

	newNode->d = value;
	newNode->successor = currentNode;
	newNode->predecessor = currentNode->predecessor;
	if (currentNode->predecessor != NULL) {
		currentNode->predecessor->successor = newNode;
	}
	currentNode->predecessor = newNode;

	return NUMBER_ADDED; // Successfully added element
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
	if (s1 == NULL || s2 == NULL) {
		printf("Error: One or both sets are NULL\n");
		return NULL;  // Or return an error code, depending on your needs
	}

	orderedIntSet* intersection = createOrderedIntSet();
	if (intersection == NULL) {
		printf("Error: Failed to create intersection set\n");
		return NULL;
	}

	// Assuming s1 and s2 are ordered and not empty, now perform intersection
	// You can use logic like this to go through the elements in both sets
	s1 = gotoHead(s1);
	s1 = gotoNextNode(s1);

	while (s1->current != s1->tail) {
		s2 = gotoHead(s2);
		s2 = gotoNextNode(s2);

		while (s2->current != s2->tail) {
			if (s1->current->d == s2->current->d) {
				// Add common element to intersection set
				insertAfter(intersection, s1->current->d);
				break;
			}
			s2 = gotoNextNode(s2);
		}

		s1 = gotoNextNode(s1);
	}

	return intersection;
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

	if (s1 == NULL || s2 == NULL) {
		printf("Error: One or both sets are NULL\n");
		return NULL;
	}

	// Check if head and tail are properly initialized in both sets
	if (s1->head == NULL || s2->head == NULL || s1->tail == NULL || s2->tail == NULL) {
		printf("Error: Set or head is NULL\n");
		return NULL;
	}

	// Create a new set for the union result
	DoubleLinkedList* uniset = createDoubleLinkedList();
	if (uniset == NULL) {
		printf("Error: Failed to create the result set\n");
		return NULL;
	}

	// Traverse both sets and perform union
	s1 = gotoHead(s1);
	s2 = gotoHead(s2);

	while (s1->current != s1->tail || s2->current != s2->tail) {
		addElement(uniset, s1->current->d);  // Add current element to the uniset
		s1 = gotoNextNode(s1);  // Move to the next node in s1
	}

	// Traverse the second set (s2)
	s2 = gotoHead(s2);  // Set the current pointer to head
	s2 = gotoNextNode(s2);  // Move to the first element of the set

	// Add all elements from s2 to uniset, avoiding duplicates
	while (s2->current != s2->tail) {
		// Get the last element in the union set (if any)
		int lastElem = uniset->tail->predecessor->d;

		// Add the element from s2 only if it's different from the last element
		if (lastElem != s2->current->d) {
			addElement(uniset, s2->current->d);  // Add current element to the uniset
		}

		s2 = gotoNextNode(s2);  // Move to the next node in s2
	}

	return uniset;  // Return the resulting union set
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
	// Check if either set is NULL
	if (s1 == NULL || s2 == NULL) {
		printf("Error: One or both sets are NULL.\n");
		return NULL;  // Exit if either set is NULL
	}

	// Check if head and tail are properly initialized in both sets
	if (s1->head == NULL || s2->head == NULL || s1->tail == NULL || s2->tail == NULL) {
		printf("Error: Set or head is NULL\n");
		return NULL;
	}

	// Create a new set to store the difference
	DoubleLinkedList* diffset = createDoubleLinkedList();
	if (diffset == NULL) {
		printf("Error: Failed to create a new ordered set for the set difference.\n");
		return NULL;  // Exit if the diffset cannot be created
	}

	// Initialize iteration on s1
	s1 = gotoHead(s1);
	s1 = gotoNextNode(s1);  // Now s1->current is at the first node

	// Iterate through all nodes in set 1
	while (s1 != NULL && s1->current != NULL && s1->current->successor != NULL) {
		int isFoundInS2 = 0;

		// Check if the element is in set 2
		s2 = gotoHead(s2);
		s2 = gotoNextNode(s2);  // Now s2->current is at the first node

		while (s2 != NULL && s2->current != NULL && s2->current->successor != NULL) {
			if (s1->current->d == s2->current->d) {
				isFoundInS2 = 1;  // Element found in set 2
				break;  // Break out of the inner loop since element is in set 2
			}
			s2 = gotoNextNode(s2);  // Move to the next node in s2
		}

		// If element not found in s2, add to the result
		if (!isFoundInS2) {
			diffset = insertAfter(diffset, s1->current->d);  // Add element to the difference set
		}

		s1 = gotoNextNode(s1);  // Move to the next node in s1
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
	if (s == NULL || s->head == NULL || s->tail == NULL) {
		printf("Error: Set is NULL\n");
		return NULL;  // Return or handle the error appropriately
	}


	// Assuming you have a valid set, iterate through its elements
	s = gotoHead(s);  // Go to head of the set
	s = gotoNextNode(s);  // Go to first element
	
	printf("{");
	while (s != NULL && s->current != NULL && s->current->successor != NULL) {
		{
		printf("%i,", s->current->d);  // Print the current element
		s = gotoNextNode(s);  // Move to the next element
	}
	printf("}\n");

	return s;  // Return the set
}
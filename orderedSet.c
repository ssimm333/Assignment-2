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



 // creates an empty ordered set (list contains no elements
 // and number of elements is set to 0).Make sure that your solution provides
 // an explicit create function.
orderedIntSet* createOrderedIntSet() {
	orderedIntSet* set = (orderedIntSet*)malloc(sizeof(orderedIntSet));
	set->head = NULL;
	set->tail = NULL;
	set->size = 0;
	return set;
}

	ReturnStatus addElement(DoubleLinkedList * s, int elem) {
		if (!s) return ALLOCATION_ERROR;

		// Create a new node 
		Node* newNode = (Node*)malloc(sizeof(Node));
		if (!newNode) return ALLOCATION_ERROR; // Bellek ayırma hatası
		newNode->data = elem;
		newNode->next = NULL;
		newNode->prev = NULL;

		// If the list in empty, add the element directly
		if (s->head == NULL) {
			s->head = newNode;
			s->tail = newNode;
			s->size++;
			return NUMBER_ADDED;
		}

		// Check the element starting from the beginning of the list 
		Node* current = s->head;
		while (current) {
			// If the element already exists in the set 
			if (current->data == elem) {
				free(newNode); // Release the new node
				return NUMBER_ALREADY_IN_SET;
			}

			// Add the element if the correct position is found 
			if (current->data > elem) {
				newNode->next = current;
				newNode->prev = current->prev;

				if (current->prev) {
					current->prev->next = newNode;
				}
				else {
					// The element is added at the beginning of the list 
					s->head = newNode;
				}

				current->prev = newNode;
				s->size++;
				return NUMBER_ADDED;
			}

			current = current->next;
		}

		// The element should be added at the end of the list 
		s->tail->next = newNode;
		newNode->prev = s->tail;
		s->tail = newNode;
		s->size++;
		return NUMBER_ADDED;
	}



	// set Intersection
	DoubleLinkedList* setIntersection(DoubleLinkedList * s1, DoubleLinkedList * s2) {

		// Create interset
		DoubleLinkedList* interset = createDoubleLinkedList();
		//Find first element of set 1
		s1 = gotoHead(s1);
		s1 = gotoNextNode(s1);

		// for each node in set1
		while (s1->current->successor != NULL) {

			//Find first element of set 2
			s2 = gotoHead(s2);
			s2 = gotoNextNode(s2);

			// For each node in set 2
			while (s2->current->successor != NULL) {

				// If set1i == set2i
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




	// set Union
	DoubleLinkedList* setUnion(DoubleLinkedList * s1, DoubleLinkedList * s2) {

		// Create uniset
		DoubleLinkedList* uniset = createDoubleLinkedList();

		//Find first element of set 1
		s1 = gotoHead(s1);
		s1 = gotoNextNode(s1);

		//for each node in set1
		while (s1->current->successor != NULL) {

			// Add node to uniset
			uniset = insertAfter(uniset, s1->current->d);

			s1 = gotoNextNode(s1);
		}



		// Find first element of set2
		s2 = gotoHead(s2);
		s2 = gotoNextNode(s2);

		// for each node in set2
		while (s2->current->successor != NULL) {


			// for each node in uniset
			while (uniset->current->successor != NULL) {

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
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

enum ReturnValue addElement(DoubleLinkedList * s, int elem) {
	// checking if its a duplicate
	dllNode* current = s->head;
	while (current!= NULL) {
		if (current->d == elem) {
			return NUMBER_ALREADY_IN_SET;
		}
		current = current->successor;
	}

	// Create a new node 
	dllNode* newNode = (dllNode*)malloc(sizeof(dllNode));
	if (!newNode) return ALLOCATION_ERROR; // Bellek ayırma hatası
	newNode->d = elem;
	newNode->successor = NULL;
	newNode->predecessor = NULL;

	// find position to add the element
	dllNode* current = s->head;
	while (current && current->d < elem) {
		current = current->successor;
	}

	// insert after current node
	if (current == NULL) {
		s->tail->successor = newNode;
		newNode->predecessor = s->tail;
		s->tail = newNode;
		s->size++;
		return NUMBER_ADDED;
	}
	else {
		current->predecessor->successor = newNode;
		newNode->predecessor = current->predecessor;
		current->predecessor = newNode;
		s->size++;
		return NUMBER_ADDED;
	}

	// The element should be added at the end of the list 

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
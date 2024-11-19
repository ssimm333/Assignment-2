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



// set Intersection
DoubleLinkedList* setIntersection(DoubleLinkedList* s1, DoubleLinkedList* s2) {
	DoubleLinkedList* interset = createDoubleLinkedList();// Create interset
	dllNode* current1 = s1->head;		//Find head of set 1
	
	
	// for each node in set1
	while (current1 != NULL) { 
		dllNode* next1 = current1->successor;

		//Find head of set 2
		dllNode* current2 = s2->head;		
		// For each node in set 2
		while (current2 != NULL) {
			dllNode* next2 = current2->successor;
			
			// If set1i == set2i
			if (current1->d == current2->d) {
				
				// add node i to interset
				interset = insertAfter(interset, current1->d);
			}
			current2 = next2;
		}
		current1 = next1;

	}
	return interset;
}




// set Union
// Create  uniset
// for each node in set1
//		for each node in set2
//			if set1i =! set2i
//				add set1i to uniset
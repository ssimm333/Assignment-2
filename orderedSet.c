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


// add set1i to interset
// set Intersection
// Create interset
// for each node in set1
//		for each node in set2
//			if set1i == set2i
//				add set1i to intset

// set Union
// Create  uniset
// for each node in set1
//		for each node in set2
//			if set1i =! set2i
//				add set1i to uniset
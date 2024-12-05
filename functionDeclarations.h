/*****************************************************************//**
 * @file	functionDeclarations.h
 * @brief	header file containing function declarations for the linked list and ordered set and other functions required for this program
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
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "enum.h"

//function declarations for the linked list
dllist* createList();
void deleteList(dllist* list);
data* getData(dllist* list);
void gotoNextNode(dllist* list);
void gotoPrevNode(dllist* list);
void gotoHead(dllist* list);
void gotoTail(dllist* list);
enum ReturnValue insertAfter(dllist* list, data newdata);
enum ReturnValue insertBefore(dllist* list, data newdata);
enum ReturnValue deleteCurrent(dllist* list);

// function declarations for the ordered set
OrderedSet* createOrderedSet();
void deleteOrderedSet(OrderedSet* set);
enum ReturnValue addElement(OrderedSet* set, data newdata);
enum ReturnValue removeElement(OrderedSet* set, int elem);
OrderedSet* setIntersection(OrderedSet* set1, OrderedSet* set2);
OrderedSet* setUnion(OrderedSet* set1, OrderedSet* set2);
OrderedSet* setDifference(OrderedSet* set1, OrderedSet* set2);

// print the list
void printToStdout(dllist* list);

void printMenu();
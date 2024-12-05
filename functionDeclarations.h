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
int test();
void bubbleSort(OrderedSet* set, int size);
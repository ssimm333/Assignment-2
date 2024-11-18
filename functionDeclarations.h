#pragma once
#include "doubleLinkedList.c"

int data;
struct Node;
struct List;
DoubleLinkedList* createDoubleLinkedList();
DoubleLinkedList* deleteDoubleLinkedList(DoubleLinkedList* list);
DoubleLinkedList* getData(DoubleLinkedList* list);
DoubleLinkedList* gotoNextNode(DoubleLinkedList* list);
DoubleLinkedList* gotoPreviousNode(DoubleLinkedList* list);
DoubleLinkedList* gotoHead(DoubleLinkedList* list);
DoubleLinkedList* gotoTail(DoubleLinkedList* list);
DoubleLinkedList* insertAfter(newdata);
DoubleLinkedList* insertBefore(newdata);
DoubleLinkedList* deleteCurrentNode(DoubleLinkedList* list);
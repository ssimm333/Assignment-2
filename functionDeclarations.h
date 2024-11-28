#pragma once

// Typedef for data type
typedef int data;

// Forward declarations of structs
typedef struct Node {
    data d;
    struct Node* successor;  // Pointer to the next node
    struct Node* predecessor; // Pointer to the previous node
} dllNode;

typedef struct List {
    dllNode* head;    // Pointer to the head node
    dllNode* tail;    // Pointer to the tail node
    dllNode* current; // Pointer to the current node
    int size;
} DoubleLinkedList;

typedef struct orderedIntSet {
    dllNode* head;
    dllNode* tail;
    int size;
}orderedIntSet;

enum ReturnValue {
    NUMBER_ALREADY_IN_SET,
    NUMBER_NOT_IN_SET,
    NUMBER_ADDED,
    NUMBER_REMOVED,
    ALLOCATION_ERROR
};

DoubleLinkedList* createDoubleLinkedList();
DoubleLinkedList* deleteDoubleLinkedList(DoubleLinkedList* list);
DoubleLinkedList* getData(DoubleLinkedList* list);
DoubleLinkedList* gotoNextNode(DoubleLinkedList* list);
DoubleLinkedList* gotoPreviousNode(DoubleLinkedList* list);
DoubleLinkedList* gotoHead(DoubleLinkedList* list);
DoubleLinkedList* gotoTail(DoubleLinkedList* list);
DoubleLinkedList* insertAfter(DoubleLinkedList* list, int newdata);
DoubleLinkedList* insertBefore(DoubleLinkedList* list, int newdata);
DoubleLinkedList* deleteCurrentNode(DoubleLinkedList* list);
orderedIntSet* createOrderedIntSet();
orderedIntSet* deleteOrderedIntSet(orderedIntSet* s);
enum ReturnValue addElement(DoubleLinkedList* s, int elem);
enum ReturnValue removeElement(DoubleLinkedList* s, int elem);

DoubleLinkedList* setIntersection(DoubleLinkedList* s1, DoubleLinkedList* s2);
DoubleLinkedList* setUnion(DoubleLinkedList* s1, DoubleLinkedList* s2);
DoubleLinkedList* setDifference(DoubleLinkedList* s1, DoubleLinkedList* s2);
orderedIntSet* printToStdout(orderedIntSet* s);

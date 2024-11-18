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
} DoubleLinkedList;

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
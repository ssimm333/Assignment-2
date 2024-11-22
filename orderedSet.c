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

ReturnStatus addElement(DoubleLinkedList* s, int elem) {
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
            } else {
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

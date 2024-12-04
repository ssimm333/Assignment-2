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

int main() {

	// make SetsArray, and set all elements to NULL
	orderedIntSet* SetsArray[10];
	for (int i = 0; i < 10; i++) {
		SetsArray[i] = NULL;
	}

	int choice;

	// print main menu
	printf("\n");
	printf("\nChoose from the following:");
	printf("\n1) Create an empty Ordered Set.\n");
	printf("\n2) Delete the current Ordered Set.\n");
	printf("\n3) Add Elements to Ordered Set.\n");
	printf("\n4) Remove elements from Ordered Set.\n");
	printf("\n5) Set Intersection.\n");
	printf("\n6) Set Union.\n");
	printf("\n7) Set Difference.\n");
	printf("\n8) Terminate Program..\n");

	// want this application to run until the user terminates it, hence a do while loop
	do {
		

		// choosing a function
		printf("\nYour choice: ");
		scanf_s("%i", &choice);

		// index choice
		int index;
		int input;

		int index1;
		int index2;
		int index3;

		// switch statement
		switch (choice) {

			case 1:
				// 1) create an empty Ordered Set

				// prompts user to enter the index for the new array in SetsArray
				printf("\nPlease enter index (0 - 9) for set to be created: ");
				// read index
				scanf_s("%d", &index);
				
				// create an empty Ordered Set at index in SetsArray specified by user
				// if index is NULL, create an empty Ordered Set
				if (SetsArray[index] == NULL) {
					SetsArray[index] = createOrderedIntSet();
					printf("\nSet at index %d created\n", index);
				}
				else {
					// if index is not NULL, print error
					printf("\nEmpty Ordered Set already exists at index %d in SetsArray.\n", index);
				}
				break;

			case 2:

				// 2) delete the current Ordered 

				// prompts user to enter the index for the new array to be deleted
				printf("\nEnter index (0 - 9) for set to be deleted: ");
				// read index
				scanf_s("%d", &index);

				SetsArray[index] = deleteOrderedIntSet(SetsArray[index]);

				printf("Set at index %d deleted successfully.\n", index);
				break;

			case 3:
				// 3) add Elements to Ordered Set
				// prompts user to enter the index in SetsArray of the set to be used (reads from stdin).
				printf("\nEnter index (0 - 9) for set to be used: ");

				// read index
				scanf_s("%d", &index);

				printf("\nPlease enter element (enter value <0 to stop):");

				// Then, reads numbers continuously from stdin and uses the function addElement() to attempt to add the number to the Ordered Set.
				// This process will stop if a negative number is entered.
				scanf_s("%d", &input);
				while (input >= 0) {
					enum addElementResult result = addElement(SetsArray[index], input);

					if (result == NUMBER_ADDED) {
						printf("NUMBER ADDED\n");
					}
					else if (result == NUMBER_ALREADY_IN_SET) {
						printf("NUMBER ALREADY IN SET\n");
					}
					else if (result == ALLOCATION_ERROR) {
						printf("Error: Memory allocation failed\n");
					}

					// Continue reading input until a negative number is entered.
					scanf_s("%d", &input);
				}

				// Finally, it will call printToStdout() to print the resulting set
				// (after the last element has been added) to stdout to the screen.
				printf("Final ordered set = ");
				printToStdout(SetsArray[index]);
				break;
			

			case 4:

				// 4) Remove elements from Ordered Set
				//		this function first prompts the user to enter the index in SetsArray of the set to be used
				//		(that is, it reads it from stdin).
				printf("\nEnter index (0 - 9) for set to be used: ");
				scanf_s("%d", &index);
				
				//		Then it reads numbers continously from stdin and uses function removeElement() to attempt 
				//		to remove the number from the Ordered Set.
				do {
					removeElement(SetsArray[index], input);
					scanf_s("%d", &input);
					enum removeElementResult result = removeElement(SetsArray[index], input);
				} while (input >= 0);

				//		This process will stop if a negative number is entered. For each number it will report whether 
				//		removeElemenmt() returned NUMBER REMOVED or NUMBER NOT IN SET.At the end, it will call 
				//		printToStdout() to print the resulting set(after the last element has been removed) to stdout.
				printToStdout(SetsArray[index]);
				break;

			case 5:

				// 5) Set Intersection.
				//		This option prompts the user to enter three indices i1, i2 and i3 for three sets in SetsArray.
				printf("\nEnter three indeces i1, i2 and i3 to be used: ");
				scanf_s("%d %d %d", &index1, &index2, &index3);

				// Perform the intersection of sets i1 and i2
				orderedIntSet* intersection = setIntersection(SetsArray[index1], SetsArray[index2]);

				// Store the resulting set in SetsArray at index i3
				SetsArray[index3] = intersection;

				// Print the resulting intersection set
				printf("Intersection of set %d and set %d: ", index1, index2);
				printToStdout(intersection);
				break;

			case 6:

				// 6) Set Union
				// This option prompts the user to enter three indices i1, i2, and i3 for three sets in SetsArray
				printf("\nEnter three indices i1, i2 and i3 to be used: ");
				scanf_s("%d %d %d", &index1, &index2, &index3);

				// Check if the sets at indices i1 and i2 exist and are properly initialized
				if (SetsArray[index1] == NULL || SetsArray[index2] == NULL) {
					if (SetsArray[index1] == NULL) {
						printf("Error: No ordered set available at index %d\n", index1);
					}
					if (SetsArray[index2] == NULL) {
						printf("Error: No ordered set available at index %d\n", index2);
					}
				}
				else {
					// Call setUnion to obtain the union of sets i1 and i2
					SetsArray[index3] = setUnion(SetsArray[index1], SetsArray[index2]);

					// Print the resulting set
					if (SetsArray[index3] != NULL) {
						printf("Union of sets %d and %d: ", index1, index2);
						printToStdout(SetsArray[index3]);
						printf("\n");
					}
					else {
						printf("Error: Failed to compute set union\n");
					}
				}

				break;

			case 7:
				// 7) Set Difference
				printf("\nEnter two indices i1 and i2 to perform set difference (i1 - i2): ");
				scanf_s("%d %d", &index1, &index2);

				// Check if sets at these indices exist
				if (SetsArray[index1] == NULL || SetsArray[index2] == NULL) {
					// Print error if either of the sets is NULL
					if (SetsArray[index1] == NULL) {
						printf("Error: No ordered set available at index %d. Cannot perform set difference.\n", index1);
					}
					if (SetsArray[index2] == NULL) {
						printf("Error: No ordered set available at index %d. Cannot perform set difference.\n", index2);
					}
				}
				else {
					// Call setDifference to perform the set difference
					DoubleLinkedList* resultSet = setDifference(SetsArray[index1], SetsArray[index2]);

					// If resultSet is not NULL, print the resulting set
					if (resultSet != NULL) {
						printf("Set difference result (set%d - set%d): ", index1, index2);
						printToStdout(resultSet);
						printf("\n");
					}
					else {
						printf("Error: Set difference operation failed.\n");
					}
				}
				break;

			case 8:

				// 8) Terminate the program
				printf("\nTerminating program\n");
				return EXIT_SUCCESS;

			
			default:
				printf("\nInvalid input\n");
				break;
		}
		// clear buffer
		scanf_s("*c");

		// user input
		scanf_s("*c");

	} while (EXIT_FAILURE);
}

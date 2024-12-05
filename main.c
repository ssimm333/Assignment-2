/*****************************************************************//**
 * @file	main.c
 * @brief	main file used to implement the text menu driven application
 *
 * @author Stanislav Simanovich		23366109
 * @author Calum Breen				23368357
 * @author Emilia Hildebrandt		23356421
 * @author Tiernan O'Shaughnessy	23356642
 * @author Jordi Roca				24277215
 * @author Bengisu Fansa			24221104
 *
 *
 * @date 05 December 2024
 *********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "functionDeclarations.h"
#include "enum.h"
#define MAX_SETS 10

/**
 * @brief main function.
 * 
 * Prints the menu and takes user input.
 * 
 * @return EXIT_SUCCESS upon completion (0)
 */
int main() {
	OrderedSet* setsArray[MAX_SETS] = { NULL };

	printMenu();

	int choice, index, input, index1, index2, index3;

	do {
		printf("\nYour choice: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("\nPlease enter index (0 - 9) for set to be created: ");
			scanf_s("%d", &index);
			if (setsArray[index] == NULL) {
				setsArray[index] = createOrderedSet();
				printf("\nSet at index %d created\n", index);
			}
			else {
				printf("\nEmpty Ordered Set already exists at index %d in SetsArray.\n", index);
			}
			break;

		case 2:
			printf("\nEnter index (0 - 9) for set to be deleted: ");
			scanf_s("%d", &index);
			deleteOrderedSet(setsArray[index]);
			setsArray[index] = NULL;
			printf("\nSet at index %d deleted\n", index);
			break;

		case 3:
			printf("\nEnter index (0 - 9) for set to be used: ");
			scanf_s("%d", &index);

			while (scanf_s("%d", &input) && input >= 0) {
				printf("\nPlease enter element (enter value <0 to stop): Result:  ");
				if (addElement(setsArray[index], input) == NumberAdded) {
					printf("OK");
				}
				else {
					printf("NUMBER ALREADY IN SET");
				}
			}
			printf("\nFinal ordered set = ");
			printToStdout(setsArray[index]);
			break;

		case 4:
			printf("\nEnter index (0 - 9) for set to be used: ");
			scanf_s("%d", &index);
			printf("\nEnter elements to remove (negative number to stop): ");
			while (scanf_s("%d", &input) && input >= 0) {
				removeElement(setsArray[index], input);
				printf("\nPlease enter element (enter value <0 to stop): Result:  ");
				if (removeElement == NumberRemoved) {
					printf("NUMBER REMOVED");
				}
				else {
					printf("NUMBER NOT IN SET");
				}
			}
			printf("\nFinal ordered set = ");
			printToStdout(setsArray[index]);
			break;

		case 5:
			printf("\nEnter three indices i1, i2 and i3 to be used: ");
			scanf_s("%d %d %d", &index1, &index2, &index3);
			if (setsArray[index1] == NULL) {
				printf("\nNo ordered set available at index %d. Cannot perform intersection.\n", index1);
				break;
			}
			if (setsArray[index2] == NULL) {
				printf("\nNo ordered set available at index %d. Cannot perform intersection.\n", index2);
				break;
			}

			setsArray[index3] = setIntersection(setsArray[index1], setsArray[index2]);
			printf("\nSet Intersection = ");
			printToStdout(setsArray[index3]);
			break;

		case 6:
			printf("\nEnter three indices i1, i2 and i3 to be used: ");
			scanf_s("%d %d %d", &index1, &index2, &index3);
			if (setsArray[index1] == NULL) {
				printf("\nNo ordered set available at index %d. Cannot perform set Union.\n", index1);
				break;
			}
			if (setsArray[index2] == NULL) {
				printf("\nNo ordered set available at index %d. Cannot perform set Union.\n", index2);
				break;
			}
			setsArray[index3] = setUnion(setsArray[index1], setsArray[index2]);
			printf("\nSet Union = ");
			printToStdout(setsArray[index3]);
			break;

		case 7:
			printf("\nEnter three indices i1, i2 and i3 to be used: ");
			scanf_s("%d %d %d", &index1, &index2, &index3);
			if (setsArray[index1] == NULL) {
				printf("\nNo ordered set available at index %d. Cannot perform set difference.\n", index1);
				break;
			}
			if (setsArray[index2] == NULL) {
				printf("\nNo ordered set available at index %d. Cannot perform set difference.\n", index2);
				break;
			}
			setsArray[index3] = setDifference(setsArray[index1], setsArray[index2]);
			printf("\nSet Difference = ");
			printToStdout(setsArray[index3]);
			break;

		case 8:
			printf("\nTerminating program\n");
			return EXIT_SUCCESS;

		default:
			printf("\nInvalid input\n");
			break;
		}
	} while (1);

	return EXIT_FAILURE;
}
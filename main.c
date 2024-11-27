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

				deleteOrderedIntSet(SetsArray[index]);
				break;

			case 3:

				// 3) add Elements to Ordered Set
				//		prompts user to enter the index in SetsArray of the set to be used
				//		(reads from stdin).
				printf("\nEnter index (0 - 9) for set to be used: ");

				// read index
				scanf_s("%d", &index);

				
				//		Then, reads numbers continunously form stdin and uses the function 
				//		addElement() to attempt to add the number to the Ordered Set.
				//		This process will stop if a negative number is entered	
				scanf_s("%d", &input);
				while (input >= 0) {
					addElement(SetsArray[index], input);
					scanf_s("%d", &input);

				//		For each numberm it will report whether addELement() returned NUMBER_ADDED
				//		or NUMBER_ALREADY_IN_SET. 
				enum addElementResult result = addElement(SetsArray[index], input);
				}
				
				printToStdout(SetsArray[index]);
				//		Finally, it will call printToStdout() to print the resulting set
				//		(after the last element has been added) to stdout to the screen.

			case 4:

				// 4) Remove elements from Ordered Set
				//		this function first prompts the user to enter the index in SetsArray of the set to be used
				//		(that is, it reads it from stdin).
				//		
				//		Then it reads numbers continously from stdin and uses function removeElement() to attempt 
				//		to remove the number from the Ordered Set.
				// 
				//		This process will stop if a negative number is entered.For each number it will report whether 
				//		removeElemenmt() returned NUMBER REMOVED or NUMBER NOT IN SET.At the end, it will call 
				//		printToStdout() to print the resulting set(after the last element has been removed) to stdout.

				break;

			case 5:

				// 5) Set Intersection. 
				//		This option prompts the user to enter three indices i1, i2 and i3 for three sets in SetsArray.
				//		
				//		Then it calls function setIntersection(s1, s2) to obtain the intersetion of sets i1 and i2 
				//		and stores the resulting set at index i3.Finally, it prints the resulting set to stdout.
				
				break;

			case 6:

				// 6) Set Union
				//		This option prompts the user to enter three indices i1, i2 and i3 for three sets in SetsArray.
				// 
				//		Then it calls function setUnion(s1, s2) to obtain the union of sets i1 and i2 and stores 
				//		the resulting set at index i3.
				// 
				//		Finally, it prints the resulting set to stdout.
				
				break;

			case 7:

				// 7) Set Difference. 
				//		This option prompts the user to enter three indices i1, i2 and i3 for three sets in SetsArray.
				// 
				//		Then it calls function setDifference(s1,s2) to obtain the difference of sets i1 and i2
				//		(make sure to obtain i1 − i2 and not i2 − ii) and stores the resulting set at index i3.
				// 
				//		Finally, it prints the resulting set to stdout.

				break;

			case 8:

				// 8) Terminate the program
				printf("\nTerminating program\n");
				return EXIT_SUCCESS;

			
			default:
				printf("\nInvalid input\n");
				break;
		}

		printf("\nPress Enter to continue\n");

		// clear buffer
		scanf_s("*c");

		// user input
		scanf_s("*c");

	} while (EXIT_FAILURE);
}

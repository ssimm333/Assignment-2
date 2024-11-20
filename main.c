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
	
	// 1) create an empty Ordered Set
	//		prompts user to enter the index for the new array in SetsArray

	// 2) delete the current Ordered Set
	// 		prompts user to enter the index for the new array in SetsArray

	// 3) add Elements to Ordered Set
	//		prompts user to enter the index in SetsArray of the set to be used
	//		(reads from stdin).
	// 
	//		Then, reads numbers continunously form stdin and uses the function 
	//		addElement() to attempt to add the number to the Ordered Set.
	//		
	//		This process will stop if a negative number is entered. 
	//		
	//		For each numberm it will report whether addELement() returned NUMBER_ADDED
	//		or NUMBER_ALREADY_IN_SET. 
	//		
	//		Finally, it will call printToStdout() to print the resulting set
	//		(after the last element has been added) to stdout to the screen.
			
	// 4)  remove elements from Ordered Set
	//		this function first prompts the user to enter the index in SetsArray of the set to be used
	//		(that is, it reads it from stdin).
	//		
	//		Then it reads numbers continously from stdin and uses function removeElement() to attempt 
	//		to remove the number from the Ordered Set.
	// 
	//		This process will stop if a negative number is entered.For each number it will report whether 
	//		removeElemenmt() returned NUMBER REMOVED or NUMBER NOT IN SET.At the end, it will call 
	//		printToStdout() to print the resulting set(after the last element has been removed) to stdout.

	// 5) Set Intersection. 
	//		This option prompts the user to enter three indices i1, i2 and i3 for three sets in SetsArray.
	//		
	//		Then it calls function setIntersection(s1, s2) to obtain the intersetion of sets i1 and i2 
	//		and stores the resulting set at index i3.Finally, it prints the resulting set to stdout.

	// 6) Set Union
	//		This option prompts the user to enter three indices i1, i2 and i3 for three sets in SetsArray.
	// 
	//		Then it calls function setUnion(s1, s2) to obtain the union of sets i1 and i2 and stores 
	//		the resulting set at index i3.
	// 
	//		Finally, it prints the resulting set to stdout.

	// 7) Set Difference. 
	//		This option prompts the user to enter three indices i1, i2 and i3 for three sets in SetsArray.
	// 
	//		Then it calls function setDifference(s1,s2) to obtain the difference of sets i1 and i2
	//		(make sure to obtain i1 − i2 and not i2 − ii) and stores the resulting set at index i3.
	// 
	//		Finally, it prints the resulting set to stdout.

	// 8) Terminate the program
	return EXIT_SUCCESS;
}

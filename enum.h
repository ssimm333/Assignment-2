/*****************************************************************//**
 * @file	enum.h
 * @brief	Enumeration for Return values of double linked list and ordered set functions
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

/**
 * @brief Enumeration for Return values.
 * 
 * Used to indicate the success or failure of an operation and 
 * to provide additional information about the operation, which is specific to the function.
 */
typedef enum ReturnValue {
	ok,						// no error	
	NumberInSet,			// the number is in the set already
	NumberNotInSet,			// the number is not in the set
	NumberAdded,			// the number was added to the set
	NumberRemoved,			// the number was removed from the set
	AllocationError			// memory allocation error
};

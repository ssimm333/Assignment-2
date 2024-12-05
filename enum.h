#pragma once

// enumeration for Return values of functions
typedef enum ReturnValue {
	ok,						// no error	
	NumberInSet,			// the number is in the set already
	NumberNotInSet,			// the number is not in the set
	NumberAdded,			// the number was added to the set
	NumberRemoved,			// the number was removed from the set
	AllocationError			// memory allocation error
};

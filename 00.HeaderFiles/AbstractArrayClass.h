#ifndef __ABSTRACTARRAY__H
#define __ABSTRACTARRAY_H
//---------------------------------------------------------------- START AbstractArrayClass
#include <iostream>
#include <exception>
// Base Exception Class for all ArrayClass-type Exceptions
class ArrayException : public std::exception {};
// Allocation of free store using "new" failed.
class ArrayMemoryException : public ArrayException {};
// Element could not be accessed outside the bounds of the array
class ArrayBoundsException : public ArrayException {};

// Array ADT:	createArray(n);	creates an array of size 'n'
//				getElement(k);	accesses the element at index 'k'
//				putElement(k, e);	assigns 'e' at position 'i'
//				getSize();		returns the capacity of the array
// AbstractArrayClass defines the operations expected for all implementations of Array data structures.
template<typename DT>
class AbstractArrayClass
{
	// Prints each element seperated by commas
	friend std::ostream& operator<< (std::ostream& s, const AbstractArrayClass<DT>& ac)
	{
		size_t n = ac.size() - 1;
		if (n == -1) return s << "{}";
		s << "{";
		for (size_t i = 0; i < n; i++) s << ac[i] << ",";
		return s << ac[n] << "}";
	}
public:
	// returns number of elements that can be stored by the array
	virtual size_t size() const = NULL;
	// returns the element at index k by reference (repurpose of getElement(i) and putElement(k, e))
	virtual DT& operator[] (size_t) const = NULL;
};

//---------------------------------------------------------------- END AbstractArrayClass
#endif /* __ABSTRACTARRAY__H */

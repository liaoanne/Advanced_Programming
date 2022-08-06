// ArrayList.h
// ArrayList class definition.
// Member functions are defined in ArrayList.cpp
// Created by Anne Liao (40215517) on May 14, 2022.

#ifndef ARRAYLIST_H_ // prevent multiple inclusions of header
#define ARRAYLIST_H_
#include <iostream>

// A class representing a simple list of integers
class ArrayList {
public:
	ArrayList(); // Default constructor, creates a list of capacity=1, and used=0

	ArrayList(const ArrayList& array); // Copy constructor
	ArrayList(ArrayList&& array) noexcept; // Move constructor
	ArrayList& operator=(const ArrayList& rhs); // Copy assignment operator
	ArrayList& operator=(ArrayList&& rhs) noexcept; // Move assignment operator
	virtual ~ArrayList(); // Destructor (and a virtual one in this example)

	bool empty() const;	// Determines whether used equals zero
	bool full() const; // Determines whether used equals capacity
	int size() const; // Returns used
	void pushBack(int x); // Inserts x at position used and then increments used by 1
	bool contains(int x) const; // Determines whether x occurs in the list
	bool get(int position, int& value) const; // Returns false if position is out of range; otherwise, places the value stored at position in the reference parameter value and then returns true
	int getCapacity() const; // Returns the allocated capacity of this list
	void print(std::ostream& sout) const; // Prints the numbers in the list to the sout stream, separating them by a comma followed by a space

private:
	int* pArray{}; // Pointer to a dynamically allocated array of integers
	int capacity{}; // Allocated capacity of the array, starting at 1 and doubling as needed
	int used; // The number of array elements currently in use, also the position of the first free slot in the array

	void resize(); // Double the current capacity of the list
};

// Overload print stream
inline std::ostream& operator<<(std::ostream& sout, const ArrayList& list) {
	list.print(sout);
	return sout;
}
#endif
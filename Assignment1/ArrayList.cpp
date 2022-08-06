// ArrayList.cpp
// ArrayList class member-function definitions.
// Created by Anne Liao (40215517) on May 14, 2022.

#include "ArrayList.h" // include definition of class ArrayList from ArrayList.h

/** Constructors */

// Default constructor, creates a list of capacity=1, and used=0
ArrayList::ArrayList()
	: capacity{ 1 }, used{ 0 }, pArray{ new int[1] {} } { // member init
	// empty body
}

// Copy constructor
ArrayList::ArrayList(const ArrayList& array)
	: ArrayList{} {
	// copy array data to this
	for (int i{}; i < array.capacity; ++i) {
		pushBack(array.pArray[i]);
	}
	capacity = array.capacity;
	used = array.used;
}

// Move constructor
ArrayList::ArrayList(ArrayList&& array) noexcept 
	: pArray{ array.pArray }, capacity{ array.capacity }, used{ array.used } { // reassign array data to this
	// set array data to default data
	array.pArray = nullptr;
	array.capacity = 0;
	array.used = 0;
}

/** Assignment operator overloading */

// Copy assignment operator
ArrayList& ArrayList::operator=(const ArrayList& rhs) {
	if (&rhs != this) {
		// delete original array data
		delete[] pArray;

		// copy rhs data to this
		capacity = rhs.capacity;
		used = rhs.used;
		pArray = new int[capacity] {};
		for (int k{}; k < capacity; ++k) {
			pArray[k] = rhs.pArray[k];
		}
	}
	return *this;
}

// Move assignment operator
ArrayList& ArrayList::operator=(ArrayList&& rhs) noexcept {
	if (&rhs != this) {
		// delete original array data
		delete[] pArray;
		
		// reassign rhs data to this
		pArray = rhs.pArray;
		capacity = rhs.capacity;
		used = rhs.used;

		// set rhs data to default data
		rhs.pArray = nullptr;
		rhs.capacity = 0;
		rhs.used = 0;
	}
	return *this;
}

/** Destructor */

// Destructor (and a virtual one in this example)
ArrayList::~ArrayList() {
	delete[] pArray;
	capacity = 0;
	used = 0;
}

/** Public class member-function defintions */

// Determines whether used equals zero
bool ArrayList::empty() const {
	return used == 0;
}

// Determines whether used equals capacity
bool ArrayList::full() const {
	return used == capacity;
}

// Returns used
int ArrayList::size() const {
	return used;
}

// Inserts x at position used and then increments used by 1
void ArrayList::pushBack(int x) {
	// resize the array if it is full
	if (full()) {
		resize();
	}
	pArray[used] = x;
	++used;
}

// Determines whether x occurs in the list
bool ArrayList::contains(int x) const {
	for (int i{}; i < capacity; ++i) {
		if (pArray[i] == x) {
			return true;
		}
	}
	return false;
}

// Returns false if position is out of range; 
// otherwise, places the value stored at position in the reference parameter value and then returns true
bool ArrayList::get(int position, int& value) const {
	if (position > capacity - 1) {
		return false;
	}
	else {
		value = pArray[position];
		return true;
	}
}

// Returns the allocated capacity of this list
int ArrayList::getCapacity() const {
	return capacity;
}

// Prints the numbers in the list to the sout stream, separating them by a comma followed by a space
void ArrayList::print(std::ostream& sout) const {
	for (int i{}; i < used; ++i) {
		if (i == used - 1) {
			sout << pArray[i]; // print the last number without a comma and space at the end
		}
		else {
			sout << pArray[i] << ", ";
		}
	}
}

/** Private class member-function defintions */

// Double the current capacity of the list
void ArrayList::resize() {
	int* pArrayTemp{ new int[capacity * 2] {} }; // initiate a new dynamic array
	
	// copy the old values to the new array
	for (int i{}; i < capacity; ++i) {
		pArrayTemp[i] = pArray[i];
	}

	delete[] pArray; // delete old array
	pArray = pArrayTemp; // assign the temp pointer to the original
	pArrayTemp = nullptr; // set the temp pointer to null
	capacity *= 2;
}
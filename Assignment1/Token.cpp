// Token.cpp
// Token class member-function definitions.
// Created by Anne Liao (40215517) on May 14, 2022.

#pragma warning(disable : 4996)
#include <cstring>
#include <iomanip>

#include "Token.h" // include definition of class Token from Token.h
#include "ArrayList.h" // include definition of class ArrayList from ArrayList.h

/** Constructors */

// Normal constructor, creates a new token using the supplied C-string and line number
Token::Token(const char* cstr, int line_num)
	: cstr{ new char[strlen(cstr) + 1] {} }, frequency{ 0 }, number_list{} {
	strcpy(this->cstr, cstr);

	// Check if this is a call for a new object or call from copy constructor
	if (line_num != -1) {
		Token::addLineNumber(line_num);
	}
}

// Copy constructor
Token::Token(const Token& token) 
	: Token{token.cstr, -1} { // create a new Token object with negative line number as indicator for copy constructor call
	// copy token data to this
	strcpy(cstr, token.cstr);
	frequency = token.frequency;
	number_list = token.number_list;
}

// Move constructor
Token::Token(Token&& token) noexcept
	: cstr{ token.cstr }, frequency{ token.frequency }, number_list{ std::move(token.number_list) } { // reassign token data to this
	// set token data to default data
	token.cstr = nullptr;
	token.frequency = 0;
	// token.number_list will go out of scope and be deleted by ArrayList destructor
}

/** Assignment operator overloading */

// Copy assignment operator
Token& Token::operator=(const Token& rhs) {
	if (&rhs != this) {
		// delete original string data
		delete[] cstr;

		// copy rhs data to this
		frequency = rhs.frequency;
		number_list = rhs.number_list;
		cstr = new char[rhs.size() + 1] {};
		strcpy(cstr, rhs.cstr);
	}
	return *this;
}

// Move assignment operator
Token& Token::operator=(Token&& rhs) noexcept {
	if (&rhs != this) {
		// delete original string data
		delete[] cstr;

		// reassign rhs data to this
		cstr = rhs.cstr;
		frequency = rhs.frequency;
		number_list = std::move(rhs.number_list);

		// set rhs data to default data
		rhs.cstr = nullptr;
		rhs.frequency = 0;
		// rhs.number_list will go out of scope and be deleted by ArrayList destructor
	}
	return *this;
}

/** Destructor */

// Destructor (and a virtual one in this example)
Token::~Token() {
	delete[] cstr;
	frequency = 0;
}

/** Public class member-function defintions */

// Returns a constant pointer to this token's cstr
const char* Token::c_str() const {
	return cstr;
}

// Adds line_num to the end of this token's number list
void Token::addLineNumber(int line_num) {
	if (!number_list.contains(line_num)) {
		number_list.pushBack(line_num);
	}
	++frequency;
}

// Returns the length of this token's cstr
size_t Token::size() const {
	return strlen(cstr);
}

// Prints this token's cstr followed by its number_list
void Token::print(std::ostream& sout) const {
	// check if cstr is set to a nullptr before printing it
	if (cstr) {
		sout << std::setw(16) << cstr << "  (" << frequency << ") " << number_list;
	}
	else {
		sout << std::setw(16) << "" << "  (" << frequency << ") " << number_list;
	}
}

// Returns this token's list of line numbers
const ArrayList& Token::getNumberList() const {
	return this->number_list;
}

// Returns -1, 0, or 1, depending on whether this token's cstr is less than, equal to, or greater than aToken's cstr
int Token::compare(const Token& aToken) const {
	return strcmp(this->cstr, aToken.cstr);
}

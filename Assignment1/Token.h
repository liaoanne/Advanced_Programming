// Token.h
// Token class definition.
// Member functions are defined in Token.cpp
// Created by Anne Liao (40215517) on May 14, 2022.

#ifndef TOKEN_H_ // prevent multiple inclusions of header
#define TOKEN_H_
#include <iostream>

#include "ArrayList.h"

// A class representing a token
class Token {
public:
	Token(const char* cstr, int line_num); // Normal constructor, creates a new token using the supplied C-string and line number
	Token() = delete; // Default constructor =delete

	Token(const Token& token); // Copy constructor
	Token(Token&& token) noexcept; // Move constructor
	Token& operator=(const Token& rhs); // Copy assignment operator
	Token& operator=(Token&& rhs) noexcept; // Move assignment operator
	virtual ~Token(); // Destructor (and a virtual one in this example)

	const char* c_str() const; // Returns a constant pointer to this token's cstr
	void addLineNumber(int line_num); // Adds line_num to the end of this token's number list
	size_t size() const; // Returns the length of this token's cstr
	void print(std::ostream& sout) const; // Prints this token's cstr followed by its number_list
	const ArrayList& getNumberList() const; // Returns this token's list of line numbers
	int compare(const Token& aToken) const; // Returns -1, 0, or 1, depending on whether this token's cstr is less than, equal to, or greater than aToken's cstr

private:
	char* cstr; // Pointer to a dynamically allocated array of characters storing the characters in this token
	int frequency; // The number of occurences of this token
	ArrayList number_list; // The list of line numbers associated with this token
};

// Overload print stream
inline std::ostream& operator<<(std::ostream& sout, const Token& tok) {
	tok.print(sout);
	return sout;
}
#endif
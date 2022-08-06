// Token.cpp
// Token class member-function definitions.
// Created by Anne Liao (40215517) on June 12, 2022.
// Last modified on June 14, 2022.

#include <iomanip>

#include "Token.h" // include definition of class Token from Token.h

/** Constructors */

// Sets the frequency count to 1, initializes the token text, and inserts line_number at the end of the line_number_list.
Token::Token(string text, size_t line_number) 
	: text{ text }, frequency{ 1 } {
	push_back_line_number(line_number);
}

/** Public class member-function defintions */

// Compares this and other token texts using std::string's compare
int Token::compare(const Token& other) const {
	return this->text.compare(other.text);
}

// Prints this token's text, frequency, and list of line numbers
void Token::print(std::ostream& out) const {
	out << std::setw(16) << text << "  (" << frequency << ") ";

	for (auto i : line_number_list) {
		out << i << " ";
	}
}

// Returns a copy of this token's text
// TODO : NOT BEING USED
string Token::get_token_text() const {
	return text;
}

// Returns this token's frequency
int Token::get_frequency() const {
	return static_cast<int>(frequency);
}

// Returns a copy of this token's list of line numbers
// TODO : NOT BEING USED
vector<size_t> Token::get_number_list() const {
	return line_number_list;
}

// Increments this token's frequency
void Token::increment_frequency() {
	++frequency;
}

// Add a specific line number to this token's list of line numbers; only if the specified line number is not in the list
void Token::push_back_line_number(size_t lineNum) {
	// check if lineNum is already in the line_number_list
	//for (auto i : line_number_list) {
	//	if (lineNum == i) {
	//		return;
	//	}
	//}

	// check if lineNum is already in the line_number_list
	// this method is O(1). it works because we go through each line of the file from top to bottom,
	// so we only need to check whether the last number in line_number_list is the same as the one we are currently adding
	if (!line_number_list.empty()) {
		if (line_number_list.back() == lineNum) return;
	}

	// not in the list, add the line number to the end of the list
	line_number_list.push_back(lineNum);
}
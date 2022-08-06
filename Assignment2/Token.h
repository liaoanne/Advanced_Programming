// Token.h
// Token class definition.
// Member functions are defined in Token.cpp
// Created by Anne Liao (40215517) on June 12, 2022.
// Last modified on June 14, 2022.

#ifndef TOKEN_H_
#define TOKEN_H_

#include <iostream>
#include <forward_list>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Token {
private:
	string text; // This token's text
	size_t frequency; // This token's frequency at construction
	vector<size_t> line_number_list; // This token's list of associated line numbers
public:
	Token(string text, size_t line_number); // A normal constructor
	Token() = delete; // Disables default construction
	
	Token(const Token& source) = default; // Copy ctor
	Token(Token&& source) = default; // Move ctor
	Token& operator=(const Token& rhs) = default; // Copy op=
	Token& operator=(Token&& rhs) = default; // Move op=
	~Token() = default; // Dtor

	int compare(const Token& other) const; // Compares this and other token texts using std::string's compare
	void print(std::ostream& out) const; // Prints this token's text, frequency, and list of line numbers
	string get_token_text() const; // Returns a copy of this token's text
	int get_frequency() const; // Returns this token's frequency
	vector<size_t> get_number_list() const; // Returns a copy of this token's list of line numbers
	size_t length() const { return text.length(); }; // Returns the length of this token's text
	void increment_frequency(); // Increments this token's frequency
	void push_back_line_number(size_t lineNum); // Add a specific line number to this token's list of line numbers; only if the specified line number is not in the list
};

// Overload print stream
inline std::ostream& operator<<(std::ostream& out, const Token& tok) {
	tok.print(out);
	return out;
}

// Overload < to use compare
inline bool operator<(const Token& t1, const Token& t2) {
	if (t1.compare(t2) < 0) return true;
	return false;
}

// Compares two Token text lengths
inline bool isShorter(const Token& first, const Token& second) {
	if (first.length() < second.length()) return true;
	if (first.length() > second.length()) return false;
	// since the two supplied tokens are of the same length, we order them lexicography
	if (first.compare(second) < 0) return true;
	return false;
}

// Compares two Token freqenecies
inline bool isLessFrequent(const Token& first, const Token& second) {
	if (first.get_frequency() < second.get_frequency()) return true;
	if (first.get_frequency() > second.get_frequency()) return false;
	// since the two supplied tokens are of the same frequency, we order them lexicography
	if (first.compare(second) < 0) return true;
	return false;
}

#endif
// Dictionary.h
// Dictionary class definition.
// Member functions are defined in Dictionary.cpp
// Created by Anne Liao (40215517) on June 12, 2022.
// Last modified on June 16, 2022.

#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <iostream>
#include <fstream>
#include <array>
#include <list>
#include <forward_list>
#include <string>
#include <set>
#include <vector>

#include "Token.h"

using std::forward_list;
using std::set;
using std::vector;
using std::string;
using std::ostream;
using std::array;
using std::list;

class Dictionary {
private:
	string filename; // Input file name
	const string theSeparators; // The separator characters in a std::string
	vector<string> input_lines; // The lines in the input file
	array<list<Token>, 27> token_list_buckets; // Array of 27 token list buckets

	size_t bucket_index(const string& tokenText) const; // Returns the index of the bucket corresponding to tokenText[0]
	vector<string> extract_tokens_from_line(const string& line) const; // Extracts and returns the tokens separated by theSeparator in the specified line
	void push_back_into_bucket(const string& tokenText, size_t line_number); // Creates a token with the specified tokenText and line_number and then pushes (inserts) the token at the end of the bucket list corresponding to tokenText[0]
	void extract_and_push(const string& line, size_t line_number); // Using extract_tokens_from_line and push_back_into_bucket, inserts the tokens extracted from the specified line and line_number into appropriate buckets
	
	set<char> cleanup_set(set<char>& char_set) const; // Return new char_set with the duplicate special characters removed and duplicate case variations
	forward_list<Token> create_sorted_list(const list<Token>& list, const string& sortBy = "") const; // Copy the bucket list into a forward_list and sort by specified parameters

public:
	Dictionary(const string& filename, const string& separators = " \t\n"); // Normal constructor
	Dictionary() = delete; // Default ctor

	Dictionary(const Dictionary&) = default; // Copy ctor
	Dictionary(Dictionary&&) = default; // Move ctor
	Dictionary& operator=(const Dictionary&) = default; // Copy assignment
	Dictionary& operator=(Dictionary&&) = default; // Move assignment
	~Dictionary() = default; // Default dtor

	static string restore_fake_tab_newline_chars(const string& separators); // Static member function, which could otherwise be a free function. Replaces \t and \n with \\t and \\n in separators and returns the resulting string.
	
	void print_input_lines(set<char>& char_set) const; // Prints the input lines beginning with the characters stored in char_set. Each line is preceded by its line numbers in the input file. If char_set is empty, then it prints all input lines.
	void print_input_tokens(set<char>& char_set) const; // For each character ch in char-set: If ch is a letter, it prints original unsorted bucket corresponding to ch; if ch is not a letter, it prints the original unsorted foreign bucket.
	void print_sorted_on_token_text(set<char>& char_set) const; // Prints tokens sorted on token text
	void print_sorted_on_token_frequency(set<char>& char_set) const; // Prints tokens sorted on token frequency
	void print_sorted_on_token_length(set<char>& char_set) const; // Prints tokens sorted on token length
	void print_input_lines() const; // Prints all input lines, each preceded by line number
	void print_input_tokens() const; // Prints original unsorted tokens
	void print_sorted_on_token_text() const; // Prints all buckets sorted on token text
	void print_sorted_on_token_frequency() const; // Prints all buckets sorted on token frequency
	void print_sorted_on_token_length() const; // Prints all buckets sorted on token length
};

#endif
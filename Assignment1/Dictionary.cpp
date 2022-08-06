// Dictionary.cpp
// Dictionary class member-function definitions.
// Created by Anne Liao (40215517) on May 28, 2022.

#include <fstream>
#include <sstream>

#include "Dictionary.h" // include definition of class Dictionary from Dictionary.h

/** Constructors */

// Normal constructor, creates a dictionary
Dictionary::Dictionary(const string& filename) : filename(filename)
{
	std::ifstream fin(filename); // create an input file stream
	if (!fin) {
		std::cout << "could not open input file: " << filename << std::endl;
		exit(1);
	}

	int linenum = 0;
	string line;
	getline(fin, line); // very important first attempt to read;
								// this first attemot will get the i/o flags initialized
	while (fin) {
		++linenum; // count the line
		std::istringstream sin(line); // turn the line into an input string stream
		string tokenStr;
		// extract token strings
		while (sin >> tokenStr) {
			processToken(tokenStr, linenum);
		}
		getline(fin, line); // attempt to read the next line, if any
	}
	fin.close();
}

/** Public class member-function defintions */

// Determine where the input string and linenum should go in the dictionary
void Dictionary::processToken(const string& token, int linenum) {
	size_t index = bucketIndex(token);
	Token t(token.c_str(), linenum);
	tokenListBuckets[index].addSorted(t);
}

// Print the sorted dictionary list
void Dictionary::print(std::ostream& out) const {
	for (size_t i{}; i < 27; ++i) {
		char c = 'A' + i;
		if (c == 91) {
			c = NULL;
		}
		out << '<' << c << '>' << std::endl;
		out << tokenListBuckets[i] << std::endl;
	}
}

/** Private class member-function defintions */

// Determine the alphanumeric index the token should go in
size_t Dictionary::bucketIndex(const string& token) const {
	size_t index = 26; // bucket index for tokens not beginning with a letter
	if (isalpha(token[0])) {
		if (isupper(token[0])) index = token[0] - 'A';
		else index = token[0] - 'a';
	}
	return index;
}
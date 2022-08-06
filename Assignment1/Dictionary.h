// Dictionary.h
// Dictionary class definition
// Member functions are defined in Dictionary.cpp
// Created by Anne Liao (40215517) on May 28, 2022.

#ifndef DICTIONARY_H_ // prevent multiple inclusions of header
#define DICTIONARY_H_
#include <string>

#include "TokenList.h"

using std::string;

class Dictionary {
private:
	string filename;
	TokenList tokenListBuckets[27]; // 26 alpha buckets + 1 none-alpha bucket

	size_t bucketIndex(const string& token) const; // Determine the alphanumeric index the token should go in

public:
	Dictionary(const string& filename); // Normal constructor, creates a dictionary
	Dictionary() = delete; // no default ctor

	Dictionary(const Dictionary&) = default; // copy ctor
	Dictionary(Dictionary&&) = default; // move ctor
	Dictionary& operator=(const Dictionary&) = default; // copy assignment
	Dictionary& operator=(Dictionary&&) = default; // move assignment
	~Dictionary() = default; // default dtor

	void processToken(const string& token, int linenum); // Determine where the input string and linenum should go in the dictionary
	void print(std::ostream& out) const; // Print the sorted dictionary list
};

// Overload print stream
inline std::ostream& operator<<(std::ostream& sout, const Dictionary& dict) {
	dict.print(sout);
	return sout;
}
#endif
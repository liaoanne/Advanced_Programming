// assignment5.cpp
// assignment5 free function definitions.
// Created by Anne Liao (40215517) on July 27, 2022.
// Last modified on Aug 4, 2022.

#include "assignment5.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <functional>
#include <numeric>
#include <set>
#include <sstream>

/** TASK 1 */

// Takes a text file consisting of exactly one word perline and 
// returns a WordsVector containing all the words in that file
WordsVector read_words_into_vector(const std::string& inFileName) {
	std::ifstream ifs(inFileName); // create an input file stream
	if (!ifs.is_open()) { // check that the file is open
		std::cout << "Could not open file " + inFileName << std::endl;
		throw std::runtime_error("Could not open file" + inFileName);
	}

	WordsVector words_vector; // an empty vector
	std::copy(std::istream_iterator<std::string>(ifs), // start of input stream
		std::istream_iterator<std::string>(), // end of input stream
		std::back_inserter(words_vector)); // destination
	return words_vector;
}

/** TASK 2 */

// Counts the number of occurances of each individual word occuring in wvec, with lambda
WordsMap map_and_count_words_using_lambda(const WordsVector& wvec) {
	WordsMap wmap;
	std::for_each(wvec.begin(), // start of source
		wvec.end(), // end of source
		[&wmap](std::string word) { ++wmap[word]; }); // lambda expression
	return wmap;
}

/** TASK 3 */

// WordCountFunctor object
class WordCountFunctor {
	using WordsMap = std::map<std::string, size_t>;
private:
	WordsMap wmap;
public:
	void operator()(const std::string& word) {
		++wmap[word];
	}
	WordsMap getmap() const {
		return wmap;
	}
};

// Count the number of occurences of each individual word occuring in wvec, with functor
WordsMap map_and_count_words_using_functor(const WordsVector& wvec) {
	WordCountFunctor wcf{};
	wcf = std::for_each(wvec.begin(), // start of source
		wvec.end(), // end of source
		wcf); // a functor keeping track of the frequencies
	return wcf.getmap();
}

/** TASK 4 */

// Remove the duplicated words in the supplied words_vector
WordsVector remove_duplicates(const WordsVector& words_vector) {
	WordsVector words_vec{ words_vector };

	// sort the vector alphabetically
	std::sort(words_vec.begin(), words_vec.end());

	// rearrange the words in the sorted words_vec
	// store the iterator which points to the first non-unique element
	std::vector<std::string>::iterator it{ std::unique(words_vec.begin(), words_vec.end()) };

	// erase the range of non-unique words in words_vec
	words_vec.erase(it, words_vec.end());

	return words_vec;
}

/** TASK 5 */

// Determines whether the string phrase is a palindrome
bool is_palindrome(const std::string& phrase) {
	std::string temp{};

	// copy only alphabetical characters from phrase to temp
	std::remove_copy_if(phrase.begin(), phrase.end(), std::back_inserter(temp), is_alphabetic);

	// convert all the characters in temp to lowercase
	std::transform(temp.begin(), temp.end(), temp.begin(), [](char ch) -> char { return tolower(ch); });
	
	// compare the two halves of the string to check for palindrome
	bool result{ std::equal(temp.begin(), temp.begin() + temp.size() / 2, temp.rbegin()) };

	return result;
}

// Free function for determining whether ch is an alphabetic character
// Returns false if it is alpha
bool is_alphabetic(const char& ch) {
	return !isalpha(ch);
}

/** TASK 6 */

// CorrectSizeFunctor object for Method 2
class CorrectSizeFunctor {
public:
	bool operator()(const std::string& phrase, int n) {
		return phrase.size() == n;
	}
};

// Method 1: Count and return the number of elements in vec that are of length n, using lambda
size_t count_using_lambda(const std::vector<std::string>& vec, int n) {
	auto count{ count_if(vec.begin(), // start of source range
		vec.end(), // end of source range
		[&n](std::string phrase) {return phrase.size() == n; }) }; // a unary predicate

	return count;
}

// Method 2: Count and return the number of elements in vec that are of length n, using functor
size_t count_using_Functor(const std::vector<std::string>& vec, int n) {
	CorrectSizeFunctor csf{};
	
	auto count{ count_if(vec.begin(), // start of source range
		vec.end(), // end of source range
		std::bind(csf, std::placeholders::_1, n)) }; // a unary predicate
	
	return count;
}

// Method 3: Count and return the number of elements in vec that are of length n, using free function
size_t count_using_Free_Func(const std::vector<std::string>& vec, int n) {
	auto count{ count_if(vec.begin(), // start of source range
		vec.end(), // end of source range
		std::bind(isCorrectSizeFreeFunc, std::placeholders::_1, n)) }; // a unary predicate
	
	return count;
}

// Free function for determining if phrase is equal to size n, for method 3
bool isCorrectSizeFreeFunc(const std::string& phrase, int n) {
	return phrase.size() == n;
}

/** TASK 7 */

// Prints the sorted version of a supplied vector, using default comparison std::less<T>
void multisetUsingDefaultComparator(const std::vector<std::string>& vec) {
	std::multiset<std::string> strSet; // an empty set

	std::copy(vec.begin(), vec.end(), // source start and finish
		std::inserter(strSet, strSet.begin())); // destination start using a general inserter

	// create an ostream_iterator attached to cout, using a space " " as a separator
	std::ostream_iterator<std::string> out(std::cout, " ");

	// output the set elements to the cout
	std::copy(strSet.begin(), strSet.end(), out);
}

// LexicoComparator object with lexicographical compare functor
class LexicoComparator {
public:
	bool operator()(const std::string& phrase1, const std::string& phrase2) const {
		if (phrase1.size() < phrase2.size()) return true;
		if (phrase1.size() > phrase2.size()) return false;
		// since the two supplied tokens are of the same length, we order them lexicography
		if (phrase1.compare(phrase2) < 0) return true;
		return false;
	}
};

// Prints the sorted version of a supplied vector, sorted lexicographically
void multisetUsingMyComparator(const std::vector<std::string>& vec) {
	std::multiset<std::string, LexicoComparator> strSet; // an empty set, using custom Comparator

	std::copy(vec.begin(), vec.end(), // source start and finish
		std::inserter(strSet, strSet.begin())); // destination start using a general inserter

	// create an ostream_iterator attached to cout, using a space " " as a separator
	std::ostream_iterator<std::string> out(std::cout, " ");

	// output the set elements to the cout
	std::copy(strSet.begin(), strSet.end(), out);
}

/** TASK 8 */

// Fibonacci object with functor that returns the next integer of the fibonacci sequence
class Fibonacci {
private:
	int prev_last{1};
	int last{0};
public: 
	int operator()() {
		int temp{ last };
		last = prev_last + last;
		prev_last = temp;
		return temp;
	}
};

// Generate the first n terms of the Fibonacci sequence into a vector and return the vector
std::vector<int> getnerate_Fibonacci(int n) {
	std::vector<int> fib(n); // a vector of n ints, all initialized to 0

	std::generate(fib.begin(), fib.end(), // source start and finish
		Fibonacci()); // passing an unnamed function object

	return fib;
}

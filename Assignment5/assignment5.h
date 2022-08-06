// assignment5.h
// assignment5 header definition.
// Functions are defined in assignment5.cpp
// Created by Anne Liao (40215517) on July 27, 2022.
// Last modified on July 30, 2022.

#ifndef ASSIGNMENT5_H_
#define ASSIGNMENT5_H_

#include <map>
#include <string>
#include <vector>

// Type aliases
using WordsVector = std::vector<std::string>;
using WordsMap = std::map<std::string, size_t>;

WordsVector read_words_into_vector(const std::string& inFileName); // Task 1: Reads a text file and returns a WordsVector containing all the words in that file
WordsMap map_and_count_words_using_lambda(const WordsVector& wvec); // Task 2: Counts the number of occurances of each individual word occuring in wvec, with lambda
WordsMap map_and_count_words_using_functor(const WordsVector& wvec); // Task 3: Count the number of occurences of each individual word occuring in wvec, with functor
WordsVector remove_duplicates(const WordsVector& words_vector); // Task 4: Remove the duplicated words in the supplied words_vector
bool is_palindrome(const std::string& phrase); // Task 5: Determines whether the string phrase is a palindrome
size_t count_using_lambda(const std::vector<std::string>& vec, int n); // Task 6: Count and return the number of elements in vec that are of length n, using lambda
size_t count_using_Functor(const std::vector<std::string>& vec, int n); // Task 6: Count and return the number of elements in vec that are of length n, using functor
size_t count_using_Free_Func(const std::vector<std::string>& vec, int n); // Task 6: Count and return the number of elements in vec that are of length n, using free function
void multisetUsingDefaultComparator(const std::vector<std::string>& vec); // Task 7: Prints the sorted version of a supplied vector, using default comparison std::less<T>
void multisetUsingMyComparator(const std::vector<std::string>& vec); // Task 7: Prints the sorted version of a supplied vector, sorted lexicographically
std::vector<int> getnerate_Fibonacci(int n); // Task 8: Generate the first n terms of the Fibonacci sequence into a vector and return the vector

// Free functions for tasks
bool is_alphabetic(const char& ch); // Task 5: Determines whether ch is an alphabetic character
bool isCorrectSizeFreeFunc(const std::string& phrase, int n); // Task 6: Free function for determining if phrase is equal to size n

#endif
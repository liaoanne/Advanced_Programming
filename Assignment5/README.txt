README---------------------------------------------------------------------

COMP 5421 Assignment 5
By Anne Liao, student ID 40215517

Purpose: The purpose of this program is to use the STL components in C++: 
standard sequence container classes, standard associative container classes, 
iterators, and callable objects to implement a series of eight tasks. To 
enforce the usage of STL, no explicit loops (i.e. for, while, or do/while 
loops) were allowed for the implementation of any of the functions.

The tasks include: reading a textfile into a vector, counting occurances 
of each word, removing duplicate words in a vector, determining if a string 
is a palindrome, counting number of elements in a vector that are of a 
given length, sorting a vector lexicographically, and generating a vector 
containing a fibonacci sequence of a given length.

Instructions on how to run the program:

- assignment_5_test_driver.cpp contains the main() method, which will run 
a test of all the implemented tasks and print to the console a success 
message with the output of some functions, or an error message box if 
functions were incorrectly implemented.

Extra Features:

- Added two free functions (is_alphabetic, isCorrectSizeFreeFunc) to 
properly implement Task 5 and 6, respectively.
- Added three Functor objects (CorrectSizeFunctor, LexicoComparator, 
Fibonacci) to implement Task 6, 7, and 8, respectively.
- Definitions can be found in assignment5.cpp

Testing:

- Program was tested and run on Microsoft Visual Studio 2022 using C++20.
- assignment_5_test_driver.cpp gave the correct output and exited with 
code 0.
- No known bugs were found.

Additional notes:

- Modified assignment_5_test_driver.cpp line 175 to change the input text 
file path to work for my own directory path.

README---------------------------------------------------------------------
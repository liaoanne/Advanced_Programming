README---------------------------------------------------------------------

COMP 5421 Assignment 3
By Anne Liao, student ID 40215517

Purpose: This program implements an abstract data type (ADT) called a Quad.
The Quad comprises of an ordered sequence of four real numbers denoted by
[x1,x2,x3,x4] where xi are doubles. In this ADT, we have overloaded the 
constructor, compound assignment operator, basic arithmetic operators, 
unary operators, pre/post-increment/decrement operators, subscript operator, 
function objects, input/output operators, and relational operators.

Instructions on how to run the program:

- Test_Quad.cpp contains the main() method, which will run through a check 
of all the implemented overloads.

- To use the Quad ADT, use #include "Quad.h" in your code.

Extra Features:

- Revision 1: Added inverse() and absoluteValue() member functions. Added
test_accessor_mutator() in Test_Quad.cpp.

- Added void test_exceptions() in Test_Quad.cpp to test the the operators 
are throwing exceptions when an invalid operation is performed.

Testing:

- Program was tested and run on Microsoft Visual Studio 2022 using C++20.

- Test_Quad.cpp executed successfully and exited with code 0.

- No known bugs were found.

Additional notes:

- std::max({initializer_list}) would not compile when used for the function 
operators. This would have been preferred for better reusability. Instead,
the max value was found using conditions for each function operator.

README---------------------------------------------------------------------
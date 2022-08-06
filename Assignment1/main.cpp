// main.cpp
// A sample driver program using Dictionary

#include <iostream>
#include <string>
#include "Dictionary.h"

using std::cout;
using std::cin;
using std::string;

int main()
{
	cout << "Enter the name of input text file: ";
	string filename;
	cin >> filename;
	Dictionary dictionary(filename);
	cout << dictionary;
	return 0; // 0 means success!
}
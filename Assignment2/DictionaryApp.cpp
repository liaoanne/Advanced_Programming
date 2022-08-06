// DictionaryApp.cpp
// Main driver for Dictionary
// Created by Anne Liao (40215517) on June 12, 2022.
// Last modified on June 16, 2022.

#include <iostream>
#include <string>

#include "Dictionary.h"

using std::string;

int main() {
	// store filename
	std::cout << "Enter the name of an input text file: ";
	string filename;
	getline(std::cin, filename);

	// store separator characters
	std::cout << "Enter the separator characters: ";
	string separators;
	getline(std::cin, separators); // getLine automatically escapes the string

	// create dictionary
	Dictionary dictionary = separators.empty() ? Dictionary(filename) : Dictionary(filename, Dictionary::restore_fake_tab_newline_chars(separators));
	
	// set separators to the default value if none was given
	if (separators.empty()) separators = " \\t\\n";

	// store the menu selection from user
	char selection{};

	// display options menu continuously until user types '0' to exit
	do {
		// options
		std::cout << "\n  Chose one of the options listed below and, optionally, \n";
		std::cout << "  enter the initial character of the tokens to print: \n";
		std::cout << "    1 - Print input lines\n";
		std::cout << "    2 - Print original unsorted tokens\n";
		std::cout << "    3 - Print tokens sorted by text\n";
		std::cout << "    4 - Print tokens sorted by frequency\n";
		std::cout << "    5 - Print tokens sorted by length\n";
		std::cout << "    0 - Exit\n";
		std::cout << "\n  Enter your input: ";

		// store the menu input instructions from user
		string menuInput;
		getline(std::cin, menuInput);

		// check that menu input was given
		if (menuInput.empty()) {
			std::cout << "\nInvalid selection. Please try again.\n";
			continue;
		}

		// extract the selection and modifiers
		selection = menuInput[0]; // get first character of input string
		string modifiers{ menuInput.substr(1) }; // get the remaining input string after the first character
		set<char> char_set; // place all the characters in the modifier into a char_set
		for (auto const& ch : modifiers) {
			char_set.insert(ch);
		}

		// exeute option based on user selection
		switch (selection) {
			case '0': break; // exit

			case '1': // print input lines
				std::cout << "\nDictionary Source File: " << filename << "\n";
				std::cout << "Separator characters: " << separators << "\n";

				if (char_set.empty()) dictionary.print_input_lines();
				else dictionary.print_input_lines(char_set);

				break;

			case '2' : // print original unsorted tokens
				std::cout << "\nDictionary Source File: " << filename << "\n";
				std::cout << "Separator characters: " << separators << "\n";

				if (char_set.empty()) dictionary.print_input_tokens();
				else dictionary.print_input_tokens(char_set);

				break;

			case '3' : // print tokens sorted by text
				std::cout << "\nDictionary Source File: " << filename << "\n";
				std::cout << "Separator characters: " << separators << "\n";

				if (char_set.empty()) dictionary.print_sorted_on_token_text();
				else dictionary.print_sorted_on_token_text(char_set);

				break;

			case '4' : // print tokens sorted by frequency
				std::cout << "\nDictionary Source File: " << filename << "\n";
				std::cout << "Separator characters: " << separators << "\n";

				if (char_set.empty()) dictionary.print_sorted_on_token_frequency();
				else dictionary.print_sorted_on_token_frequency(char_set);

				break;

			case '5' : // print tokens sorted by length
				std::cout << "\nDictionary Source File: " << filename << "\n";
				std::cout << "Separator characters: " << separators << "\n";

				if (char_set.empty()) dictionary.print_sorted_on_token_length();
				else dictionary.print_sorted_on_token_length(char_set);

				break;

			default: // invalid input
				std::cout << "\nInvalid selection. Please try again.\n";
				break;
		}
	} while (selection != '0');

	// user selected exit code
	std::cout << "\nGoodbye." << std::endl;
	return 0; // success

}
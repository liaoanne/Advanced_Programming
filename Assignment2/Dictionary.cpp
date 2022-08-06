// Dictionary.cpp
// Dictionary class member-function definitions.
// Created by Anne Liao (40215517) on June 12, 2022.
// Last modified on June 16, 2022.

#include <iomanip>

#include "Dictionary.h" // include definition of class Dictionary from Dictionary.h

/** Constructors */

// Normal constructor
Dictionary::Dictionary(const string& filename, const string& separators) 
	: filename{ filename }, theSeparators{ separators } {

	std::ifstream fin(filename); // create an input file stream
	if (!fin) {
		std::cout << "Could not open input file: " << filename << std::endl;
		exit(1);
	}

	int linenum{ 0 };
	string line;
	getline(fin, line); // very important first attempt to read;
						// this first attempt will get the i/o flags initialized
	while (fin) {
		++linenum; // count the line
		input_lines.push_back(line); // add line to input_lines vector
		extract_and_push(line, linenum); // extract the tokens from the line
		getline(fin, line); // attempt to read the next line, if any
	}
	fin.close();
}

/** Public class member-function defintions */

// TODO : MODIFIED COMPARED TO ASSIGNMENT (DONE BACKWARDS)
// Static member function, which could otherwise be a free function. Replaces all \\t and \\n with \t and \n in separators and returns the resulting string.
string Dictionary::restore_fake_tab_newline_chars(const string& separators) {
	string newSeparators{ separators };

	// find all \\t and replace with \t
	size_t start_t{ newSeparators.find("\\t") };
	while (start_t != string::npos) {
		newSeparators.replace(start_t, 2, "\t");
		start_t = newSeparators.find("\\t");
	}
	
	// find all \\n and replace with \n
	size_t start_n{ newSeparators.find("\\n") };
	while (start_n != string::npos) {
		newSeparators.replace(start_n, 2, "\n");
		start_n = newSeparators.find("\\n");
	}

	return newSeparators;
}

// Option 1 (with modifiers)
// Prints the input lines beginning with the characters stored in char_set. Each line is preceded by its line numbers in the input file. If char_set is empty, then it prints all input lines.
void Dictionary::print_input_lines(set<char>& char_set) const {
	std::cout << "\nInput Lines\n";
	std::cout << "===========\n";

	// iteratates through lines and prints the input lines that match char_set
	int line_num{ 1 };
	for (auto const& line : input_lines) {
		// check if first character in the line matches with one of the characters in the char_set
		size_t firstChar = line.find_first_not_of(" \t\r\n"); // find the index of the first character that is not a blank character
		if (firstChar != string::npos) {
			// check both upper and lower case versions of the character is found in the char_set
			if (char_set.find(tolower(line[firstChar])) != char_set.end() ||
				char_set.find(toupper(line[firstChar])) != char_set.end()) {
				std::cout << std::setw(3) << line_num << ": " << line << "\n";
			}
		}
		++line_num;
	}
}

// Option 2 (with modifiers)
// For each character ch in char_set: If ch is a letter, it prints original unsorted bucket corresponding to ch; if ch is not a letter, it prints the original unsorted foreign bucket.
void Dictionary::print_input_tokens(set<char>& char_set) const {
	std::cout << "\nDictionary Unsorted\n";
	std::cout << "===================";

	// remove duplicates of upper and lower case of the same character, 
	// and duplicate special characters (since they all trigger the same foreign bucket)
	set<char> f_char_set{ cleanup_set(char_set) };

	// check if each characer in char_set is alpha or non alpha
	for (auto const& ch : f_char_set) {
		if (isalpha(ch)) { // print each token in alpha bucket
			int index{ toupper(ch) - 'A' };
			std::cout << "\n<" << ch << ">\n";
			for (auto const& tok : token_list_buckets.at(index)) {
				std::cout << tok << "\n";
			}
		}
		else { // print each token foreign bucket
			std::cout << "\n<>\n";
			for (auto const& tok : token_list_buckets[26]) {
				std::cout << tok << "\n";
			}
		}
	}
}

// Option 3 (with modifiers)
// Prints tokens sorted on token text
void Dictionary::print_sorted_on_token_text(set<char>& char_set) const {
	std::cout << "\nDictionary sorted by token text\n";
	std::cout << "===============================";

	// remove duplicates of upper and lower case of the same character, 
	// and duplicate special characters (since they all trigger the same foreign bucket)
	set<char> f_char_set{ cleanup_set(char_set) };

	// check if each characer in char_set is alpha or non alpha
	for (auto const& ch : f_char_set) {
		if (isalpha(ch)) { // print each token in alpha bucket
			int index{ toupper(ch) - 'A' }; // get bucket index based on first char

			// generate sorted forward_list from token_list_buckets[index]
			forward_list<Token> flist{ create_sorted_list(token_list_buckets.at(index))};

			std::cout << "\n<" << ch << ">\n";
			for (auto const& tok : flist) {
				std::cout << tok << "\n";
			}
		}
		else { // print each token foreign bucket	
			// generate sorted forward_list from token_list_buckets[26]
			forward_list<Token> flist{ create_sorted_list(token_list_buckets[26]) };

			std::cout << "\n<>\n";
			for (auto const& tok : flist) {
				std::cout << tok << "\n";
			}
		}
	}
}

// Option 4 (with modifiers)
// Prints tokens sorted on token frequency
void Dictionary::print_sorted_on_token_frequency(set<char>& char_set) const {
	std::cout << "\nDictionary sorted by token frequency\n";
	std::cout << "====================================";

	// remove duplicates of upper and lower case of the same character, 
	// and duplicate special characters (since they all trigger the same foreign bucket)
	set<char> f_char_set{ cleanup_set(char_set) };

	// check if each characer in char_set is alpha or non alpha
	for (auto const& ch : f_char_set) {
		if (isalpha(ch)) { // print each token in alpha bucket
			int index{ toupper(ch) - 'A' };

			// generate sorted forward_list from token_list_buckets[index]
			forward_list<Token> flist{ create_sorted_list(token_list_buckets.at(index), "isLessFrequent") };

			std::cout << "\n<" << ch << ">\n";
			for (auto const& tok : flist) {
				std::cout << tok << "\n";
			}
		}
		else { // print each token foreign bucket
			// generate sorted forward_list from token_list_buckets[26]
			forward_list<Token> flist{ create_sorted_list(token_list_buckets[26], "isLessFrequent") };

			std::cout << "\n<>\n";
			for (auto const& tok : flist) {
				std::cout << tok << "\n";
			}
		}
	}
}

// Option 5 (with modifiers)
// Prints tokens sorted on token length
void Dictionary::print_sorted_on_token_length(set<char>& char_set) const {
	std::cout << "\nDictionary sorted by token length\n";
	std::cout << "=================================";

	// remove duplicates of upper and lower case of the same character, 
	// and duplicate special characters (since they all trigger the same foreign bucket)
	set<char> f_char_set{ cleanup_set(char_set) };

	// check if each characer in char_set is alpha or non alpha
	for (auto const& ch : f_char_set) {
		if (isalpha(ch)) { // print each token in alpha bucket
			int index{ toupper(ch) - 'A' };

			// generate sorted forward_list from token_list_buckets[i]
			forward_list<Token> flist{ create_sorted_list(token_list_buckets.at(index), "isShorter") };

			std::cout << "\n<" << ch << ">\n";
			for (auto const& tok : flist) {
				std::cout << tok << "\n";
			}
		}
		else { // print each token foreign bucket
			// generate sorted forward_list from token_list_buckets[26]
			forward_list<Token> flist{ create_sorted_list(token_list_buckets[26], "isShorter") };

			std::cout << "\n<>\n";
			for (auto const& tok : flist) {
				std::cout << tok << "\n";
			}
		}
	}
}

// Option 1 (without modifiers)
// Prints all input lines, each preceded by line number
void Dictionary::print_input_lines() const {
	std::cout << "\nInput Lines\n";
	std::cout << "===========\n";

	// prints all the input lines because char_set is empty
	int line_num{ 1 };
	for (auto const& line : input_lines) {
		std::cout << std::setw(3) << line_num << ": " << line << "\n";
		++line_num;
	}
}

// Option 2 (without modifiers)
// Prints original unsorted tokens
void Dictionary::print_input_tokens() const {
	std::cout << "\nDictionary Unsorted\n";
	std::cout << "===================";

	// print all the buckets
	for (size_t i{}; i < 27; ++i) {
		// convert the bucket index to ASCII characters to print
		char ch{ 'A' + static_cast<char>(i) };
		if (ch == 91) {
			ch = NULL; // convert the foreign bucket index (26) to a null ASCII character
		}

		std::cout << "\n<" << ch << ">\n";
		for (auto const& tok : token_list_buckets[i]) {
			std::cout << tok << "\n";
		}
	}
}

// Option 3 (without modifiers)
// Prints all buckets sorted on token text
void Dictionary::print_sorted_on_token_text() const {
	std::cout << "\nDictionary sorted by token text\n";
	std::cout << "===============================";

	for (size_t i{}; i < 27; ++i) {
		// generate sorted forward_list from token_list_buckets[i]
		forward_list<Token> flist{ create_sorted_list(token_list_buckets[i]) };

		// convert the bucket index to ASCII characters to print
		char ch{ 'A' + static_cast<char>(i) };
		if (ch == 91) {
			ch = NULL; // convert the foreign bucket index (26) to a null ASCII character
		}

		std::cout << "\n<" << ch << ">\n";
		for (auto const& tok : flist) {
			std::cout << tok << "\n";
		}
	}
}

// Option 4 (without modifiers)
// Prints all buckets sorted on token frequency
void Dictionary::print_sorted_on_token_frequency() const {
	std::cout << "\nDictionary sorted by token frequency\n";
	std::cout << "====================================";

	for (size_t i{}; i < 27; ++i) {
		// generate sorted forward_list from token_list_buckets[i]
		forward_list<Token> flist{ create_sorted_list(token_list_buckets[i], "isLessFrequent") };

		// convert the bucket index to ASCII characters to print
		char ch{ 'A' + static_cast<char>(i) };
		if (ch == 91) {
			ch = NULL; // convert the foreign bucket index (26) to a null ASCII character
		}

		std::cout << "\n<" << ch << ">\n";
		for (auto const& tok : flist) {
			std::cout << tok << "\n";
		}
	}
}

// Option 5 (without modifiers)
// Prints all buckets sorted on token length
void Dictionary::print_sorted_on_token_length() const {
	std::cout << "\nDictionary sorted by token length\n";
	std::cout << "=================================";

	for (size_t i{}; i < 27; ++i) {
		// generate sorted forward_list from token_list_buckets[i]
		forward_list<Token> flist{ create_sorted_list(token_list_buckets[i], "isShorter") };

		// convert the bucket index to ASCII characters to print
		char ch{ 'A' + static_cast<char>(i) };
		if (ch == 91) {
			ch = NULL; // convert the foreign bucket index (26) to a null ASCII character
		}

		std::cout << "\n<" << ch << ">\n";
		for (auto const& tok : flist) {
			std::cout << tok << "\n";
		}
	}
}

/** Private class member-function defintions */

// Returns the index of the bucket corresponding to tokenText[0]
size_t Dictionary::bucket_index(const string& tokenText) const {
	size_t index{ 26 }; // bucket index for tokens not beginning with a letter
	if (isalpha(tokenText[0])) {
		index = toupper(tokenText[0]) - 'A';
	}
	return index;
}

// Extracts and returns the tokens separated by theSeparator in the specified line
vector<string> Dictionary::extract_tokens_from_line(const string& line) const {
	// declare empty vector<string>
	vector<string> vectorLine;
	
	// find the start index of first token if any
	size_t startIndex{ line.find_first_not_of(theSeparators) };

	// while there are tokens
	while (startIndex != string::npos) {
		size_t endIndex{ line.find_first_of(theSeparators, startIndex + 1) };
		if (endIndex == string::npos) {
			// reached the end of line, so set end_index to end of line
			endIndex = line.length();
		}

		// extract the token
		string token{ line.substr(startIndex, endIndex - startIndex) };
		// find the start index of the next token, if any
		startIndex = line.find_first_not_of(theSeparators, endIndex + 1);
		// add token to vector
		vectorLine.push_back(token);
	}

	return vectorLine;
}

// Creates a token with the specified tokenText and line_number and then pushes (inserts) the token at the end of the bucket list corresponding to tokenText[0]
void Dictionary::push_back_into_bucket(const string& tokenText, size_t line_number) {
	Token new_tok(tokenText, line_number); // create token

	// find bucket index based on first character in the token
	size_t index{ bucket_index(tokenText) };

	// check if the tokenText already exists in the bucket
	for (auto& tok : token_list_buckets[index]) {
		if (tok.compare(new_tok) == 0) {
			// tokenText is already in bucket; increment frequency and add line number
			tok.increment_frequency();
			tok.push_back_line_number(line_number);
			return;
		}
	}
	// tokenText does not exist, place token into the correct bucket at the end of the list
	token_list_buckets[index].push_back(new_tok);
}

// Using extract_tokens_from_line and push_back_into_bucket, inserts the tokens extracted from the specified line and line_number into appropriate buckets
void Dictionary::extract_and_push(const string& line, size_t line_number) {
	// get strings from the line into a vector
	vector<string> vectorLine = extract_tokens_from_line(line);
	
	// insert each string into the correct bucket with the line_number
	for (const auto& s : vectorLine) {
		push_back_into_bucket(s, line_number);
	}
}

// Return new char_set with the duplicate special characters removed and duplicate case variations (all will be upper case)
set<char> Dictionary::cleanup_set(set<char>& char_set) const {
	// create new char_set
	set<char> f_char_set;

	// variable to check if already special character to f_char_set
	bool added_foreign{ false };

	// insert characters from char_set into f_char_set if they are not duplicates
	for (auto const& ch : char_set) {
		if (isalpha(ch)) {
			if (f_char_set.find(toupper(ch)) == f_char_set.end()) {
				f_char_set.insert(toupper(ch));
			}
		}
		else if (!added_foreign) { // check to only add special characters once
			f_char_set.insert('~'); // makes sure that the foreign bucket is printed last,
										// ~ is after the alpha characters in ASCII
			added_foreign = true;
		}
	}

	return f_char_set;
}

// Copy the bucket list into a forward_list and sort
forward_list<Token> Dictionary::create_sorted_list(const list<Token>& list, const string& sortBy) const {
	// create forward_list and copy list into it
	forward_list<Token> flist;
	forward_list<Token>::iterator it{ flist.before_begin() };
	for (auto const& tok : list) {
		it = flist.insert_after(it, tok);
	}

	// sort forward_list based on sortBy
	if (sortBy.empty()) {
		flist.sort();
	}
	else if (sortBy.compare("isLessFrequent") == 0) {
		flist.sort(isLessFrequent);
	}
	else if (sortBy.compare("isShorter") == 0) {
		flist.sort(isShorter);
	}
	else {
		std::cout << "\nProgram terminated.\n";
		std::cout << "Invalid use of create_sorted_list(const list<Token>& list, const string& sortBy)\n";
		std::cout << "sortBy can only equal one of the three options: '', isLessFrequent, isShorter." << std::endl;
		abort();
	}

	return flist;
}
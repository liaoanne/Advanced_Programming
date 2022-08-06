README---------------------------------------------------------------------

COMP 5421 Assignment 2
By Anne Liao, student ID 40215517

Purpose: This program takes in a user provided .txt file and reads it. Then, 
it populates an index style dictionary, where words are grouped alphabetically.
The user can define the delimiter characters to specify how the program 
should interpret what a "word" is (optional). The user will then be able to 
display the dictionary by inputing different menu options followed by a 
string of characters they are interested in seeing (optional).

Menu options:

1 - Print input lines
2 - Print original unsorted tokens
3 - Print tokens sorted by text
4 - Print tokens sorted by frequency
5 - Print tokens sorted by length
0 - Exit

Instructions on how to run the program:

- When running the program in command line, the terminal will prompt
the user with "Enter the name of input text file: ".

- Please check that the input file (example: "Seuss.txt") is in the 
same location as the source code and type the file name 
(example: "Seuss.txt"), followed by the enter key.

- Next, the user will be prompted to input delimiter characters. All keyboard
characters are supported including whitespace characters which are should be
types as '\t', '\r', '\n' or ' '.

- Afterwards, the user will type a menu selection followed by the characters
that they would like the dictionary to display.

Extra Features:

- Added two (2) additional member functions in the Dictionary class for 
better encapsulation. They are: 

// Return new char_set with the duplicate special characters removed and 
// duplicate case variations.
set<char> cleanup_set(set<char>& char_set) const;

// Copy the bucket list into a forward_list and sort by specified parameters.
forward_list<Token> create_sorted_list(const list<Token>& list, 
	const string& sortBy = "") const;

Testing:

- Program was tested and run on Microsoft Visual Studio 2022.

- All options were tested and matched expected output.

- No known bugs were found. Output of main.cpp is as expected.

Additional notes:

- Two assumptions were made that affected the design and output of the code
(to match with the output given in the assignment):

1) When user selects option 1, the char_set they enter is case insensitive so
any line that begins with an uppercase or lowercase variation of the char_set
will be a match.

2) When user selects option 1, any whitespace characters that the user enters
in the char_set will be ignored and the line will be matched according to the
first non-whitspace character in the line.

README---------------------------------------------------------------------
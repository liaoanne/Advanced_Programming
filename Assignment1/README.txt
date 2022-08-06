README---------------------------------------------------------------------

COMP 5421 Assignment 1
By Anne Liao, student ID 40215517

Instructions on how to run the program:

- When running the program in command line, the terminal will prompt
the user with "Enter the name of input text file: ".

- Please check that the input file (example: "input_file_A1.txt") is in the 
same location as the source code and type the file name 
(example: "input_file_A1.txt"), followed by the enter key.

Extra Features:

- Added two (2) additional member functions in the TokenList class for 
better encapsulation. They are: 

public void clear(); // Release all the nodes in this TokenList
private void copy(const TokenList& list); // Copies list into this list

- The print stream operator << overload was implemented for all classes.

Testing:

- Constructors, assignment operators, and destructors were tested 
extensively in ArrayList, Token, and TokenList class.

- No known bugs were found. Output of main.cpp is as expected.

Additional notes:

- Program was tested and run on Microsoft Visual Studio on the ENCS computers.

README---------------------------------------------------------------------
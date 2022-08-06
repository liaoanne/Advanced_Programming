// Canvas.h
// Canvas class definition.
// Member functions are defined in Canvas.cpp
// Created by Anne Liao (40215517) on July 18, 2022.
// Last modified on July 23, 2022.

#ifndef CANVAS_H_
#define CANVAS_H_

#include <iostream>
#include <string>
#include <vector>

using std::vector;

class Canvas {
protected:
	vector<vector<char>> grid{}; // The only data member

	bool check(int r, int c) const; // Validates row r and column c, 0-based
	void resize(size_t rows, size_t cols); // Resizes this Canvas's dimensions

public:
	Canvas() = default; // Default constructor
	Canvas(int rows, int columns, char fillChar = ' '); // Normal constructor
	Canvas(const Canvas&) = default; // Copy constructor
	Canvas(Canvas&&) = default; // Move constructor
	Canvas& operator=(const Canvas&) = default; // Copy assignment
	Canvas& operator=(Canvas&&) = default; // Move assignment
	virtual ~Canvas() = default; // Destructor

	int getRows() const; // Returns height of this Canvas object
	int getColumns() const; // Returns width of this Canvas object
	Canvas flip_horizontal() const; // Flips this canvas horizontally
	Canvas flip_vertical() const; // Flips this canvas vertically
	void print(std::ostream&) const; // Prints this Canvas to ostream
	char get(int r, int c) const; // Returns char at row r and column c, 0-based;
	void put(int r, int c, char ch); // Puts ch at row r and column c, 0-based
	void drawString(int r, int c, const std::string text); // Draws text starting at row r and col c on this canvas
	void overlap(const Canvas& can, size_t r, size_t c); // Copies the non-blank characters of "can" onto the invoking Canvas object;
};

std::ostream& operator<<(std::ostream& sout, const Canvas& can); // Overloaded output operator

#endif
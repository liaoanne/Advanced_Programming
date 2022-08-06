// Canvas.cpp
// Canvas class member-function definitions.
// Created by Anne Liao (40215517) on July 18, 2022.
// Last modified on July 23, 2022.

#include "Canvas.h"

/** CONSTRUCTOR */

// Normal constructor: Creates this canvas's (rows x columns) grid filled with blank characters
Canvas::Canvas(int rows, int columns, char fillChar) 
	: grid { vector<vector<char>>(rows, vector<char>(columns, fillChar)) }{
}

/** PROTECTED CLASS MEMBER-FUNCTION DEFINITIONS */

// Validates row r and column c, 0-based
bool Canvas::check(int r, int c) const {
	if (r >= getRows()) return false;
	if (c >= getColumns()) return false;
	return true;
}

// Resizes this Canvas's dimensions
void Canvas::resize(size_t rows, size_t cols) {
	// create new grid with new size
	vector<vector<char>> temp_grid(rows, vector<char>(cols, ' '));
	for (size_t i{}; i < rows; ++i) {
		for (size_t j{}; j < cols; ++j) {
			if (check(static_cast<int>(i), static_cast<int>(j))) {
				temp_grid[i][j] = grid[i][j];
			}
		}
	}
	grid = temp_grid;
}

/** PUBLIC CLASS MEMBER-FUNCTION DEFINITIONS */

// Returns height of this Canvas object
int Canvas::getRows() const {
	return static_cast<int>(grid.size());
}

// Returns width of this Canvas object
int Canvas::getColumns() const {
	if (getRows() >= 1) return static_cast<int>(grid[0].size());
	else return 0;
}

// Flips this canvas horizontally
Canvas Canvas::flip_horizontal() const {
	int rows{ getRows() };
	int cols{ getColumns() };
	Canvas flipped_can(rows, cols);
	
	// iterates through this canvas
	for (int i{}; i < rows; ++i) {
		for (int j{}; j < cols; ++j) {
			int reflected_j{ cols - 1 - j }; // the column number of the horizontally reflected current j
			flipped_can.grid[i][reflected_j] = get(i, j); // copy values from this grid to flipped_can
		}
	}

	return flipped_can;
}

// Flips this canvas vertically
Canvas Canvas::flip_vertical() const {
	int rows{ getRows() };
	int cols{ getColumns() };
	Canvas flipped_can(rows, cols);

	for (int i{}; i < rows; ++i) {
		int reflected_i{ rows - 1 - i }; // the row number of the vertically reflected current i
		for (int j{}; j < cols; ++j) {
			flipped_can.grid[reflected_i][j] = get(i, j); // copy values from this grid to flipped_can
		}
	}
	
	return flipped_can;
}

// Prints this Canvas to ostream
void Canvas::print(std::ostream& sout) const {
	int rows{ getRows() };
	int cols{ getColumns() };
	
	for (int i{}; i < rows; ++i) {
		for (int j{}; j < cols; ++j) {
			sout << grid[i][j];
		}
		sout << "\n";
	}
}

// Returns char at row r and column c, 0-based
// throws std::out_of_range{ "Canvas index out of range" } if r or c is invalid.
char Canvas::get(int r, int c) const {
	if (!check(r, c)) throw std::out_of_range{ "Canvas index out of range" };
	else return grid[r][c];
}

// Puts ch at row r and column c, 0-based; the only function used by a shape's draw functions
// throws std::out_of_range{ "Canvas index out of range" } if r or c is invalid.
void Canvas::put(int r, int c, char ch) {
	if (!check(r, c)) throw std::out_of_range{ "Canvas index out of range" };
	else grid[r][c] = ch;
}

// Draws text starting at row r and col c on this canvas
// throws std::out_of_range if string goes outside of canvas
void Canvas::drawString(int r, int c, const std::string text) {
	// iterate through length of string
	for (int i{}; i < text.size(); ++i) {
		put(r, c + i, text[i]);
	}
}

// Copies the non-blank characters of "can" onto the invoking Canvas object;
// maps can's origin to row r and column c on the invoking Canvas object
// throws std::out_of_range if trying to overwrite outside of invoking Canvas
// NOTE: Asked prof about whether we need to resize the Canvas if the Canvas can goes 
//       outside the bounds of the invoking Canvas. Said we do not need to worry about it.
void Canvas::overlap(const Canvas& can, size_t r, size_t c) {
	int can_rows{ can.getRows() };
	int can_cols{ can.getColumns() };
	int int_r{ static_cast<int>(r) };
	int int_c{ static_cast<int>(c) };
	
	// iterate through can grid
	for (int i{}; i < can_rows; ++i) {
		for (int j{}; j < can_cols; ++j) {
			// overwrite any non-space character in can grid to this grid with origin at (r,c)
			if (can.get(i, j) != ' ') {
				put(int_r + i, int_c + j, can.grid[i][j]);
			}
		}
	}
}

/** FREE-FUNCTION DEFINITIONS */

// Overloaded output operator
std::ostream& operator<<(std::ostream& sout, const Canvas& can) {
	can.print(sout);
	return sout;
}
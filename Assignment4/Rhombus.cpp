// Rhombus.cpp
// Rhombus class member-function definitions.
// Created by Anne Liao (40215517) on July 16, 2022.
// Last modified on July 25, 2022.

#include "Rhombus.h"

/** CONSTRUCTOR */

// Normal constructor
Rhombus::Rhombus(int diagonal, const char& pen, const string& name)
	: Shape(pen, name) {
	// if diagonal is odd
	if (diagonal % 2 != 0) {
		height = diagonal;
		width = diagonal;
	}
	// if diagonal is even then + 1
	else {
		height = diagonal + 1;
		width = diagonal + 1;
	}
}

/** PUBLIC CLASS MEMBER-FUNCTION DEFINITIONS */

// Returns a non-negative integer, measuring the height of the shape's bounding box
int Rhombus::getHeight() const {
	return height;
}

// Returns a non-negative integer, measuring the width of the shape's bounding box
int Rhombus::getWidth() const {
	return width;
}

// Computes and returns the shape's geometric area
double Rhombus::areaGeo() const {
	return pow(height, 2) / 2;
}

// Computes and returns the shape's geometric perimeter
double Rhombus::perimeterGeo() const {
	return (2 * sqrt(2)) * height;
}

// Computes and returns the shape's screen area, the number of characters forming the textual image of the shape
int Rhombus::areaScr() const {
    int n{ height / 2 };
    return 2 * n * (n + 1) + 1;
}

// Computes and returns the shape's screen perimeter, the number of characters on the borders of the textual image of the shape
int Rhombus::perimeterScr() const {
	return 2 * (height - 1);
}

// Draws a textual image of the shape on a Canvas object using the shape's pen character
Canvas Rhombus::draw() const {
	Canvas can{ height, width };

	// iterate through top half of the rhombus to draw an upright triangle
	for (int i{}; i < height / 2 + 1; ++i) {
		int j{}; // integer for the column number

		// print empty space
		for (int k{}; k < width / 2 - i; ++k) {
			can.put(i, j, ' ');
			++j;
		}
		// print pen
		for (int k{}; k < 2 * i + 1; ++k) {
			can.put(i, j, getPen());
			++j;
		}
	}

	// iterate through the bottom half of the rhombus to draw an upside-down triangle
	for (int i{}; i < height / 2; ++i) {
		int row_num{ i + height / 2 + 1 }; // integer for row number
		int j{}; // integer for the column number

		// print empty space
		for (int k{}; k < i + 1; ++k) {
			can.put(row_num, j, ' ');
			++j;
		}
		// print pen
		for (int k{}; k < width - 2 * i - 2; ++k) {
			can.put(row_num, j, getPen());
			++j;
		}
	}

	return can;
}
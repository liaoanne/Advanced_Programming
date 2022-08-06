// RightTriangle.cpp
// RightTriangle class member-function definitions.
// Created by Anne Liao (40215517) on July 17, 2022.
// Last modified on July 25, 2022.

#include "RightTriangle.h"

/** CONSTRUCTOR */

// Normal constructor
RightTriangle::RightTriangle(int base, const char& pen, const string& name) 
	: Triangle(base, base, pen, name) {
}

/** PUBLIC CLASS MEMBER-FUNCTION DEFINITIONS */

// Computes and returns the shape's geometric perimeter
double RightTriangle::perimeterGeo() const {
	double n{ 2 + sqrt(2) };
	return n * getHeight();
}

// Computes and returns the shape's screen area, the number of characters forming the textual image of the shape
int RightTriangle::areaScr() const {
	return (getHeight() * (getHeight() + 1)) / 2;
}

// Computes and returns the shape's screen perimeter, the number of characters on the borders of the textual image of the shape
int RightTriangle::perimeterScr() const {
	return 3 * (getHeight() - 1);
}

// Draws a textual image of the shape on a Canvas object using the shape's pen character
Canvas RightTriangle::draw() const {
	Canvas can{ getHeight(), getWidth()};

	for (int i{}; i < getHeight(); ++i) {
		for (int j{}; j < i + 1; ++j) {
			can.put(i,j, getPen());
		}
	}

	return can;
}
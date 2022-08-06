// AcuteTriangle.cpp
// AcuteTriangle class member-function definitions.
// Created by Anne Liao (40215517) on July 17, 2022.
// Last modified on July 25, 2022.

#include "AcuteTriangle.h"

/** CONSTRUCTOR */

// Normal constructor; if base is even, base + 1
AcuteTriangle::AcuteTriangle(int base, const char& pen, const string& name) 
	: Triangle(base % 2 != 0 ? base : base + 1, base % 2 != 0 ? (base + 1) / 2 : (base + 2) / 2, pen, name) {}

/** PUBLIC CLASS MEMBER-FUNCTION DEFINITIONS */

// Computes and returns the shape's geometric perimeter
double AcuteTriangle::perimeterGeo() const {
	double n{ sqrt(pow(getWidth(),2) + 4 * (pow(getHeight(),2))) };
	return getWidth() + n;
}

// Computes and returns the shape's screen area, the number of characters forming the textual image of the shape
int AcuteTriangle::areaScr() const {
	return static_cast<int>(pow(getHeight(),2));
}

// Computes and returns the shape's screen perimeter, the number of characters on the borders of the textual image of the shape
int AcuteTriangle::perimeterScr() const {
	return 4 * (getHeight() - 1);
}

// Draws a textual image of the shape on a Canvas object using the shape's pen character
Canvas AcuteTriangle::draw() const {
	Canvas can{ getHeight(), getWidth() };

	for (int i{}; i < getHeight(); ++i) {
		int j{}; // integer for the column number

		// print empty space
		for (int k{}; k < getWidth() / 2 - i; ++k) {
			can.put(i, j, ' ');
			++j;
		}
		// print pen
		for (int k{}; k < 2 * i + 1; ++k) {
			can.put(i, j, getPen());
			++j;
		}
	}

	return can;
}
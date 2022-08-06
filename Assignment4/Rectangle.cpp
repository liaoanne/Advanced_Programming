// Rectangle.cpp
// Rectangle class member-function definitions.
// Created by Anne Liao (40215517) on July 16, 2022.
// Last modified on July 25, 2022.

#include "Rectangle.h"

/** CONSTRUCTOR */

// Normal constructor
Rectangle::Rectangle(int height, int width, const char& pen, const string& name)
	: Shape(pen, name), height{ height }, width{ width } {}

/** PUBLIC CLASS MEMBER-FUNCTION DEFINITIONS */

// Returns a non-negative integer, measuring the height of the shape's bounding box
int Rectangle::getHeight() const {
	return height;
}

// Returns a non-negative integer, measuring the width of the shape's bounding box
int Rectangle::getWidth() const {
	return width;
}

// Computes and returns the shape's geometric area
double Rectangle::areaGeo() const {
	return height * width;
}

// Computes and returns the shape's geometric perimeter
double Rectangle::perimeterGeo() const {
	return 2 * (height + width);
}

// Computes and returns the shape's screen area, the number of characters forming the textual image of the shape
int Rectangle::areaScr() const {
	return height * width;
}

// Computes and returns the shape's screen perimeter, the number of characters on the borders of the textual image of the shape
int Rectangle::perimeterScr() const {
	return 2 * (height + width) - 4;
}

// Draws a textual image of the shape on a Canvas object using the shape's pen character
Canvas Rectangle::draw() const {
	Canvas can{ height,width };
	
	for (int i{}; i < height; ++i) {
		for (int j{}; j < width; ++j) {
			can.put(i, j, getPen());
		}
	}

	return can;
}
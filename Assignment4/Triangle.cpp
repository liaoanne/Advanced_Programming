// Triangle.cpp
// Triangle class member-function definitions.
// Created by Anne Liao (40215517) on July 16, 2022.
// Last modified on July 25, 2022.

#include "Triangle.h"

/** CONSTRUCTOR */

// Normal constructor
Triangle::Triangle(int base, int height, const char& pen, const string& name) 
	: Shape(pen, name), base{ base }, height{ height } {}

/** PUBLIC CLASS MEMBER-FUNCTION DEFINITIONS */

// Returns a non-negative integer, measuring the height of the shape's bounding box
int Triangle::getHeight() const {
	return height;
}

// Returns a non-negative integer, measuring the width of the shape's bounding box
int Triangle::getWidth() const {
	return base;
}

// Computes and returns the shape's geometric area
double Triangle::areaGeo() const {
	return (height * base) / 2.0;
}
// Rhombus.h
// Rhombus class definition.
// Member functions are defined in Rhombus.cpp
// Created by Anne Liao (40215517) on July 16, 2022.
// Last modified on July 23, 2022.

#ifndef RHOMBUS_H_
#define RHOMBUS_H_

#include "Shape.h"

class Rhombus : public Shape {
private:
	int height;
	int width;
public:
	Rhombus(int diagonal, const char& pen = '*', const string& name = "Rhombus"); // Normal constructor

	Rhombus() = delete; // Default constructor
	Rhombus(const Rhombus&) = default; // Copy constructor
	Rhombus(Rhombus&&) = default; // Move constructor
	Rhombus& operator=(const Rhombus&) = default; // Copy assignment
	Rhombus& operator=(Rhombus&&) = default; // Move assignment
	virtual ~Rhombus() = default; // Destructor

	int getHeight() const override; // Returns a non-negative integer, measuring the height of the shape's bounding box
	int getWidth() const override; // Returns a non-negative integer, measuring the width of the shape's bounding box
	double areaGeo() const override; // Computes and returns the shape's geometric area
	double perimeterGeo() const override; // Computes and returns the shape's geometric perimeter
	int areaScr() const override; // Computes and returns the shape's screen area, the number of characters forming the textual image of the shape
	int perimeterScr() const override; // Computes and returns the shape's screen perimeter, the number of characters on the borders of the textual image of the shape
	Canvas draw() const override; // Draws a textual image of the shape on a Canvas object using the shape's pen character
};

#endif
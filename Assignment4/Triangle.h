// Triangle.h
// Triangle class definition.
// Member functions are defined in Triangle.cpp
// Created by Anne Liao (40215517) on July 16, 2022.
// Last modified on July 25, 2022.

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "Shape.h"

class Triangle : public Shape {
private:
	int base;
	int height;
public:
	Triangle(int base, int height, const char& pen, const string& name); // Normal constructor

	Triangle() = delete; // Default constructor
	Triangle(const Triangle&) = default; // Copy constructor
	Triangle(Triangle&&) = default; // Move constructor
	Triangle& operator=(const Triangle&) = default; // Copy assignment
	Triangle& operator=(Triangle&&) = default; // Move assignment
	virtual ~Triangle() = default; // Destructor

	int getHeight() const; // Returns a non-negative integer, measuring the height of the shape's bounding box
	int getWidth() const; // Returns a non-negative integer, measuring the width of the shape's bounding box
	double areaGeo() const; // Computes and returns the shape's geometric area

	virtual double perimeterGeo() const = 0; // Computes and returns the shape's geometric perimeter
	virtual int areaScr() const = 0; // Computes and returns the shape's screen area, the number of characters forming the textual image of the shape
	virtual int perimeterScr() const = 0; // Computes and returns the shape's screen perimeter, the number of characters on the borders of the textual image of the shape
	virtual Canvas draw() const = 0; // Draws a textual image of the shape on a Canvas object using the shape's pen character
};

#endif
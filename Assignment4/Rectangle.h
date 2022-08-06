// Rectangle.h
// Rectangle class definition.
// Member functions are defined in Rectangle.cpp
// Created by Anne Liao (40215517) on July 16, 2022.
// Last modified on July 23, 2022.

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle : public Shape {
private:
	int height;
	int width;
public:
	Rectangle(int height, int width, const char& pen = '*', const string& name = "Rectangle"); // Normal constructor]

	Rectangle() = delete; // Default constructor
	Rectangle(const Rectangle&) = default; // Copy constructor
	Rectangle(Rectangle&&) = default; // Move constructor
	Rectangle& operator=(const Rectangle&) = default; // Copy assignment
	Rectangle& operator=(Rectangle&&) = default; // Move assignment
	virtual ~Rectangle() = default; // Destructor

	int getHeight() const override; // Returns a non-negative integer, measuring the height of the shape's bounding box
	int getWidth() const override; // Returns a non-negative integer, measuring the width of the shape's bounding box
	double areaGeo() const override; // Computes and returns the shape's geometric area
	double perimeterGeo() const override; // Computes and returns the shape's geometric perimeter
	int areaScr() const override; // Computes and returns the shape's screen area, the number of characters forming the textual image of the shape
	int perimeterScr() const override; // Computes and returns the shape's screen perimeter, the number of characters on the borders of the textual image of the shape
	Canvas draw() const override; // Draws a textual image of the shape on a Canvas object using the shape's pen character
};

#endif
// RightTriangle.h
// RightTriangle class definition.
// Member functions are defined in RightTriangle.cpp
// Created by Anne Liao (40215517) on July 17, 2022.
// Last modified on July 25, 2022.

#ifndef RIGHTTRIANGLE_H_
#define RIGHTTRIANGLE_H_

#include "Triangle.h"

class RightTriangle : public Triangle {
public:
	RightTriangle(int base, const char& pen = '*', const string& name = "Ladder"); // Normal constructor

	RightTriangle() = delete; // Default constructor
	RightTriangle(const RightTriangle&) = default; // Copy constructor
	RightTriangle(RightTriangle&&) = default; // Move constructor
	RightTriangle& operator=(const RightTriangle&) = default; // Copy assignment
	RightTriangle& operator=(RightTriangle&&) = default; // Move assignment
	virtual ~RightTriangle() = default; // Destructor

	double perimeterGeo() const override; // Computes and returns the shape's geometric perimeter
	int areaScr() const override; // Computes and returns the shape's screen area, the number of characters forming the textual image of the shape
	int perimeterScr() const override; // Computes and returns the shape's screen perimeter, the number of characters on the borders of the textual image of the shape
	Canvas draw() const override; // Draws a textual image of the shape on a Canvas object using the shape's pen character
};

#endif
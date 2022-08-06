// AcuteTriangle.h
// AcuteTriangle class definition.
// Member functions are defined in AcuteTriangle.cpp
// Created by Anne Liao (40215517) on July 17, 2022.
// Last modified on July 25, 2022.

#ifndef ACUTETRIANGLE_H_
#define ACUTETRIANGLE_H_

#include "Triangle.h"

class AcuteTriangle : public Triangle {
public:
	AcuteTriangle(int base, const char& pen = '*', const string& name = "Wedge"); // Normal constructor

	AcuteTriangle() = delete; // Default constructor
	AcuteTriangle(const AcuteTriangle&) = default; // Copy constructor
	AcuteTriangle(AcuteTriangle&&) = default; // Move constructor
	AcuteTriangle& operator=(const AcuteTriangle&) = default; // Copy assignment
	AcuteTriangle& operator=(AcuteTriangle&&) = default; // Move assignment
	virtual ~AcuteTriangle() = default; // Destructor

	double perimeterGeo() const override; // Computes and returns the shape's geometric perimeter
	int areaScr() const override; // Computes and returns the shape's screen area, the number of characters forming the textual image of the shape
	int perimeterScr() const override; // Computes and returns the shape's screen perimeter, the number of characters on the borders of the textual image of the shape
	Canvas draw() const override; // Draws a textual image of the shape on a Canvas object using the shape's pen character
};

#endif
// Shape.h
// Shape class definition.
// Member functions are defined in Shape.cpp
// Created by Anne Liao (40215517) on July 16, 2022.
// Last modified on July 25, 2022.

#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
#include <string>
#include <format>

#include "Canvas.h"

using std::string;

class Shape {
private:
	string name{}; // Name of the object
	char pen{}; // A character to draw the shape with
	int identity_number{}; // A unique positive integer, distinct from that of all other shape objects
	static int next_id; // Holds an integer for the next available identity_number

public:
	Shape(const char& pen, const string& name); // Normal constructor

	Shape() = delete; // Default constructor
	Shape(const Shape&) = default; // Copy constructor
	Shape(Shape&&) = default; // Move constructor
	Shape& operator=(const Shape&) = default; // Copy assignment
	Shape& operator=(Shape&&) = default; // Move assignment
	virtual ~Shape() = default; // Destructor

	string getName() const; // Getter method for name
	char getPen() const; // Getter method for pen
	int getIdentityNumber() const; // Getter method for identity number

	void setName(const string& newName); // Setter method for name
	void setPen(const char& newPen); // Setter method for new pen

	string toString() const; // Returns std::string representation of the Shape object invoking it

	virtual int getHeight() const = 0; // Returns a non-negative integer, measuring the height of the shape's bounding box
	virtual int getWidth() const = 0; // Returns a non-negative integer, measuring the width of the shape's bounding box
	virtual double areaGeo() const = 0; // Computes and returns the shape's geometric area
	virtual double perimeterGeo() const = 0; // Computes and returns the shape's geometric perimeter
	virtual int areaScr() const = 0; // Computes and returns the shape's screen area, the number of characters forming the textual image of the shape
	virtual int perimeterScr() const = 0; // Computes and returns the shape's screen perimeter, the number of characters on the borders of the textual image of the shape
	
	virtual Canvas draw() const = 0; // Draws a textual image of the shape on a Canvas object using the shape's pen character
};

std::ostream& operator<<(std::ostream& out, const Shape& shp); // Overloaded output operator

#endif

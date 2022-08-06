// Shape.cpp
// Shape class member-function definitions.
// Created by Anne Liao (40215517) on July 16, 2022.
// Last modified on July 23, 2022.

#include "Shape.h"

/** STATIC VARIABLE INITIALIZATION */

int Shape::next_id = 1;

/** CONSTRUCTOR */

// Normal constructor
Shape::Shape(const char& pen, const string& name) 
	: name{ name }, pen{ pen }, identity_number{ next_id } {
	next_id++;
}

/** PUBLIC CLASS MEMBER-FUNCTION DEFINITIONS */

// Getter method for name
string Shape::getName() const {
	return name;
}

// Getter method for pen
char Shape::getPen() const {
	return pen;
}

// Getter method for identity number
int Shape::getIdentityNumber() const {
	return identity_number;
}

// Setter method for name
void Shape::setName(const string& newName) {
	name = newName;
}

// Setter method for new pen
void Shape::setPen(const char& newPen) {
	pen = newPen;
}

// Returns std::string representation of the Shape object invoking it
string Shape::toString() const {
	string output{};

	output += "Shape Information\n-----------------";
	output += std::format("\nid:                  {:d}", getIdentityNumber());
	output += std::format("\nShape name:          {:s}", getName());
	output += std::format("\nPen character:       {:c}", getPen());
	output += std::format("\nHeight:              {:d}", getHeight());
	output += std::format("\nWidth:               {:d}", getWidth());
	output += std::format("\nTextual area:        {:d}", areaScr());
	output += std::format("\nGeometric area:      {:.2f}", areaGeo());
	output += std::format("\nTextual perimeter:   {:d}", perimeterScr());
	output += std::format("\nGeometric perimeter: {:.2f}", perimeterGeo());
	output += std::format("\nStatic type:         {:s}", typeid(this).name());
	output += std::format("\nDynamic type:        {:s}", typeid(*this).name());
	output += "\n";

	return output;
}

/** FREE-FUNCTION DEFINITIONS */

// Overloaded output operator
std::ostream& operator<<(std::ostream& out, const Shape& shp) {
	out << shp.toString();
	return out;
}
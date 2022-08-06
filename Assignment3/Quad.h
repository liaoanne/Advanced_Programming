// Quad.h
// Quad class definition.
// Member functions are defined in Quad.cpp
// Created by Anne Liao (40215517) on July 8, 2022.
// Last modified on July 9, 2022.

#ifndef QUAD_H_
#define QUAD_H_

#include <array>
#include <iostream>

class Quad {
private:
	std::array<double, 4> quad{};
public:
	static inline const double tolerance{ 1.0E-6 };

	Quad(double x1 = 0.0, double x2 = 0.0, double x3 = 0.0, double x4 = 0.0); // Normal constructor
	Quad(const Quad&) = default; // Copy constructor
	Quad(Quad&&) = default; // Move constructor
	Quad& operator=(const Quad&) = default; // Copy assignment operator
	Quad& operator=(Quad&&) = default; // Move assignment operator
	~Quad() = default; // Destructor

	Quad get() const; // Accessor member function
	void set(const Quad&); // Mutator member function
	double absoluteValue() const; // Returns the absolute value of the invoking object
	Quad inverse() const; // Returns the inverse of the invoking object

	// Overloaded compound assignment operators
	Quad& operator+=(const Quad& rhs);
	Quad& operator+=(const double& rhs);

	Quad& operator-=(const Quad& rhs);
	Quad& operator-=(const double& rhs);

	Quad& operator*=(const Quad& rhs);
	Quad& operator*=(const double& rhs);

	Quad& operator/=(const Quad& rhs);
	Quad& operator/=(const double& rhs);

	// Overloaded unary increment and decrement operators
	Quad operator+(); // prefix
	Quad operator-(); // prefix
	Quad& operator++(); // prefix
	Quad& operator--(); // prefix
	Quad operator++(int); // postfix
	Quad operator--(int); // postfix

	// Overloaded subscript operator
	double& operator[](int i);
	const double& operator[](int i) const;

	// Overloaded function call operator
	double operator()();
	double operator()(size_t i);
	double operator()(size_t i, size_t j);
	double operator()(size_t i, size_t j, size_t k);
	double operator()(size_t i, size_t j, size_t k, size_t l);

	friend std::ostream& operator<<(std::ostream& out, const Quad& q); // Overloaded insertion (output) operator
	friend std::istream& operator>>(std::istream& in, Quad& q); // Overloaded extraction (input) operator
};

// Overloaded basic arithmetic binary operators
Quad operator+(const Quad& lhs, const Quad& rhs);
Quad operator+(const Quad& lhs, const double& rhs);
Quad operator+(const double& lhs, const Quad& rhs);

Quad operator-(const Quad& lhs, const Quad& rhs);
Quad operator-(const Quad& lhs, const double& rhs);
Quad operator-(const double& lhs, const Quad& rhs);

Quad operator*(const Quad& lhs, const Quad& rhs);
Quad operator*(const Quad& lhs, const double& rhs);
Quad operator*(const double& lhs, const Quad& rhs);

Quad operator/(const Quad& lhs, const Quad& rhs);
Quad operator/(const Quad& lhs, const double& rhs);
Quad operator/(const double& lhs, const Quad& rhs);

// Overloaded relationaland equality operators, Quad lhs and Quad rhs
bool operator==(const Quad& lhs, const Quad& rhs);
bool operator!=(const Quad& lhs, const Quad& rhs);
bool operator<(const Quad& lhs, const Quad& rhs);
bool operator<=(const Quad& lhs, const Quad& rhs);
bool operator>(const Quad& lhs, const Quad& rhs);
bool operator>=(const Quad& lhs, const Quad& rhs);

#endif
// Quad.cpp
// Quad class member-function definitions.
// Created by Anne Liao (40215517) on July 8, 2022.
// Last modified on July 10, 2022.

#include <string>
#include "Quad.h"

/** CONSTRUCTOR */

// Normal constructor
Quad::Quad(double x1, double x2, double x3, double x4) : quad { x1, x2, x3, x4 } {
}

/** PUBLIC CLASS MEMBER-FUNCTION DEFINITIONS */

// Accessor member function
Quad Quad::get() const {
	return *this;
}

// Mutator member function
void Quad::set(const Quad& q) {
	quad[0] = q.quad[0];
	quad[1] = q.quad[1];
	quad[2] = q.quad[2];
	quad[3] = q.quad[3];
}

// Returns the absolute value of the invoking object
double Quad::absoluteValue() const {
	return abs(quad[0]) + abs(quad[1]) + abs(quad[2]) + abs(quad[3]);
}

// Returns the inverse of the invoking object
Quad Quad::inverse() const {
	Quad lhs{ *this };
	double beta{ lhs[1] * lhs[3] - lhs[2] * lhs[4] };

	// print error message if inverse is undefined
	if (std::abs(beta) < tolerance) {
		std::string lhsStr{ std::to_string(lhs[1]) + ", " + std::to_string(lhs[2])
			+ ", " + std::to_string(lhs[3]) + ", " + std::to_string(lhs[4]) };
		throw std::domain_error("inverse of the Quad [" + lhsStr + "] is undefined");
	}

	return Quad(lhs[3] / beta, -lhs[2] / beta, lhs[1] / beta, -lhs[4] / beta);
}

/** Overloaded compound assignment operators */

// Quad += Quad
Quad& Quad::operator+=(const Quad& rhs) {
	quad[0] += rhs.quad[0];
	quad[1] += rhs.quad[1];
	quad[2] += rhs.quad[2];
	quad[3] += rhs.quad[3];
	return *this;
}

// Quad += double
Quad& Quad::operator+=(const double& rhs) {
	quad[0] += rhs;
	quad[1] += rhs;
	quad[2] += rhs;
	quad[3] += rhs;
	return *this;
}

// Quad -= Quad
Quad& Quad::operator-=(const Quad& rhs) {
	quad[0] -= rhs.quad[0];
	quad[1] -= rhs.quad[1];
	quad[2] -= rhs.quad[2];
	quad[3] -= rhs.quad[3];
	return *this;
}

// Quad -= double
Quad& Quad::operator-=(const double& rhs) {
	quad[0] -= rhs;
	quad[1] -= rhs;
	quad[2] -= rhs;
	quad[3] -= rhs;
	return *this;
}

// Quad *= Quad
Quad& Quad::operator*=(const Quad& rhs) {
	double q0{ quad[0] * rhs.quad[0] + quad[1] * rhs.quad[3] };
	double q1{ quad[0] * rhs.quad[1] + quad[1] * rhs.quad[2] };
	double q2{ quad[3] * rhs.quad[1] + quad[2] * rhs.quad[2] };
	double q3{ quad[3] * rhs.quad[0] + quad[2] * rhs.quad[3] };

	quad[0] = q0;
	quad[1] = q1;
	quad[2] = q2;
	quad[3] = q3;

	return *this;
}

// Quad *= double
Quad& Quad::operator*=(const double& rhs) {
	quad[0] *= rhs;
	quad[1] *= rhs;
	quad[2] *= rhs;
	quad[3] *= rhs;
	return *this;
}

// Quad /= Quad
Quad& Quad::operator/=(const Quad& rhs) {
	*this *= rhs.inverse();
	return *this;
}

// Quad /= double
Quad& Quad::operator/=(const double& rhs) {
	if (rhs == 0) throw std::domain_error("inverse of the 0 is undefined");
	*this *= (1 / rhs);
	return *this;
}

/** Overloaded unary increment and decrement operators */

// +Quad
Quad Quad::operator+() {
	return *this;
}

// -Quad
Quad Quad::operator-() {
	Quad temp{ *this * -1};
	return temp;
}

// ++Quad
Quad& Quad::operator++() {
	quad[0] += 1;
	quad[1] += 1;
	quad[2] += 1;
	quad[3] += 1;
	return *this;
}

// ++Quad
Quad& Quad::operator--() {
	quad[0] -= 1;
	quad[1] -= 1;
	quad[2] -= 1;
	quad[3] -= 1;
	return *this;
}

// Quad++
Quad Quad::operator++(int) {
	Quad temp{ *this };
	++(*this);
	return temp;
}

// Quad--
Quad Quad::operator--(int) {
	Quad temp{ *this };
	--(*this);
	return temp;
}

/** Overloaded subscript operator */

double& Quad::operator[](int i) {
	if (i > 4 || i < 1) throw std::out_of_range("index out of bounds");
	return quad[i - 1];
}

const double& Quad::operator[](int i) const {
	if (i > 4 || i < 1) throw std::out_of_range("index out of bounds");
	return quad[i - 1];
}

/** Overloaded function call operator */

// Returns the largest coordinate values of the invoking Quad object
double Quad::operator()() {
	double temp{};
	if (temp < quad[0]) temp = quad[0];
	if (temp < quad[1]) temp = quad[1];
	if (temp < quad[2]) temp = quad[2];
	if (temp < quad[3]) temp = quad[3];
	return temp;
}

// Returns the i'th coordinate value of the invoking Quad object
double Quad::operator()(size_t i) {
	if (i > 4 || i < 1) throw std::out_of_range("index out of bounds");

	return quad[i - 1];
}

// Returns the larger of the i'th and j'th coordinate values of the invoking Quad object
double Quad::operator()(size_t i, size_t j) {
	if (i > 4 || j > 4 || i < 1 || j < 1) throw std::out_of_range("index out of bounds");

	if (quad[i - 1] > quad[j - 1]) return quad[i - 1];
	return quad[j - 1];
}

// Returns the largest of the i'th, j'th, and k'th coordinate values of the invoking Quad object
double Quad::operator()(size_t i, size_t j, size_t k) {
	if (i > 4 || j > 4 || k > 4 || i < 1 || j < 1 || k < 1) throw std::out_of_range("index out of bounds");

	double temp{};
	if (temp < quad[i - 1]) temp = quad[i - 1];
	if (temp < quad[j - 1]) temp = quad[j - 1];
	if (temp < quad[k - 1]) temp = quad[k - 1];
	return temp;
}

// Returns the largest of the i'th, j'th, k'th, and l'th coordinate values of the invoking Quad object
double Quad::operator()(size_t i, size_t j, size_t k, size_t l) {
	if (i > 4 || j > 4 || k > 4 || l > 4 || i < 1 || j < 1 || k < 1 || l < 1) throw std::out_of_range("index out of bounds");

	double temp{};
	if (temp < quad[i - 1]) temp = quad[i - 1];
	if (temp < quad[j - 1]) temp = quad[j - 1];
	if (temp < quad[k - 1]) temp = quad[k - 1];
	if (temp < quad[l - 1]) temp = quad[l - 1];
	return temp;
}

/** FRIEND FUNCTIONS */

/** Overloaded input/output stream operator */

// Overloaded insertion (output) operator
std::ostream& operator<<(std::ostream& out, const Quad& q) {
	out << '[' << q.quad[0] << ", " << q.quad[1] << ", " << q.quad[2] << ", " << q.quad[3] << "]\n";
	return out;
}

// Overloaded insertion (output) operator
std::istream& operator>>(std::istream& in, Quad& q) {
	for (int i{ 1 }; i < 5; ++i) {
		in >> q[i];
		in.ignore(1);
	}
	return in;
}

/** FREE FUNCTIONS */

/** Overloaded basic arithmetic binary operators, Quad lhs and Quad rhs */

// Quad + Quad
Quad operator+(const Quad& lhs, const Quad& rhs) {
	Quad temp{ lhs };
	temp += rhs;
	return temp;
}

// Quad + double
Quad operator+(const Quad& lhs, const double& rhs) {
	Quad temp{ lhs };
	temp += rhs;
	return temp;
}

// double + Quad
Quad operator+(const double& lhs, const Quad& rhs) {
	Quad temp(lhs, lhs, lhs, lhs);
	temp += rhs;
	return temp;
}

// Quad - Quad
Quad operator-(const Quad& lhs, const Quad& rhs) {
	Quad temp{ lhs };
	temp -= rhs;
	return temp;
}

// Quad - double
Quad operator-(const Quad& lhs, const double& rhs) {
	Quad temp{ lhs };
	temp -= rhs;
	return temp;
}

// double - Quad
Quad operator-(const double& lhs, const Quad& rhs) {
	Quad temp(lhs, lhs, lhs, lhs);
	temp -= rhs;
	return temp;
}

// Quad * Quad
Quad operator*(const Quad& lhs, const Quad& rhs) {
	Quad temp{ lhs };
	temp *= rhs;
	return temp;
}

// Quad * double
Quad operator*(const Quad& lhs, const double& rhs) {
	Quad temp{ lhs };
	temp *= rhs;
	return temp;
}

// double * Quad
Quad operator*(const double& lhs, const Quad& rhs) {
	Quad temp{ rhs };
	temp *= lhs;
	return temp;
}

// Quad / Quad
Quad operator/(const Quad& lhs, const Quad& rhs) {
	Quad temp{ lhs };
	temp /= rhs;
	return temp;
}

// Quad / double
Quad operator/(const Quad& lhs, const double& rhs) {
	Quad temp{ lhs };
	temp /= rhs;
	return temp;
}

// double / Quad
Quad operator/(const double& lhs, const Quad& rhs) {
	Quad temp{ rhs.inverse() };
	temp *= lhs;
	return temp;
}

/** Overloaded relational and equality operators, Quad lhs and Quad rhs */

bool operator==(const Quad& lhs, const Quad& rhs) {
	return (lhs - rhs).absoluteValue() <= Quad::tolerance;
}

bool operator!=(const Quad& lhs, const Quad& rhs) {
	return !(lhs == rhs);
}

bool operator<(const Quad& lhs, const Quad& rhs) {
	return !(lhs == rhs) && lhs.absoluteValue() < rhs.absoluteValue();
}

bool operator<=(const Quad& lhs, const Quad& rhs) {
	return lhs < rhs || lhs == rhs;
}

bool operator>(const Quad& lhs, const Quad& rhs) {
	return rhs < lhs;
}

bool operator>=(const Quad& lhs, const Quad& rhs) {
	return lhs > rhs || lhs == rhs;
}
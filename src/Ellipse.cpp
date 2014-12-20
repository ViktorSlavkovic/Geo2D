#include "Ellipse.hpp"

#include <cmath>
using std::fabs;
using std::sqrt;

using namespace Geo2D;

double Ellipse::equals(double a, double b) const {
	return (fabs(a-b) < 0.001);
}

Ellipse::Ellipse() {
	_center.setX(0.0);
	_center.setY(0.0);
}

Ellipse::Ellipse(const rVector & center, double a, double b) {
	_center=center;
	_a=a;
	_b=b;
}

double Ellipse::area() const {
	return _a*_b*3.141592653;
}

double Ellipse::perimeter() const {
	return 3.141592653*(3.0*(_a+_b)-sqrt((3.0*_a+_b)*(_a+3.0*_b)));
}

const rVector & Ellipse::getCenter() const {
	return _center;
}

void Ellipse::setCenter(const rVector & val) {
	_center=val;
}

double Ellipse::getA() const {
	return _a;
}

void Ellipse::setA(double val) {
	_a=val;
}

double Ellipse::getB() const {
	return _b;
}

void Ellipse::setB(double val) {
	_b=val;
}

Ellipse & Ellipse::operator = (const Ellipse & param) {
	_center=param.getCenter();
	_a=param.getA();
	_b=param.getB();
	return (*this);
}

bool Ellipse::operator == (const Ellipse & param) const {
	return equals(_a,param.getA()) && equals(_b,param.getB()) && _center==param.getCenter();
}

bool Ellipse::operator != (const Ellipse & param) const {
	return !(equals(_a,param.getA()) && equals(_b,param.getB()) && _center==param.getCenter());
}

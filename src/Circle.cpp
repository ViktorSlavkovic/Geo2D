#include "Circle.hpp"

#include <cmath>
using std::fabs;

using namespace Geo2D;

double Circle::equals(double a, double b) const {
	return (fabs(a-b) < 0.001);
}

Circle::Circle() {
	_center.setX(0.0);
	_center.setY(0.0);
	_radius = 0.0;
}

Circle::Circle(const rVector & center, double radius) {
	_center = center;
	_radius = radius;
}

double Circle::area() const {
	return _radius*_radius*3.141592653;
}

double Circle::perimeter() const {
	return 2*_radius*3.141592653;
}

const rVector & Circle::getCenter() const {
	return _center;
}

void Circle::setCenter(const rVector & val) {
	_center = val;
}

double Circle::getRadius() const {
	return _radius;
}

void Circle::setRadius(double val) {
	_radius=val;
}

Circle & Circle::operator = (const Circle & param) {
	_radius=param.getRadius();
	_center=param.getCenter();
	return (*this);
}

bool Circle::operator == (const Circle & param) const {
	return equals(_radius,param.getRadius()) && _center==param.getCenter();
}

bool Circle::operator != (const Circle & param) const {
	return !(equals(_radius,param.getRadius()) && _center==param.getCenter());
}

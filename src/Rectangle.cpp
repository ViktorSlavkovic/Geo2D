#include "Rectangle.hpp"

using namespace Geo2D;

Rectangle::Rectangle() {
	_corner.setX(0.0);
	_corner.setY(0.0);
	_size.setX(0.0);
	_size.setY(0.0);
}

Rectangle::Rectangle(const rVector & corner, const rVector & size) {
	_corner = corner;
	_size = size;
}

double Rectangle::area() const {
	return _size.getX()*_size.getY();
}

double Rectangle::perimeter() const {
	return 2.0*(_size.getX()+_size.getY());
}

const rVector & Rectangle::getCorner() const{
	return _corner;
}

void Rectangle::setCorner(const rVector & val) {
	_corner = val;
}

const rVector & Rectangle::getSize() const {
	return _size;
}

void Rectangle::setSize(const rVector & val) {
	_size = val;
}

Rectangle & Rectangle::operator = (const Rectangle & param) {
	_size = param.getSize();
	_corner = param.getCorner();
	return (*this);
}

bool Rectangle::operator == (const Rectangle & param) const {
	return _size==param.getSize() && _corner==param.getCorner();
}

bool Rectangle::operator != (const Rectangle & param) const {
	return !(_size==param.getSize() && _corner==param.getCorner());
}

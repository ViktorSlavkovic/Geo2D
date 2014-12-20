#include "Line.hpp"

using namespace Geo2D;

Line::Line() {
    _first.setX(0.0);
    _second.setX(0.0);
    _first.setY(0.0);
    _second.setY(0.0);
}

Line::Line(rVector first, rVector second) {
    _first=first;
    _second=second;
}

const rVector & Line::getFirst() const {
    return _first;
}

void Line::setFirst(const rVector & val) {
    _first=val;
}

const rVector & Line::getSecond() const {
    return _second;
}

void Line::setSecond(const rVector & val) {
    _second=val;
}

Line & Line::operator = (const Line & param) {
    _first=param.getFirst();
    _second=param.getSecond();
    return (*this);
}

bool Line::operator == (const Line & param) const {
    return _first==param.getFirst() && _second==param.getSecond();
}

bool Line::operator != (const Line & param) const {
    return _first!=param.getFirst() && _second!=param.getSecond();
}

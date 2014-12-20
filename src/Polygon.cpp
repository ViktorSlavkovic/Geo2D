#include "Polygon.hpp"

using namespace Geo2D;

double Polygon::area() const {
	double sum=((*this)[0].getY()-(*this)[(*this).size()-1].getY())*((*this)[0].getX()+(*this)[(*this).size()-1].getX());
	for (size_type i=1; i<(*this).size(); i++) sum+=((*this)[i].getY()-(*this)[i-1].getY())*((*this)[i].getX()+(*this)[i-1].getX());
	sum/=2.0;
	return sum;
}

double Polygon::perimeter() const {
	double sum=(*this)[0] >> (*this)[(*this).size()-1];
	for (size_type i=1; i<(*this).size(); i++) sum+=sum=(*this)[i] >> (*this)[i-1];
	return sum;
}

rVector Polygon::massCenter() const {
	rVector pom;
	for (size_type i=0; i<(*this).size(); i++) pom += (*this)[i];
	pom /= (double)(*this).size();
	return pom;
}

Polygon & Polygon::operator = (const Polygon & param) {
	(*this).resize(param.size());
	for (size_type i=0; i<param.size(); i++)
		(*this)[i]=param[i];
	return (*this);
}

Polygon & Polygon::operator = (const vector<rVector> & param) {
	(*this).resize(param.size());
	for (size_type i=0; i<param.size(); i++)
		(*this)[i]=param[i];
	return (*this);
}

bool Polygon::operator == (const Polygon & param) const {
	if ((*this).size()!=param.size()) return false;
	for (size_type i=0; i<param.size(); i++) if ((*this)[i] != param[i]) return false;
	return true;
}

bool Polygon::operator != (const Polygon & param) const {
	if ((*this).size()!=param.size()) return true;
	for (size_type i=0; i<param.size(); i++) if ((*this)[i] != param[i]) return true;
	return false;
}

double Polygon::equals(double a, double b) const {
	return (fabs(a-b) < 0.001);
}

bool Polygon::Compare1(rVector & a, rVector & b) const {
	if (equals(a.getX(),b.getX())) {
		return a.getY() < b.getY();
	}
	else return a.getX()>b.getX();
}

rVector pom;

double equals(double a, double b) {
	return (fabs(a-b) < 0.001);
}

double AngleX(double x1, double y1, double x2, double y2) {
	double Pi=3.141592653;
	if (equals(x1,x2)) return Pi/2.0;
	else return fabs(atan((y1-y2)/(x1-x2)));
}

bool Cmp(const rVector & a, const rVector & b) {
	double aa=AngleX(a.getX(),a.getY(),pom.getX(),pom.getY());
	double ab=AngleX(b.getX(),b.getY(),pom.getX(),pom.getY());
	if (equals(aa,ab)) {
		return (a>>pom < b>>pom);
	}
	else return aa<ab;
}

void Polygon::Simplify() {
	if ((*this).size()<2) return;
	for (size_type i=1; i<(*this).size(); i++)
		if (!Compare1((*this)[0],(*this)[i])) {
			rVector pera=(*this)[0];
			(*this)[0]=(*this)[i];
			(*this)[i]=pera;
		}
	pom=(*this)[0];
	sort((*this).begin()+1,(*this).end(), Cmp);
}

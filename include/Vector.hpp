#ifndef _GEO_2_D_Vector_HPP_
#define _GEO_2_D_Vector_HPP_

#include <string>
#include <sstream>
#include <cmath>

using std::string;
using std::ostringstream;
using std::sqrt;
using std::fabs;

namespace Geo2D {

    //DECLARATION

	template <class type>
	class Vector {
		private:
			type _x;
			type _y;

			double equals(double a, double b) const;
		public:
			Vector();
			template <class type1>
			Vector(const Vector<type1> & copy);
			Vector(type x, type y);

			template <class type1>
			double distance(const Vector<type1> & v) const;
			double modulus() const;

			type getX() const;
			void setX(type x);
			type getY() const;
			void setY(type y);

			string toString() const;

			template <class type1>
			double operator >> (const Vector<type1> & param) const;
			template <class type1>
			Vector<type> operator + (const Vector<type1> & param) const;
			template <class type1>
			Vector<type> & operator += (const Vector<type1> & param);
			template <class type1>
			Vector<type> operator - (const Vector<type1> & param) const;
			template <class type1>
			Vector<type> & operator -= (const Vector<type1> & param);
			template <class type1>
			Vector<type> operator * (type1 param) const;
			template <class type1>
			Vector<type> & operator *= (type1 param);
			template <class type1>
			Vector<type> operator / (type1 param) const;
			template <class type1>
			Vector<type> & operator /= (type1 param);
            template <class type1>
			Vector<type> & operator = (const Vector<type1> & param);
            template <class type1>
			bool operator == (const Vector<type1> & param) const;
			template <class type1>
			bool operator != (const Vector<type1> & param) const;
	};

    //IMPLEMENTATION

    template <class type> double Vector<type>::equals(double a, double b) const {
        return (fabs(a-b) < 0.001);
    }

    template <class type> Vector<type>::Vector() {
        _x = 0.0;
        _y = 0.0;
    }

    template <class type> template <class type1> Vector<type>::Vector(const Vector<type1> & copy) {
        _x = (type) copy.getX();
        _y = (type) copy.getY();
    }

    template <class type> Vector<type>::Vector(type x, type y) {
        _x = x;
        _y = y;
    }

    template <class type> template <class type1> double Vector<type>::distance(const Vector<type1> & v) const {
        return sqrt(((double)_x-(double)v.getX())*((double)_x-(double)v.getX()) + ((double)_y-(double)v.getY())*((double)_y-(double)v.getY()));
    }

    template <class type> double Vector<type>::modulus() const{
        return sqrt(_x*_x + _y*_y);
    }

    template <class type> type Vector<type>::getX() const {
        return _x;
    }

    template <class type> void Vector<type>::setX(type x) {
        _x = x;
    }

    template <class type> type Vector<type>::getY() const {
        return _y;
    }

    template <class type> void Vector<type>::setY(type y) {
        _y = y;
    }

    template <class type> string Vector<type>::toString() const {
        string s;
        ostringstream sout(s);
        sout.precision(3);
        sout<<_x<<' '<<_y;
        return sout.str();
    }

    template <class type> template <class type1> Vector<type> Vector<type>::operator + (const Vector<type1> & param) const {
        return Vector<type>(_x + (type)param.getX(), _y + (type)param.getY());
    }

    template <class type> template <class type1> Vector<type> & Vector<type>::operator += (const Vector<type1> & param) {
        _x += (type) param.getX();
        _y += (type) param.getY();
        return (*this);
    }

    template <class type> template <class type1> Vector<type> Vector<type>::operator - (const Vector<type1> & param) const {
        return Vector<type>(_x - (type)param.getX(), _y - (type)param.getY());
    }

    template <class type> template <class type1> Vector<type> & Vector<type>::operator -= (const Vector<type1> & param) {
        _x -= (type) param.getX();
        _y -= (type) param.getY();
        return (*this);
    }

    template <class type> template <class type1> Vector<type> Vector<type>::operator * (type1 param) const {
        return Vector<type>(_x*(type)param, _y*(type)param);
    }

    template <class type> template <class type1> Vector<type> & Vector<type>::operator *= (type1 param) {
        _x*=(type) param;
        _y*=(type) param;
        return (*this);
    }

    template <class type> template <class type1> Vector<type> Vector<type>::operator / (type1 param) const {
        return Vector<type>(_x/(type)param, _y/(type)param);
    }

    template <class type> template <class type1> Vector<type> & Vector<type>::operator /= (type1 param) {
        _x/=(type)param;
        _y/=(type)param;
        return (*this);
    }

    template <class type> template <class type1> Vector<type> & Vector<type>::operator = (const Vector<type1> & param) {
        _x = (type)param.getX();
        _y = (type)param.getY();
        return (*this);
    }

    template <class type> template <class type1> bool Vector<type>::operator == (const Vector<type1> & param) const {
        return equals((double)_x,(double)param.getX()) && equals((double)_y,(double)param.getY());
    }

    template <class type> template <class type1> bool Vector<type>::operator != (const Vector<type1> & param) const {
        return (!equals((double)_x,(double)param.getX()) || !equals((double)_y,(double)param.getY()));
    }

    template <class type> template <class type1> double Vector<type>::operator >> (const Vector<type1> & param) const {
        return this->distance(param);
    }

}

#endif

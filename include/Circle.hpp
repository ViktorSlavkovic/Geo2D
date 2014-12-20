#ifndef _GEO_2_D_Circle_HPP_
#define _GEO_2_D_Circle_HPP_

#include "Vectors.hpp"

namespace Geo2D {

	class Circle {
		private:
			rVector _center;
			double _radius;

			double equals(double a, double b) const;
		public:
			Circle();
			Circle(const rVector & center, double radius);

			double area() const;
			double perimeter() const;

			const rVector & getCenter() const;
			void setCenter(const rVector & val);
			double getRadius() const;
			void setRadius(double val);

			Circle & operator = (const Circle & param);
			bool operator == (const Circle & param) const;
			bool operator != (const Circle & param) const;
	};

}

#endif

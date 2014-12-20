#ifndef _GEO_2_D_Ellipse_HPP_
#define _GEO_2_D_Ellipse_HPP_

#include "Vectors.hpp"

namespace Geo2D {

	class Ellipse {
		private:
			rVector _center;
			double _a, _b;

			double equals(double a, double b) const;
		public:
			Ellipse();
			Ellipse(const rVector & center, double a, double b);

			double area() const;
			double perimeter() const;

			const rVector & getCenter() const;
			void setCenter(const rVector & val);
			double getA() const;
			void setA(double val);
			double getB() const;
			void setB(double val);

			Ellipse & operator = (const Ellipse & param);
			bool operator == (const Ellipse & param) const;
			bool operator != (const Ellipse & param) const;
	};

}

#endif

#ifndef _GEO_2_D_Polygon_HPP_
#define _GEO_2_D_Polygon_HPP_

#include "Vectors.hpp"
#include <vector>
#include <cmath>
#include <algorithm>
using std::vector;
using std::sort;
using std::atan;

namespace Geo2D {

	class Polygon: public vector<rVector> {
		private:
			double equals(double a, double b) const;
			bool Compare1(rVector& a, rVector& b) const;
		public:

			void Simplify();

			double area() const;
			double perimeter() const;

			rVector massCenter() const;

			Polygon & operator = (const Polygon & param);
			Polygon & operator = (const vector<rVector> & param);
			bool operator == (const Polygon & param) const;
			bool operator != (const Polygon & param) const;
	};

}

#endif

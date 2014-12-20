#ifndef _GEO_2_D_Rectangle_HPP_
#define _GEO_2_D_Rectangle_HPP_

#include "Vectors.hpp"

namespace Geo2D {

	class Rectangle {
		private:
			rVector _corner, _size;
		public:
			Rectangle();
			Rectangle(const rVector & corner, const rVector & size);

			double area() const;
			double perimeter() const;

			const rVector & getCorner() const;
			void setCorner(const rVector & val);
			const rVector & getSize() const;
			void setSize(const rVector & val);

			Rectangle & operator = (const Rectangle & param);
			bool operator == (const Rectangle & param) const;
			bool operator != (const Rectangle & param) const;
	};

}

#endif

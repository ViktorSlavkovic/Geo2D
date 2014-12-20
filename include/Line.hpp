#ifndef _GEO_2_D_Line_HPP_
#define _GEO_2_D_Line_HPP_

#include "Vectors.hpp"

namespace Geo2D {

	class Line {
		private:
			rVector _first, _second;
		public:
			Line();
			Line(rVector first, rVector second);
			
			const rVector & getFirst() const;
			void setFirst(const rVector & val);
			const rVector & getSecond() const;
			void setSecond(const rVector & val);
			
			Line & operator = (const Line & param);
			bool operator == (const Line & param) const;
			bool operator != (const Line & param) const;
	};

}

#endif

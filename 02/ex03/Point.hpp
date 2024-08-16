#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:

	public:
		const Fixed	_x;
		const Fixed	_y;
		Point(void);
		Point(const float, const float);
		Point(const Point & origin);
		~Point(void);

		Point &	operator=(const Point & rhs);

		static bool bsp(const Point a, const Point b, const Point c,
			const Point point);
};

#endif

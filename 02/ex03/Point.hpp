#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	private:
		const Fixed	_x;
		const Fixed	_y;

		Point&	operator=(const Point& rhs);

	public:
		Point(void);
		Point(const float, const float);
		Point(const Point& rhs);
		~Point(void);

		const Fixed&	get_x(void) const;
		const Fixed&	get_y(void) const;
};

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point);

#endif

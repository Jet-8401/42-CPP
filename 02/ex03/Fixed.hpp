#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed {
	private:
		int				_rawbits;
		static short	_fractbits;

	public:
		Fixed(void);
		Fixed(const Fixed & origin);
		Fixed(const int n);
		Fixed(const float f);
		~Fixed(void);

		Fixed &			operator=(const Fixed & rhs);
		float			operator+(const Fixed & rhs) const;
		float			operator-(const Fixed & rhs) const;
		float			operator*(const Fixed & rhs) const;
		float			operator/(const Fixed & rhs) const;
		bool			operator>(const Fixed & rhs) const;
		bool			operator<(const Fixed & rhs) const;
		bool			operator>=(const Fixed & rhs) const;
		bool			operator<=(const Fixed & rhs) const;
		bool			operator==(const Fixed & rhs) const;
		bool			operator!=(const Fixed & rhs) const;
		float			operator++(void);
		float			operator++(int);
		float			operator--(void);
		float			operator--(int);

		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;
		static			Fixed &	min(Fixed & a, Fixed & b);
		static const	Fixed & min(const Fixed & a, const Fixed & b);
		static			Fixed &	max(Fixed & a, Fixed & b);
		static const 	Fixed & max(const Fixed & a, const Fixed & b);
};

std::ostream &	operator<<(std::ostream & out, Fixed const & rhs);

#endif

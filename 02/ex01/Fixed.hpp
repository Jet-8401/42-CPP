#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed {
	private:
		int				_value;
		static short	_bits;

	public:
		Fixed(void);
		Fixed(const Fixed &origin);
		Fixed(const int n);
		Fixed(const float f);
		~Fixed(void);

		Fixed &		operator=(const Fixed &rhs);

		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;
};

std::ostream &	operator<<(std::ostream out, Fixed const & rhs);

#endif

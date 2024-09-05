#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int				_rawbits;
		static short	_fractbits;

	public:
		Fixed(void);
		Fixed(const Fixed &origin);
		~Fixed(void);

		Fixed &		operator=(const Fixed &rhs);
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
};

#endif

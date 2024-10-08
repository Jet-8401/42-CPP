#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>

//typedef unsigned long uintptr_t;

class Serializer {
	private:
		Serializer(void);
		Serializer(const Serializer& src);
		~Serializer(void);

		Serializer&	operator=(const Serializer& rhs);

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif

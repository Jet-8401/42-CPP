#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
typedef unsigned int uint;

namespace {

	template <typename T>
	class Array {
		private:
			uint	_length;
			T		*_intern_arr;

		public:
			class OutOfBoundException : public std::exception {
				const char* what() const throw() {
					return "Accessing index is out of bound";
				}
			};

			Array(void): _length(0) {
				this->_intern_arr = new T[0];
				return ;
			}

			Array(uint n): _length(n) {
				this->_intern_arr = new T[n];
				for (uint i = 0; i < this->_length; i++)
					this->_intern_arr[i] = 0;
				return ;
			}

			Array(const Array& src): _length(src._length) {
				this->_intern_arr = new T[this->_length];
				*this = src;
				return ;
			}

			virtual	~Array(void) {
				delete [] this->_intern_arr;
				return ;
			}

			Array&	operator=(const Array& rhs) {
				if (!this->_intern_arr || !rhs._intern_arr)
					return (*this);
				for (uint i = 0; i < this->_length && i < rhs._length; i++)
					this->_intern_arr[i] = rhs._intern_arr[i];
				return (*this);
			}

			T&		operator[](const uint n) const {
				if (n >= this->_length || !this->_intern_arr)
					throw OutOfBoundException();
				return (this->_intern_arr[n]);
			}

			uint	size(void) const {
				return (this->_length);
			}
	};

	template<typename T>
	void	printArray(::Array<T>& arr)
	{
		for (uint i = 0; i < arr.size(); i++)
			std::cout << "array[" << i << "]=" << arr[i] << std::endl;
		return ;
	}
}

#endif

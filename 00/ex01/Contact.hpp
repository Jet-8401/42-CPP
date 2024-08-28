#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "main.hpp"

class Contact {

	public:
		Contact(void);

		bool			create(void);
		void			set_secret(void);
		std::string&	get_secret(void);
		void			preview(int);
		void			print(void);

	private:
		bool			_is_already_set;
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_phone_number;
		std::string		_darkest_secret;

		void			clear(void);

};

#endif

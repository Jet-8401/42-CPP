#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "main.hpp"

class Contact {

	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		void		set_secret(void);
		char		*get_secret(void);
		void		preview(int);
		void		print(void);

	private:
		char		darket_secret[SECRET_LEN];

};

#endif

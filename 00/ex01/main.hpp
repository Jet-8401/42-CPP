#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>
# include <iostream>
# include <iomanip>
# include <cstdlib>

# define SECRET_LEN 256
# define KEYS 3
# define DISPLAY_LEN 10
# define CONTACTS_N 8

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

class PhoneBook {
	public:
		PhoneBook	(void);
		int			current_contacts;
		void		add(void);
		void		search(void);
		void		exit_cmd(void);
		void		display_contacts(void);
	private:
		Contact 	contacts[CONTACTS_N];
};

#endif

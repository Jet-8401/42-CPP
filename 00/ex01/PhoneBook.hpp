#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"
# include "Contact.hpp"

class PhoneBook {

	public:
		PhoneBook(void);

		void			add(void);
		void			search(void);
		void			exit_cmd(void);
		void			display_contacts(void);

	private:
		unsigned int	_contacts_set;
		unsigned int	_oldest_contact;
		Contact 		_contacts[CONTACTS_N];
};

#endif

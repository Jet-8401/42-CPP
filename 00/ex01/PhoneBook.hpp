#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"
# include "Contact.hpp"

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

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
//#include "PhoneBook.hpp"

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _darkestSecret;
		std::string _phoneNumber;
		int         _index;
	public:
		void	setContact(int i);
		void    showContacts();
        void    displayResult();
        void    displayString(std::string str);
		/* Get Functions */
        std::string  getFirstName();
        std::string  getLastName();
        std::string  getNickName();
        std::string  getDarkestSecret();
        std::string  getPhoneNumber();
        int     getIndex();
};

#endif
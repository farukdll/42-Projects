#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
    private:
        Contact _contacts[8];
        int _total;
    
    public:
        PhoneBook(int added);
        void addContact();
        void displayContacts();
        void searchContacts();
        int getIndex();
        void updateTotal(int i);
};

#endif

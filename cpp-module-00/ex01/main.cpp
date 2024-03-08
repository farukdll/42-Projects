#include "PhoneBook.hpp"

int main(void)
{
    std::string     input;
    PhoneBook       phoneBook(0);

    std::cout << "WELCOME TO YOUR PHONEBOOK" << std::endl;
    while(1)
    {
        std::cout<<"-----------WHAT DO YOU WANT?---------------"<<std::endl;
        std::cout << "1. ADD\t  : Adds contact to phonephoneBook."<<std::endl;
        std::cout <<"2. SEARCH : Shows _contacts and searchs."<<std::endl;
        std::cout <<"3. EXIT   : Closes phonephoneBook."<<std::endl;
        std::cout <<"---------------------------------------"<<std::endl<<"_>";
        std::getline(std::cin, input);
        if (!input.compare("EXIT"))
            break ;
        else if (!input.compare("ADD"))
            phoneBook.addContact();
        else if (!input.compare("SEARCH"))
        {
            phoneBook.displayContacts();
        }
        else
            std::cout <<"INVALID INPUT"<<std::endl;
    }
    return (0);
}
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(int added)
{
    _total = added; 
}

void    PhoneBook::addContact()
{
    _contacts[_total % 8].setContact(_total % 8);
    PhoneBook::updateTotal(1);
    if (_total <= 8)
        std::cout << "Your contact has been added successfully." <<std::endl;
    else
        std::cout << "List is full! Oldest contact was deleted!" << std::endl;
}

void    PhoneBook::updateTotal(int i)
{
    _total += i;
}

int PhoneBook::getIndex()
{
    return ((_total % 8) + 1);
}

void    PhoneBook::displayContacts()
{
    if (_total == 0)
    {
        std::cout << "Nothing to Search, add some _contacts!" << std::endl; 
        return ;
    }
    std::cout << " ___________________________________________ "<< std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|"<< std::endl;
    for (int i = 0; i < _total && i < 8; i++)
    {
        std::cout << "|----------|----------|----------|----------|" << std::endl;
        _contacts[i].showContacts();
    }
    std::cout << " ------------------------------------------- " << std::endl;
    PhoneBook::searchContacts();
}

void    PhoneBook::searchContacts()
{
    std::string input;
    bool checker = false;
    int i = 0;
    do
    {
        std::cout << "enter the index of the contact to be displayed: ";
        std::getline(std::cin, input);
        if (input == "")
		{
			std::cout << "Id cannot be empty" << std::endl;
			continue;
		}
        while(input[i]){
            if (isdigit(input[i]) == false)
            {
                std::cout << "Id must be a number" << std::endl;
                return ;
            }
            i++;
        }
        if ((std::stoi (input)) < 1 || (std::stoi (input) > 8))
		{
			std::cout << "Id must be between 1 and 8" << std::endl;
			continue;
		}
        if(std::stoi (input) > _total)
        {
            std::cout << "Id must be smaller than total contacts" << std::endl;
			continue;
        }
        _contacts[std::stoi(input) - 1].displayResult();
        checker = true;
    } while (!checker);
}

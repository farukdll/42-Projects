#include "PhoneBook.hpp"

void    Contact::setContact(int i)
{
	int a = true;
	while(a)
	{
		std::cout << "Type first name: ";
		std::getline(std::cin, _firstName);
		if (_firstName == "")
		{
			std::cout << "First name cannot be empty" << std::endl;
			continue;
		}
		label1:
		std::cout<< "Type last name: ";
		std::getline(std::cin, _lastName);
		if (_lastName == "")
		{
			std::cout << "Last name cannot be empty" << std::endl;
			goto label1;
		}
		label2:
		std::cout << "Type nickname: ";
		std::getline(std::cin, _nickName);
		if (_nickName == "")
		{
			std::cout << "Nickname cannot be empty" << std::endl;
			goto label2;
		}
		label3:
		std::cout << "Type Darkest secret: ";
		std::getline(std::cin, _darkestSecret);
		if (_darkestSecret == "")
		{
			std::cout << "Darkest secret cannot be empty" << std::endl;
			goto label3;
		}
		label4:
		std::cout << "Type phone number: ";
		std::getline(std::cin, _phoneNumber);
		if (_phoneNumber == "")
		{
			std::cout << "Phone number cannot be empty" << std::endl;
			goto label4;
		}
		a = false;
		_index = i;
	}
}

void    Contact::displayString(std::string str)
{
	if (str.length() > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << str[i];
		std::cout<<".";
	}
	else
	{
		for (unsigned long i = 10; i > str.length(); i--)
			std::cout << " ";
		for (unsigned long i = 0; i < str.length(); i++)
			std::cout << str[i];
	}
}

void    Contact::showContacts()
{
	std::cout <<"|         "<< Contact::getIndex() + 1 << "|";
	Contact::displayString(Contact::getFirstName());
	std::cout <<"|";
	Contact::displayString(Contact::getLastName());
	std::cout <<"|";
	Contact::displayString(Contact::getNickName());
	std::cout <<"|";
	std::cout<<std::endl;
}

std::string  Contact::getFirstName()
{
	return (_firstName);
}

std::string  Contact::getLastName()
{
	return (_lastName);
}

std::string  Contact::getNickName()
{
	return (_nickName);
}

std::string  Contact::getDarkestSecret()
{
	return (_darkestSecret);
}

std::string  Contact::getPhoneNumber()
{
	return (_phoneNumber);
}

int Contact::getIndex()
{
	return (_index);
}

void    Contact::displayResult()
{
	std::cout<<"\n---------------Contact-----------------"<<std::endl;
	std::cout<<"First Name: \t"<<Contact::getFirstName()<<std::endl;
	std::cout <<"Last Name: \t"<<Contact::getLastName()<<std::endl;
	std::cout <<"Nickname: \t"<<Contact::getNickName()<<std::endl;
	std::cout <<"Darkest Secret: "<<Contact::getDarkestSecret()<<std::endl;
	std::cout << "Phone Number: \t"<<Contact::getPhoneNumber()<<std::endl;
	std::cout <<"---------------------------------------"<<std::endl;
}
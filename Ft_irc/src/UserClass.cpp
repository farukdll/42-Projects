#include "../inc/User.hpp"

User::User() {}

User::User(int fd): fd(fd), active(FALSE), oper(false)
{
	stringstream convert;

	cout << "created" << endl;
	convert << fd;
	this->user_name= "kvirc" + convert.str();
	this->host_name = this->user_name;
	this->serv_name = this->user_name;
	this->real_name = this->user_name;
}

User::User(const User &user)
{
	*this = user;
}

User::~User() {}

User&			User::operator=(const User &user)
{
	if (this != &user)
	{
		this->user_name = user.user_name;
		this->host_name = user.host_name;
		this->serv_name = user.serv_name;
		this->real_name = user.real_name;	
	}
	return (*this);
}

const string&	User::getUserName() const { return (user_name); }

const string&	User::getHostName() const { return (host_name); }

const string&	User::getServName() const { return (serv_name); }

const string&	User::getRealName() const { return (real_name);	}

const string&	User::getNickName() const { return (nick_name); }

const int		User::getActive() const { return (active); }

const int		User::getFd() const { return (fd); }

void			User::setActive(e_active choose)	{ active = choose; }

void			User::setUserName(const string& set) { user_name = set; }

void			User::setHostName(const string& set) { host_name = set; }

void			User::setServName(const string& set) { serv_name = set; }

void			User::setRealName(const string& set) { real_name = set; }

void			User::setNickName(const string& set) { nick_name = set; }

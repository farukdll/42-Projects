#include <Server.hpp>

Server	start;

/*
	Using a negative value for a port number causes errors and leads to unexpected results because 
	it does not comply with network communication standards. Therefore, 
	port numbers are always considered as positive integer values.
*/
bool	control(char **av)
{
	int port = atoi(av[1]);

	if (port >= 1024 && port <= 65535)
		return true;
	return false;
}



int	main(int ac, char **av) // 8080 emakas
{
	if (ac != 3 || !control(av))
	{
		cout << "You have entered the missing argument!" << endl;
		cout << "./irc <port> <password>" << endl;
		return (1);
	}
	start.setPort(atoi(av[1]));
	start.setPassword(av[2]);
	start.toBegin();



	return (0);
}
/*
	- Let's create a user.
	- We will strive to make the get and set functions more professional.
	- Let's try to add users to channels using a map.
	- Let's try to write some simple commands.
*/
//"a " State of being					  (OK)
// join									  ()
// Send a message to KVirc.				  ()
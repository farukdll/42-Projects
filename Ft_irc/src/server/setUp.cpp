#include "../../inc/Server.hpp"
#include "../../inc/Commands.hpp"

bool	isEqual(const string &test, const string &aim, int enter)
{
	if (enter == 0)
		return (false);
	int size = aim.size();
	int i;

	for (i = 0; i < size && aim[i] == test[i]; ++i);

	if (size == i)
		return (true);
	return (false);
}

/**
 * selcommand used for select command for given input
 * @param input: Input string
 * @return fp_command is the type of the function that represents 
 */
fp_command selCommand(vector<string> &input)
{
	string		str[] = {"JOIN", "NICK", "*", "KILL", "PING", "PONG", "WHO", "USER", "LIST", "PASS"};
	fp_command	result[] = {cmd::join, cmd::nick, cmd::quit, cmd::kill, cmd::ping, cmd::pong, cmd::who, cmd::user, cmd::list, cmd::pass, NULL};
	int			i;

	for (i = -1; i < 10; ++i)
		if (isEqual(input[0], str[i], input.size() >= 1) || 
				isEqual(input[1], str[i], input.size() >= 2))
			break;
	return result[i];
}


/// @brief handles input
/// @param fd 
/// @param input 
void	Server::handleInput(int fd, const string &input)
{
	fp_command 		func;
	string			str;
	stringstream	sstream(input);
	vector<string>	commands;

	while (getline(sstream, str, ' '))
	{
		if (str[0] > 33)
			commands.push_back(str);
	}
	// [<prefix>] <numeric_code> <param1> <param2>
	// Write(fd,"001 amy :Ahmet naber\n",100);
	// Create command from input
	if (commands.size() >= 2 && (func = selCommand(commands)) != 0)
		func(commands, *users[fd]);
	else
	{
		// Write(fd," 001 amy :Welcome to the Internet Relay Network borja!borja@polaris.cs.uchicago.edu\n",100); //return come of the text to the client
	}
}

// Const string& generateReply(int code, User, string message);

void	Server::setUpSocket()
{
	Socket clientSocket;
	vector<struct pollfd> pollfds;

	clientSocket.init(port);
	pollfds.push_back( (struct pollfd){clientSocket.getSocketFd(), POLLIN, 0} );
	while (poll(&pollfds[0], pollfds.size(), -1))
	{   
		for (int i = 0; i < pollfds.size(); i++)
		{
			if(pollfds[i].revents & POLLIN)
			{
				if (pollfds[i].fd == clientSocket.getSocketFd())// Connected to socket
				{   /**
					* It will check if a new connection is established, and if there is a new connection, 
					 - it will enter the function and call accept.
					* How does it detect a new connection? 
					*/
					int	 clientFd =  clientSocket.Accept();

					fcntl(clientFd, F_SETFL, O_NONBLOCK);
					pollfds.push_back( (struct pollfd){clientFd, POLLIN | POLLOUT} );
					users::getOrCreateUser(clientFd, this->users);
				}
				else // Connected to client
				{
					char	input[512] = {0};
					int	 readed = recv(pollfds[i].fd, input, sizeof(input) - 1,  0);

					if (readed <= 1)
					{
						close(pollfds[i].fd);
						users::deleteUser(pollfds[i].fd, this->users);
					}
					handleInput(pollfds[i].fd, string(input));
				}
			}
		}
	}
	exit (0);
}

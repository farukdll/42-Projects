#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <Person.hpp>
#include <DefineMod.hpp>

class Socket
{
	private:
		int			fd_socket;
		sockaddr_in	connect_int; // Getting the address and port information to which the socket will connect

	public:
		Socket();
		~Socket();

		bool	init(int por);
		bool	Create(int port);
		bool	Bind();
		bool	Listen();
		int		Accept();
		bool	Connect(string &ipAdress);
		bool	Send(string &message);
		void	SetNonBlocking(bool isNonBlocking);
		int		Receive(string &message);
		void	Close();

		int	 getSocketFd();
};

#endif

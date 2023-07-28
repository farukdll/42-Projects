#include "../inc/Socket.hpp"

int MAX_CLIENT = 50;

/*
The reason for initializing the file descriptor (fd) 
value to 0 here is to be able to determine if the socket is not created or if there is an error. 
Because when a socket is created, the variable fd_socket will already hold the file descriptor of the assigned socket.
*/
Socket::Socket() : fd_socket(0) {}

/*
It was a logical move to directly call the close function in the destructor, 
as the socket needs to be closed when it is destroyed.
*/
Socket::~Socket()
{
	Close();
}

/*
The function will check whether the socket was successfully created or not, 
and the returned value will enable the use of the created socket or the application of necessary error handling.
*/
bool Socket::Create(int port)
{
	int opt = 1;// ???

	fd_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (fd_socket == -1)
	{
		perror("Socket function doesn't work");
		exit (EXIT_FAILURE);
	}
	/*
		It states that reuse allows the reuse of resources obtained from inside or outside. In some older PCs, 
		there could be issues with port allocation during socket creation when connecting ports together. 
		To avoid any problems while connecting the ports, a pipe example is used for this check.
	*/
	if (setsockopt(fd_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	connect_int.sin_family = AF_INET;
	connect_int.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	connect_int.sin_port = htons(port);
	return (fd_socket != -1);
}

/*
	The function we will use to bind a socket with the port obtained from the argument.
*/
bool Socket::Bind()
{
	return (bind(fd_socket, (struct sockaddr *)&connect_int, sizeof(connect_int)) != -1);
}

bool Socket::Listen()
{
	return (listen(fd_socket, MAX_CLIENT) != -1);
}

int Socket::Accept()
{
	socklen_t clientSize = sizeof(connect_int); // It enters the loop and waits for data to be received.

	return (accept(fd_socket, (struct sockaddr *)&connect_int, (socklen_t *)&clientSize));
}

bool Socket::Connect(string &ipAdress)
{
	inet_pton(AF_INET, ipAdress.c_str(), &(connect_int.sin_addr)); // It converts the given IP address into binary format.
//	Inet_ntoa" can be used instead, as I couldn't find permission for "inet_pton".
	return (connect(fd_socket, (sockaddr *)&connect_int, sizeof(connect_int)) != -1);
}

bool Socket::Send(string &message)
{
	int sendResult = send(fd_socket, message.c_str(), message.size(), 0);

	return (sendResult != -1);
}

// ------------ Emin değiliz çalıştırılması gerek
// The poll() function identifies those file descriptors on which an application can read or write data, or on which an error event has occurred.
void Socket::SetNonBlocking(bool isNonBlocking)
{
	struct pollfd pfd;

	pfd.fd = fd_socket;
	pfd.events = POLLIN | POLLOUT; // To monitor the listening and writing events

	int timeout = 0; // To call poll without a timeout

	if (isNonBlocking)
		pfd.revents = 0; // If we don't reset the returned events here, poll retains the events from the previous call.

   // if (poll(&pfd, 1, timeout) == -1)
	 //   perror("poll() fail");
}

/*
It is used to receive data from the socket. 
It stores the incoming data into the 'message' parameter and returns the number of bytes received.

By using it, we can determine if we have received the complete data or if we need to receive more data.

If the byte count is 0, it can indicate that the connection has been closed or that we haven't received any data.
*/

bool Socket::init(int port)
{
	Create(port);
	if (getSocketFd() < 0)
	{
		cout << "Cannot open the socket file " << endl;
		return false;
	}
	Bind();
	Listen();
	return true;
}

int Socket::Receive(string &message)
{
	char buffer[4096] = {0};

	int bytesRead = recv(fd_socket, buffer, sizeof(buffer) - 1, 0);

	if (bytesRead > 0)
		message = buffer;
	return bytesRead;
}

void Socket::Close()
{
	if (fd_socket != 0)
	{
		close(fd_socket);
		fd_socket = 0;
	}
}

int Socket::getSocketFd()
{
	return this->fd_socket;
}

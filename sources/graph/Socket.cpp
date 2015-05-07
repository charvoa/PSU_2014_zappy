//
// Socket.cpp for Zappy in /home/nicolas/socketcpp
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May  6 13:12:01 2015 Nicolas Girardot
// Last update Thu May  7 10:31:27 2015 Nicolas Girardot
//

#include "Socket.hh"

Socket::Socket(const char *ip, const int port) : _ip(ip), _port(port)
{

}

Socket::~Socket()
{

}

void	Socket::initSocket()
{
  this->_proto = getprotobyname("TCP");
  _socket = socket(AF_INET, SOCK_STREAM, this->_proto->p_proto);
  _s_in.sin_family = AF_INET;
  this->_s_in.sin_addr.s_addr = inet_addr(this->_ip);
  this->_s_in.sin_port = htons(_port);
}

void	Socket::connectSocket()
{
  connect(this->_socket, (const struct sockaddr *)&(this->_s_in), sizeof(_s_in));
}

void	Socket::my_connect()
{
  int	fd;

  FD_ZERO(&_rfds);
  FD_ZERO(&_wfds);
  FD_SET(STDIN_FILENO, &_rfds);
  FD_SET(_socket, &_rfds);
  FD_SET(_socket, &_rfds);
  if (_socket == -1)
    fd = STDERR_FILENO;
  else
    fd = _socket;
  select(fd + 1, &_rfds, &_wfds, NULL, NULL);
}

void	Socket::selectSocket()
{
  std::stringstream readd;
  const std::string tmp;
  char *end_of_put;
  char buffer[4096];

  while (42)
    {
      my_connect();
      if (FD_ISSET(STDIN_FILENO, &this->_rfds))
	{
	  if (fgets(buffer, 4096, stdin))
	    {
	      if ((end_of_put = (strchr(buffer, '\n'))))
		buffer[end_of_put - buffer] = '\0';
	    }
	  write(_socket, buffer, strlen(buffer));
	}
      else if (FD_ISSET(this->_socket, &_rfds))
	{
	  readd << _socket;
	  std::cout << readd << std::endl;
	}
    }
}

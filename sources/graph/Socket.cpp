//
// Socket.cpp for Zappy in /home/nicolas/socketcpp
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May  6 13:12:01 2015 Nicolas Girardot
// Last update Tue May 26 19:41:27 2015 Nicolas Girardot
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

  this->initSocket();
  this->connectSocket();
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
  int connected = 0;

  while (42)
    {
       if (connected == 0)
	 {
	   write(_socket, "graph_cli_connected\n", strlen("graph_cli_connected\n"));
	   connected = 1;
	 }
      my_connect();
      if (FD_ISSET(STDIN_FILENO, &this->_rfds));
      else if (FD_ISSET(this->_socket, &_rfds))
	{
	  readd << _socket;
	}
    }
}

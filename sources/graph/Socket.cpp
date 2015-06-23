//
// Socket.cpp for Zappy in /home/nicolas/socketcpp
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May  6 13:12:01 2015 Nicolas Girardot
// Last update Mon Jun 22 15:12:00 2015 Nicolas Girardot
//

#include "Socket.hh"

Socket::Socket(const char *ip, const int port) : _ip(ip), _port(port)
{
  this->initSocket();
  this->connectSocket();
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
  FD_SET(this->_socket, &_rfds);
  FD_SET(this->_socket, &_wfds);
  if (_socket == -1)
    fd = STDERR_FILENO;
  else
    fd = _socket;
  select(fd +  1, &_rfds, &_wfds, NULL, NULL);
}

void	Socket::selectSocket()
{
  if (_connected == 0)
    {
      write(_socket, "graph_cli_connected\n", strlen("graph_cli_connected\n"));
      _connected = 1;
    }
  my_connect();
  if (FD_ISSET(this->_socket, &_rfds))
    {
      std::cout << "test" << std::endl;
      _read << _socket;
    }
}

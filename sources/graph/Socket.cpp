//
// Socket.cpp for Zappy in /home/nicolas/socketcpp
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May  6 13:12:01 2015 Nicolas Girardot
// Last update Sat Jul  4 14:08:08 2015 Nicolas Girardot
//

#include "Socket.hh"

Socket::Socket(const char *ip, const int port, GameEngine *game) : _ip(ip), _port(port)
{
  this->_cmd = new Command();
  this->initSocket();
  this->_game = game;
  this->connectSocket();
}

Socket::~Socket()
{

}

void	Socket::closeSocket()
{
  close(_socket);
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
  std::string output(150000, 0);
  std::string div;
  my_connect();
  if (FD_ISSET(this->_socket, &_rfds))
    {
      if (read(this->_socket, &output[0], 149999) <= 0)
	exit (0);
      std::istringstream dd(output);
      while (std::getline(dd, div, '\n'))
	     _cmd->Parse(div, _game);
    }
}

void	Socket::writeOnSocket(std::string message)
{
  write(_socket, message.c_str(), strlen(message.c_str()));
}

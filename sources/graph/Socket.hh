//
// Socket.hh for zappy in /home/nicolas/socketcpp
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May  6 13:12:07 2015 Nicolas Girardot
// Last update Thu Jun 25 18:33:28 2015 Nicolas Girardot
//

#ifndef SOCKET_HH_
# define SOCKET_HH_

# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <netdb.h>
# include <fstream>
# include <iostream>
# include <string>
# include <sstream>
# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/socket.h>
# include "Command.hh"
# include "GameEngine.hh"

class GameEngine;
class Command;

class Socket
{
private:
  GameEngine		*_game;
  Command		*_cmd;
  fd_set		_rfds;
  fd_set		_wfds;
  struct protoent	*_proto;
  struct sockaddr_in	_s_in;
  int			_socket;
  const	char		*_ip;
  const	int		_port;
  std::stringstream	_read;
  int			_connected = 0;
public:
  Socket(const char *ip, const int port, GameEngine *);
  ~Socket();
  void	initSocket();
  void	connectSocket();
  void	closeSocket();
  void	selectSocket();
  void	my_connect();
  void	writeOnSocket(std::string);
};

#endif

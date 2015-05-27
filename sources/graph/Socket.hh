//
// Socket.hh for zappy in /home/nicolas/socketcpp
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May  6 13:12:07 2015 Nicolas Girardot
// Last update Tue May 26 19:41:55 2015 Nicolas Girardot
//

#ifndef SOCKET_HH_
# define SOCKET_HH_

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <netdb.h>
# include <iostream>
# include <string>
# include <sstream>
# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/socket.h>

class Socket
{
private:
  fd_set		_rfds;
  fd_set		_wfds;
  struct protoent	*_proto;
  struct sockaddr_in	_s_in;
  int			_socket;
  const	char		*_ip;
  const	int		_port;
public:
  Socket(const char *ip, const int port);
  ~Socket();
  void	initSocket();
  void	connectSocket();
  void	selectSocket();
  void	my_connect();
};

#endif

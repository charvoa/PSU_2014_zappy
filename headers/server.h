/*
** server.h for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/headers
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sun May  3 11:28:52 2015 Serge Heitzler
** Last update Sun May  3 17:47:57 2015 Serge Heitzler
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/socket.h>
# include "list.h"

# define RED "\x1b[31m"
# define BLUE "\x1b[36m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define RESET "\x1b[0m"

typedef enum e_rock
  {
    LIMEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  }		e_rock;

typedef enum e_orientation
  {
    UP,
    RIGHT,
    DOWN,
    LEFT
  }		e_orientation;

typedef struct s_player
{
  char		*team;
  int		level;
  e_orientation	orientation;
}		t_player;

typedef struct	s_client
{
  int		fd;
  char		*team_name;
  t_player	**player;
  // list de player
}		t_client;

typedef struct s_map
{
  int		width;
  int		height;
  char		**plan;
}		t_map;

typedef struct		s_serv_info
{
  struct protoent	*proto;
  struct sockaddr_in	s_in;
  int			socket;
}			t_serv_info;

typedef struct s_server
{
  int		port;
  int		fd_max;
  int		graph_launched;
  int		nbr_max_client_by_team;
  int       	delay;
  char		**teams_names;
  t_serv_info	serv_info;
  fd_set	readfds;
  fd_set	writefds;
  // List de client
}		t_server;

#endif /* !SERVER_H_ */

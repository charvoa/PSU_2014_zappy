/*
** server.h for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/headers
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sun May  3 11:28:52 2015 Serge Heitzler
** Last update Thu May  7 11:32:25 2015 Serge Heitzler
*/

#ifndef			SERVER_H_
# define		SERVER_H_

# include		<stdio.h>
# include		<stdlib.h>
# include		<string.h>
# include		<unistd.h>
# include		<sys/types.h>
# include		<sys/socket.h>
# include		<sys/select.h>
# include		<netinet/in.h>
# include		<arpa/inet.h>
# include		<sys/stat.h>
# include		<fcntl.h>
# include		<limits.h>
# include		<signal.h>

# define		RED "\x1b[31m"
# define		BLUE "\x1b[36m"
# define		GREEN "\x1b[32m"
# define		YELLOW "\x1b[33m"
# define		RESET "\x1b[0m"

typedef enum		e_rock
  {
    LIMEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  }			e_rock;

typedef enum		e_orientation
  {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    NONE
  }			e_orientation;

typedef struct		s_food
{
  int			pos_x;
  int			pos_y;
  e_orientation		orientation;
}			t_food;

typedef struct		s_player
{
  char			*team;
  int			level;
  int			pos_x;
  int			pos_y;
  e_orientation		orientation;
}			t_player;

typedef struct	s_client
{
  int			fd;
  int			nbr_players;
  char			*team_name;
  t_list		*players;
}			t_client;

typedef struct s_map
{
  int			width;
  int			height;
  char			**full;
  t_list		**objects;
}			t_map;

typedef struct		s_serv_info
{
  struct protoent	*proto;
  struct sockaddr_in	s_in;
  int			socket;
}			t_serv_info;

typedef struct s_server
{
  fd_set		master;
  fd_set		read_fds;
  struct sockaddr_in	serveraddr;
  struct sockaddr_in	clientaddr;
  int			fdmax;
  int			listener;
  int			newfd;
  char			*buf;
  int			addrlen;
  char			**args;
  int			i;
  char			*home;


  int			graph_launched;
  unsigned int		nbr_max_client_by_team;
  unsigned int		delay;
  char			**teams_names;
  t_map			*map;
  t_list		*clients;
}			t_server;

extern	int		g_verbose;
extern	int		g_listener;
extern	int		g_fdmax;

int			xsocket(int, int, int);
void			xbind(int, const struct sockaddr*, socklen_t);
void			xlisten(int, int);
void			init_socket(t_server*);
void			bind_socket(t_server*, int);
void			accept_server(t_server*, char**);
void			read_write_server(t_server*, int, char**);
void			my_printf(const char *, ...);

#endif /* !SERVER_H_ */

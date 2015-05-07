/*
** server.h for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/headers
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sun May  3 11:28:52 2015 Serge Heitzler
** Last update Thu May  7 15:25:51 2015 Audibert Louis
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
# include		"list.h"
# include		"xfuncs.h"

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
  unsigned int	       	width; // -x
  unsigned int	       	height; // -y
  char			**full;
  t_list		**objects;
}			t_map;

typedef struct s_server
{
  // Loulou's Work
  unsigned int		port; // -p
  char			**team_names; // -n
  unsigned int		nb_max_clients_by_team; // -c
  unsigned int		time_action; // -t
  char			*optarg;
  int			opt;

  // Charvo's struct
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

  // Pontoise's Work
  int			graph_launched;
  //  char			**teams_names;
  t_map			*map;
  t_list		*clients;
}			t_server;

extern	int		g_verbose;
extern	int		g_listener;
extern	int		g_fdmax;

void			init_socket(t_server*);
void			bind_socket(t_server*, int);
void			accept_server(t_server*, char**);
void			read_write_server(t_server*, int, char**);
void			my_printf(const char *, ...);

/* SET_OPTIONS.C */

void			init_opt(int (*options[5])(t_server *s));
int			check_cmd(int opt);
void			exec_option(t_server *s);

/* OPTIONS.C */

int			is_number(char *str);
int			opt_port(t_server *s);
int			opt_teams(t_server *s);
int			opt_nb_client(t_server *s);
int			opt_time_action(t_server *s);

/* OPTIONS2.C */

int			opt_x_map(t_server *s);
int			opt_y_map(t_server *s);
int			opt_verbose(t_server *s);

/* WRITE_TO_CLIENT.C */
void			write_to_client(t_server *, char *);

/* CREATE_MAP.C */
void			init_map(t_map *, unsigned int, unsigned int);
char			**init_full_tab(int);

/* EXEC_CMD.C */
void			exec_cmd(t_server *s);

#endif /* !SERVER_H_ */

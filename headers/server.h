/*
** server.h for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/headers
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sun May  3 11:28:52 2015 Serge Heitzler
** Last update Wed Jul  1 13:41:45 2015 Audibert Louis
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
# include		<math.h>
# include		<time.h>
# include		"list.h"
# include		"ring_buffer.h"
# include		"xfuncs.h"
# include		"position.h"
# include		"egg.h"
# include		"client.h"
# include		"map.h"
# include		"ressources.h"

# define		RED "\x1b[31m"
# define		BLUE "\x1b[36m"
# define		GREEN "\x1b[32m"
# define		YELLOW "\x1b[33m"
# define		RESET "\x1b[0m"
# define		NO -1
# define		YES 0
# define		ERROR -1
# define		SUCCESS 0

typedef enum		e_bool
  {
    TRUE,
    FALSE
  }			e_bool;

typedef struct		s_incantation
{
  int			player;
  int			linemate;
  int		        deraumere;
  int			sibur;
  int			mendiane;  
  int			phiras;
  int		        thystame;
}			t_incantation;

typedef struct		s_cmds
{
  char			*name;
  int			(*ptr_func)();
  float			delay;
}			t_cmds;

typedef struct		s_cmd
{
  /* "delay" à diviser par t au moment du calcul
     du delay si changement de t par le client */
  char		       	*label;
  long			delay;
  struct timespec       exec_at;
  long			precision;
}			t_cmd;

typedef struct		s_opt
{
  char			*optarg;
  int			opt;
  int			optind;
  int			argc;
  char			**argv;
}			t_opt;

typedef struct		s_server
{
  // Loulou's Work
  unsigned int		port; // -p
  float			time_action; // -t
  t_opt			*o;
  int			map_set[2];

  // Charvo's struct
  fd_set		master;
  fd_set		read_fds;
  struct sockaddr_in	serveraddr;
  struct sockaddr_in	clientaddr;
  int			fdmax;
  int			listener;
  int			newfd;
  int			addrlen;
  char			*home;

  // Pontoise's Work
  t_map			*map;
  t_list		*clients;
  t_list		*teams;
  t_list		*eggs;
  struct timespec      	now;
}			t_server;

extern int		g_verbose;
extern int		g_listener;
extern int		g_fdmax;
extern t_objects	g_objects[8];
extern t_cmds		g_cmds[23];
extern t_incantation   	g_incantation[7];

#endif /* !SERVER_H_ */

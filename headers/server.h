/*
** server.h for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/headers
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sun May  3 11:28:52 2015 Serge Heitzler
** Last update Thu May 21 22:11:11 2015 Serge Heitzler
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
# include		"xfuncs.h"

# define		RED "\x1b[31m"
# define		BLUE "\x1b[36m"
# define		GREEN "\x1b[32m"
# define		YELLOW "\x1b[33m"
# define		RESET "\x1b[0m"
# define		ERROR -1
# define		SUCCESS 0

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
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3,
    NONE
  }			e_orientation;

typedef enum		e_bool
  {
    TRUE,
    FALSE
  }			e_bool;

typedef struct		s_position
{
  unsigned int		x;
  unsigned int		y;
}			t_position;

typedef struct		s_food
{
  t_position		*pos;
  e_orientation		orientation;
}			t_food;

typedef struct	s_client
{
  int			fd;
  char			*team_name;
  unsigned int		level;
  t_position		*pos;
  t_list		*inventory;
  e_orientation		orientation;
  t_list		*players;
}			t_client;

typedef struct s_size
{
  unsigned int	       	width; // -x
  unsigned int	       	height; // -y  
}		t_size;

typedef struct s_map
{
  t_size		*size;
  char			**full;
  t_list		***objects;
}			t_map;

typedef struct s_teams
{
  char			**team_names; // -n
  int			len_names;
  unsigned int		nb_max_clients_by_team; // -c
  int			slot_rest;
}			t_teams;

typedef struct s_opt
{
  char			*optarg;
  int			opt;
  int			optind;
  int			argc;
  char			**argv;
}		t_opt;

typedef struct s_server_graph
{
  e_bool	connected;
  int		fd;
}		t_server_graph;

typedef struct s_server
{
  // Loulou's Work
  unsigned int		port; // -p
  t_teams		*teams; // -n -c
  unsigned int		time_action; // -t
  t_opt			*o;
  char			**tab;

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
  t_map			*map;
  t_list		*clients;
  t_server_graph	*graph;
}			t_server;

extern	int		g_verbose;
extern	int		g_listener;
extern	int		g_fdmax;

void			init_socket(t_server*);
void			bind_socket(t_server*, int);
void			accept_server(t_server*, char**);
void			read_write_server(t_server*, int, char**);
void			my_printf(const char *, ...);

/* $(CMDIA)CMD_LEFT.C */
void			cmd_left(t_server *, t_client *);

/* $(CMDIA)CMD_RIGHT.C */
void			cmd_right(t_server *, t_client *);

/* $(CMDIA)CMD_ADVANCE.C */
void			cmd_advance(t_server *, t_client *);
void			init_advance(void (*advance[4])(t_size *, t_client *));

/* $(CMDIA)ADVANCE_FUNCS.C */
void			adv_up(t_size *, t_client *);
void			adv_right(t_size *, t_client *);
void	       		adv_down(t_size *, t_client *);
void			adv_left(t_size *, t_client *);

/* CREATE_CLIENT.C */
void			init_orientation(void(*orientation[4])(t_client *));
void			create_client(t_client *, int, char *, t_size *);

/* CREATE_MAP.C */
void			init_map(t_server *, unsigned int, unsigned int);
char			**init_full_tab(int, int);

/* COMMANDS.C */
int			cmd_team(t_server *);

/* DISTANCES.C */
unsigned int   		calcul_length(unsigned int, unsigned int, t_map *);
unsigned int   		calcul_width(unsigned int, unsigned int, t_map *);
float			calcul_distance(int, int);
unsigned int		calcul_limit(unsigned int);
float			give_me_distance(t_map *, t_position *, t_position *);

/* EXEC_CMD.C */
void			exec_cmd(t_server *);

/* MY_STR_TO_WORDTAB.C */
int			my_count_word(char *);
int			my_count_char(char *, int *);
char			**my_str_to_wordtab(char *);
void			show_error(char *);

/* OPTIONS.C */
int			is_number(char *);
int			opt_port(t_server *);
int			opt_teams(t_server *);
int			opt_nb_client(t_server *);
int			opt_time_action(t_server *);

/* OPTIONS2.C */
int			opt_width_map(t_server *);
int			opt_height_map(t_server *);
int			opt_verbose(t_server *);

/* RAND_ORIENTATIONS.C */
void			ori_up(t_client *);
void			ori_right(t_client *);
void	       		ori_down(t_client *);
void			ori_left(t_client *);

/* SERVER.C */
void			handler_ctrl_c(int);
void			loop_server(t_server *, char**);
void			init_opt_server(t_server *);
t_server		*fill_struct_serv(int, char **);

/* SEND_DATA.C */
int			send_data(int, const char *);

/* SET_OPTIONS.C */
void			init_opt(int (*options[6])(t_server *));
int			check_opt(int);
void			exec_option(t_server *, int (*options[6])(t_server *));

/* TMP */
char			**parser(char **, char *);

/* WRITE_TO_CLIENT.C */
void			write_to_client(t_server *, char *);

#endif /* !SERVER_H_ */

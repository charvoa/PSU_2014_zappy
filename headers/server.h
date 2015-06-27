/*
** server.h for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/headers
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sun May  3 11:28:52 2015 Serge Heitzler
** Last update Sat Jun 27 10:58:04 2015 Audibert Louis
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

typedef struct		s_cmds
{
  char			*name;
  int			(*ptr_func)();
  int			delay;
}			t_cmds;

typedef struct		s_cmd
{
  /* "delay" à diviser par t au moment du calcul
     du delay si changement de t par le client */
  const char	       	*label;
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
  t_list		*teams;
  struct timespec      	now;
}			t_server;

extern int		g_verbose;
extern int		g_listener;
extern int		g_fdmax;
extern t_objects	g_objects[8];
extern t_cmds		g_cmds[22];

/* void			init_socket(t_server*); */
/* void			bind_socket(t_server*, int); */
/* void			accept_server(t_server*, char**); */
/* void			read_write_server(t_server*, int, char**); */
/* void			my_printf(const char *, ...); */

/* int			cmd_left(t_server *, t_client *, const char *); */
/* int			cmd_right(t_server *, t_client *, const char *); */
/* int			cmd_advance(t_server *, t_client *, const char *); */
/* int			cmd_view(t_server *, t_client *, const char *); */
/* int			cmd_inventory(t_server *, t_client *, const char *); */
/* int			cmd_take_object(t_server *, t_client *, const char *); */
/* int			cmd_drop_object(t_server *, t_client *, const char *); */
/* int			cmd_kick(t_server *, t_client *, const char *); */
/* int			cmd_incantation(t_server *, t_client *, const char *); */
/* int			cmd_fork(t_server *, t_client *, const char *); */
/* int			cmd_dead(t_server *, t_client *, const char *); */
/* int			cmd_broadcast(t_server *, t_client *, const char *); */
/* int			cmd_msz(t_server *, t_client *, const char *); */
/* int			cmd_sgt(t_server *, t_client *, const char *); */
/* int			cmd_sst(t_server *, t_client *, const char *); */
/* int			cmd_tna(t_server *, t_client *, const char *); */
/* int			cmd_bct(t_server *, t_client *, const char *); */
/* int			cmd_mct(t_server *, t_client *, const char *); */
/* int			cmd_ppo(t_server *, t_client *, const char *); */
/* int			cmd_plv(t_server *, t_client *, const char *); */
/* int			cmd_pin(t_server *, t_client *, const char *); */

/* int			is_cmd(const char *); */
/* void			exec_cmd(t_server *, t_client *); */

/* void			set_slot_for_team(t_list *, char *, int); */
/* char			*get_objects_from_inventory(t_inventory *); */
/* int			get_nbr_of_rock(e_rock_type, t_list *); */
/* void			init_advance(void (*advance[4])(t_size *, t_client *)); */
/* int			istm(int); */
/* t_client		*get_client_by_id(t_list *, int); */
/* t_team			*get_team_by_name(t_list *, char *); */
/* char			*get_team_name_at_index(t_list *, int); */
/* int			size_of_tab(char **); */
/* char			*show_items_at_position(t_server *, int, int); */
/* int			get_size_malloc_at_position(t_server *, int, int); */
/* int			create_food(t_server *); */
/* int			create_rock(t_server *); */
/* void			prepare_for_exec(t_server *, t_client *); */

/* /\* $(CMD)ADD_OR_REMOVE_ID.C *\/ */
/* int			*add_id(t_block *block, int id); */
/* int			*remove_id(t_block *block, int id); */

/* /\* $(CMD)ADVANCE_FUNCS.C *\/ */
/* void			adv_up(t_size *, t_client *); */
/* void			adv_right(t_size *, t_client *); */
/* void	       		adv_down(t_size *, t_client *); */
/* void			adv_left(t_size *, t_client *); */

/* /\* $(CMD)CMD_CONNECT_NBR.C *\/ */
/* int			cmd_connect_nbr(t_server *, t_client *, const char *); */

/* /\* $(CMD)CMD_TAKE_OBJECT.C *\/ */
/* int			check_rock(char *rock); */
/* int			remove_rock(t_node *tmp, t_list *list, int rock_type, int index); */
/* int			take_rock(t_server *s, t_client *c, char *item); */
/* int			take_food(t_server *s, t_client *c); */
/* int			cmd_take_object(t_server *s, t_client *c, const char *cmd); */

/* /\* $(CMD)CMD_DROP_OBJECT.C *\/ */
/* int			launch_func_inventory(t_client *, int, e_flag_rock); */
/* int			launch_func_block(t_block *, int, e_flag_rock); */

/* /\* $(CMD)INVENTORY_ROCK.C *\/ */
/* int			inventory_limemate(t_inventory *, e_flag_rock); */
/* int			inventory_deraumere(t_inventory *, e_flag_rock); */
/* int			inventory_sibur(t_inventory *, e_flag_rock); */

/* /\* $(CMD)INVENTORY_ROCK2.C *\/ */
/* int			inventory_mendiane(t_inventory *, e_flag_rock); */
/* int			inventory_phiras(t_inventory *, e_flag_rock); */
/* int			inventory_thystame(t_inventory *, e_flag_rock); */

/* /\* $(CMD)BLOCK_ROCK.C *\/ */
/* int			block_limemate(t_block *, e_flag_rock); */
/* int			block_deraumere(t_block *, e_flag_rock); */
/* int			block_sibur(t_block *, e_flag_rock); */

/* /\* $(CMD)BLOCK_ROCK2.C *\/ */
/* int			block_mendiane(t_block *, e_flag_rock); */
/* int			block_phiras(t_block *, e_flag_rock); */
/* int		       	block_thystame(t_block *, e_flag_rock); */

/* /\* $(CMD)CMD_TEAM *\/ */
/* int	is_a_team(t_server *, char *); */
/* void	validate_team(t_team *, t_client *, char *); */
/* int	cmd_team(t_server *, t_client *, const char *); */

/* /\* COUNT_TEAMS.C *\/ */
/* int			count_teams(t_server *); */

/* /\* CREATE_CLIENT.C *\/ */
/* void			init_orientation(void(*orientation[4])(t_client *)); */
/* int			create_client(t_server *, int, char *, t_size *); */

/* /\* CREATE_MAP.C *\/ */
/* void			init_map(t_server *, unsigned int, unsigned int); */
/* char			**init_full_tab(int, int); */

/* /\* CREATE_TEAM.C *\/ */
/* t_team			*create_team(t_server *s, char *name, int nb_max); */


/* /\* COMMANDS.C *\/ */
/* int			cmd_team(t_server *, t_client *, const char *); */

/* /\* DETERMINE_POS.C *\/ */
/* int			determine_pos_x(t_client *, t_size *, int, int); */
/* int			determine_pos_y(t_client *, t_size *, int, int); */

/* /\* DISTANCES.C *\/ */
/* unsigned int   		calcul_length(unsigned int, unsigned int, t_map *); */
/* unsigned int   		calcul_width(unsigned int, unsigned int, t_map *); */
/* float			calcul_distance(int, int); */
/* unsigned int		calcul_limit(unsigned int); */
/* float			give_me_distance(t_map *, t_position *, t_position *); */

/* /\* MY_STR_TO_WORDTAB.C *\/ */
/* int			my_count_word(char *); */
/* int			my_count_char(char *, int *); */
/* char			**my_str_to_wordtab(char *); */
/* void			show_error(char *); */

/* /\* OPTIONS.C *\/ */
/* int			is_number(char *); */
/* int			opt_port(t_server *); */
/* int			opt_teams(t_server *); */
/* int			opt_nb_client(t_server *); */
/* int			opt_time_action(t_server *); */

/* /\* OPTIONS2.C *\/ */
/* int			opt_width_map(t_server *); */
/* int			opt_height_map(t_server *); */
/* int			opt_verbose(t_server *); */

/* /\* RAND_ORIENTATIONS.C *\/ */
/* void			ori_up(t_client *); */
/* void			ori_right(t_client *); */
/* void	       		ori_down(t_client *); */
/* void			ori_left(t_client *); */

/* /\* SERVER.C *\/ */
/* void			handler_ctrl_c(int); */
/* void			loop_server(t_server *, char**); */
/* void			init_opt_server(t_server *); */
/* t_server		*fill_struct_serv(int, char **); */

/* /\* SEND_DATA.C *\/ */
/* int			send_data(int, const char *); */
/* int			send_data_to_gui(t_list *clients, const char *msg); */
/* /\* SET_OPTIONS.C *\/ */
/* void			init_opt(int (*options[6])(t_server *)); */
/* int			check_opt(int); */
/* void			exec_option(t_server *, int (*options[6])(t_server *)); */

/* /\* TMP *\/ */

/* void			parser(t_server *, char *); */

/* /\* WRITE_TO_CLIENT.C *\/ */
/* void			write_to_client(t_server *, char *); */
=======
void			init_socket(t_server*);
void			bind_socket(t_server*, int);
void			accept_server(t_server*, char**);
void			read_write_server(t_server*, int, char**);
void			my_printf(const char *, ...);

int			cmd_left(t_server *, t_client *, const char *);
int			cmd_right(t_server *, t_client *, const char *);
int			cmd_advance(t_server *, t_client *, const char *);
int			cmd_view(t_server *, t_client *, const char *);
int			cmd_inventory(t_server *, t_client *, const char *);
int			cmd_take_object(t_server *, t_client *, const char *);
int			cmd_drop_object(t_server *, t_client *, const char *);
int			cmd_kick(t_server *, t_client *, const char *);
int			cmd_incantation(t_server *, t_client *, const char *);
int			cmd_fork(t_server *, t_client *, const char *);
int			cmd_dead(t_server *, t_client *, const char *);
int			cmd_broadcast(t_server *, t_client *, const char *);
int			cmd_msz(t_server *, t_client *, const char *);
int			cmd_sgt(t_server *, t_client *, const char *);
int			cmd_sst(t_server *, t_client *, const char *);
int			cmd_tna(t_server *, t_client *, const char *);
int			cmd_bct(t_server *, t_client *, const char *);
int			cmd_mct(t_server *, t_client *, const char *);
int			cmd_ppo(t_server *, t_client *, const char *);
int			cmd_plv(t_server *, t_client *, const char *);
int			cmd_pin(t_server *, t_client *, const char *);

int			is_cmd(const char *);
void			exec_cmd(t_server *, t_client *);

void			set_slot_for_team(t_list *, char *, int);
char			*get_objects_from_inventory(t_inventory *);
int			get_nbr_of_rock(e_rock_type, t_list *);
void			init_advance(void (*advance[4])(t_size *, t_client *));
int			istm(int);
t_client		*get_client_by_id(t_list *, int);
t_team			*get_team_by_name(t_list *, char *);
char			*get_team_name_at_index(t_list *, int);
int			size_of_tab(char **);
char			*show_items_at_position(t_server *, int, int);
int			get_size_malloc_at_position(t_server *, int, int);
int			create_food(t_server *);
int			create_rock(t_server *);
void			prepare_for_exec(t_server *, t_client *);
int			check_exec(t_server *);

/* $(CMD)ADD_OR_REMOVE_ID.C */
int			*add_id(t_block *block, int id);
int			*remove_id(t_block *block, int id);

/* $(CMD)ADVANCE_FUNCS.C */
void			adv_up(t_size *, t_client *);
void			adv_right(t_size *, t_client *);
void	       		adv_down(t_size *, t_client *);
void			adv_left(t_size *, t_client *);

/* $(CMD)CMD_CONNECT_NBR.C */
int			cmd_connect_nbr(t_server *, t_client *, const char *);

/* $(CMD)CMD_TAKE_OBJECT.C */
int			check_rock(char *rock);
int			remove_rock(t_node *tmp, t_list *list, int rock_type, int index);
int			take_rock(t_server *s, t_client *c, char *item);
int			take_food(t_server *s, t_client *c);
int			cmd_take_object(t_server *s, t_client *c, const char *cmd);

/* $(CMD)CMD_DROP_OBJECT.C */
int			launch_func_inventory(t_client *, int, e_flag_rock);
int			launch_func_block(t_block *, int, e_flag_rock);

/* $(CMD)INVENTORY_ROCK.C */
int			inventory_limemate(t_inventory *, e_flag_rock);
int			inventory_deraumere(t_inventory *, e_flag_rock);
int			inventory_sibur(t_inventory *, e_flag_rock);

/* $(CMD)INVENTORY_ROCK2.C */
int			inventory_mendiane(t_inventory *, e_flag_rock);
int			inventory_phiras(t_inventory *, e_flag_rock);
int			inventory_thystame(t_inventory *, e_flag_rock);

/* $(CMD)BLOCK_ROCK.C */
int			block_limemate(t_block *, e_flag_rock);
int			block_deraumere(t_block *, e_flag_rock);
int			block_sibur(t_block *, e_flag_rock);

/* $(CMD)BLOCK_ROCK2.C */
int			block_mendiane(t_block *, e_flag_rock);
int			block_phiras(t_block *, e_flag_rock);
int		       	block_thystame(t_block *, e_flag_rock);

/* $(CMD)CMD_TEAM */
int			is_a_team(t_server *, char *);
void			validate_team(t_team *, t_client *, char *);
int			cmd_team(t_server *, t_client *, const char *);

/* COUNT_TEAMS.C */
int			count_teams(t_server *);

/* CREATE_CLIENT.C */
void			init_orientation(void(*orientation[4])(t_client *));
int			create_client(t_server *, int, char *, t_size *);

/* CREATE_MAP.C */
void			init_map(t_server *, unsigned int, unsigned int);
char			**init_full_tab(int, int);

/* CREATE_TEAM.C */
t_team			*create_team(t_server *s, char *name, int nb_max);


/* COMMANDS.C */
int			cmd_team(t_server *, t_client *, const char *);

/* DETERMINE_POS.C */
int			determine_pos_x(t_client *, t_size *, int, int);
int			determine_pos_y(t_client *, t_size *, int, int);

/* DISTANCES.C */
unsigned int   		calcul_length(unsigned int, unsigned int, t_map *);
unsigned int   		calcul_width(unsigned int, unsigned int, t_map *);
float			calcul_distance(int, int);
unsigned int		calcul_limit(unsigned int);
float			give_me_distance(t_map *, t_position *, t_position *);

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
int			send_data_to_gui(t_list *, const char *);

/* SET_OPTIONS.C */
void			init_opt(int (*options[6])(t_server *));
int			check_opt(int);
void			exec_option(t_server *, int (*options[6])(t_server *));

/* TMP */

void			parser(t_server *, char *);

/* WRITE_TO_CLIENT.C */
void			write_to_client(t_server *, char *);
>>>>>>> a2b9a0c5173c890f945535ea185c623f45a5bdad

#endif /* !SERVER_H_ */

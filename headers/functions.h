/*
** functions.h for zappy in /home/audibe_l/rendu/PSU_2014_zappy/headers
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Sat Jun 27 09:51:35 2015 Audibert Louis
** Last update Sat Jun 27 11:24:09 2015 Audibert Louis
*/

#ifndef _FUNCTIONS_H_
# define _FUNCTIONS_H_

# include		"server.h"

/* Function(s) in file check_exec.c */
int		check_exec(t_server *);

/* Function(s) in file count_teams.c */
int		count_teams(t_server *s);

/* Function(s) in file create_client.c */
void		init_orientation(void (*orientation[4])(t_client *));
void		init_inventory(t_client *c);
int		create_client(t_server *, int, char *, t_size *);

/* Function(s) in file create_cmd.c */
t_cmd		*create_cmd(const char *cmd);

/* Function(s) in file create_food.c */
int		create_food(t_server *s);

/* Function(s) in file create_map.c */
char		**init_full_tab(int width, int height);
void		init_map(t_server *s, unsigned int width, unsigned int height);

/* Function(s) in file create_objects.c */
int		create_objects(t_server *s);

/* Function(s) in file create_rock.c */
int		create_rock(t_server *s);

/* Function(s) in file create_team.c */
t_team		*create_team(t_server *s, char *name, int nb_max);

/* Function(s) in file distances.c */
unsigned int	calcul_length(unsigned int, unsigned int, t_map *);
unsigned int	calcul_width(unsigned int, unsigned int, t_map *);
float		calcul_distance(int w, int l);
unsigned int	calcul_limit(unsigned int len);
float		give_me_distance(t_map *map, t_position *f_pos, t_position *s_pos);

/* Function(s) in file my_printf.c */
void		my_printf(const char *format, ...);

/* Function(s) in file options.c */
int		is_number(char *str);
int		opt_port(t_server *s);
int		opt_teams(t_server *s);
int		opt_nb_client(t_server *s);
int		opt_time_action(t_server *s);

/* Function(s) in file options2.c */
int		opt_width_map(t_server *s);
int		opt_height_map(t_server *s);
int		opt_verbose(t_server *s);

/* Function(s) in file prepare_for_exec.c */
void		prepare_for_exec(t_server *s, t_client *c);

/* Function(s) in file rand_orientations.c */
void		ori_up(t_client *client);
void		ori_right(t_client *client);
void		ori_down(t_client *client);
void		ori_left(t_client *client);

/* Function(s) in file ring_buffer.c */
t_ring_buffer	*ring_buffer_create(int length);
void		ring_buffer_destroy(t_ring_buffer *buffer);
int		ring_buffer_write(t_ring_buffer *buffer, char *data, int length);
int		ring_buffer_read(t_ring_buffer *buffer, char *target, int amount);
char		*ring_buffer_gets(t_ring_buffer *buffer, int amount);
char		*ring_buffer_get_next_command(t_ring_buffer *buffer);
int		ring_buffer_expand(t_ring_buffer *buffer, int size);

/* Function(s) in file send_data.c */
int		send_data(int socket, const char *buffer);
int		send_data_to_gui(t_list *clients, const char *msg);

/* Function(s) in file server.c */
void		handler_ctrl_c(int sig);
void		check_death(t_server *s);
void		loop_server(t_server *s, char **argv);
char		**get_tab(int argc, char **argv);
void		init_opt_server(t_server *s);
t_server	*fill_struct_serv(int argc, char **argv);

/* Function(s) in file set_options.c */
void		init_opt(int (*options[6])(t_server *s));
int		check_opt(int opt);
void		exec_option(t_server *s, int (*options[6])(t_server *s));

/* Function(s) in file size_of_tab.c */
int		size_of_tab(char **tab);

/* Function(s) in file utilis.c */
void		init_socket(t_server *s);
void		bind_socket(t_server *s, int port);
void		protocole_connexion(t_server *s, int fd);
void		accept_server(t_server *s, char **argv);
void		read_write_server(t_server *s, int i, char **argv);

/* --------------------$(CMD)--------------------- */

/* Function(s) in file add_or_remove_id.c */
int		*add_id(t_block *block, int id);
int		*remove_id(t_block *block, int id);

/* Function(s) in file advance_funcs.c */
void		adv_up(t_size *size, t_client *client);
void		adv_right(t_size *size, t_client *client);
void		adv_down(t_size *size, t_client *client);
void		adv_left(t_size *size, t_client *client);

/* Function(s) in file block_rocks.c */
int		block_limemate(t_block *block, e_flag_rock flag);
int		block_deraumere(t_block *block, e_flag_rock flag);
int		block_sibur(t_block *block, e_flag_rock flag);

/* Function(s) in file block_rocks2.c */
int		block_mendiane(t_block *block, e_flag_rock flag);
int		block_phiras(t_block *block, e_flag_rock flag);
int		block_thystame(t_block *block, e_flag_rock flag);

/* Function(s) in file cmd_advance.c */
void		init_advance(void (*advance[4])(t_size *, t_client *));
int		cmd_advance(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_bct.c */
int		cmd_bct(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_broadcast.c */
char		*get_trame_broadcast(t_client *c, char *text);
void		get_text(char *text, const char *cmd);
int		cmd_broadcast(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_connect_nbr.c */
int		cmd_connect_nbr(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_dead.c */
int		cmd_dead(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_drop_object.c */
int		launch_func_inventory(t_client *c, int rock, e_flag_rock flag);
int		drop_rock(t_server *s, t_client *c, char *item);
int		drop_food(t_server *s, t_client *c);
int		cmd_drop_object(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_fork.c */
int		cmd_fork(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_incantation.c */
int		cmd_incantation(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_inventory.c */
char		*get_objects_from_inventory(t_inventory *i);
int		cmd_inventory(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_kick.c */
char		*get_trame_deplacement(t_client *c);
int		cmd_kick(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_left.c */
int		cmd_left(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_mct.c */
int		number_of_busy_space(t_server *s);
int		get_all_malloc_size(t_server *s);
int		cmd_mct(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_msz.c */
int		cmd_msz(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_plv.c */
int		cmd_plv(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_pin.c */
int		cmd_pin(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_ppo.c */
int		cmd_ppo(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_right.c */
int		cmd_right(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_sgt.c */
int		cmd_sgt(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_sst.c */
int		cmd_sst(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_take_object.c */
int		check_rock(char *rock);
int		launch_func_block(t_block *block, int rock_type, e_flag_rock flag);
int		take_rock(t_server *s, t_client *c, char *item);
int		take_food(t_server *s, t_client *c);
int		cmd_take_object(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_team.c */
int		is_a_team(t_server *s, char *team);
void		validate_team(t_team *team, t_client *c, char *name);
int		cmd_team(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_tna.c */
char		*get_all_teams_in_str(t_server *s);
int		cmd_tna(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file cmd_view.c */
int		get_number_of_visible_space(unsigned int level);
char		**write_pos_in_array(t_server *s, t_client *c, int i, int l);
char		**get_pos_of_visible_space(t_server *s, t_client *c);
char		*create_final_string_view(t_server *s, t_client *c, int, char **);
int		cmd_view(t_server *s, t_client *c, const char *cmd);

/* Function(s) in file determine_pos.c */
int		determine_pos_x(t_client *c, t_size *size, int t, int l);
int		determine_pos_y(t_client *c, t_size *size, int t, int l);

/* Function(s) in file int_size_to_malloc.c */
int		istm(int nb);

/* Function(s) in file inventory_rocks.c */
int		inventory_limemate(t_inventory *inventory, e_flag_rock flag);
int		inventory_deraumere(t_inventory *inventory, e_flag_rock flag);
int		inventory_sibur(t_inventory *inventory, e_flag_rock flag);

/* Function(s) in file inventory_rocks2.c */
int		inventory_mendiane(t_inventory *inventory, e_flag_rock flag);
int		inventory_phiras(t_inventory *inventory, e_flag_rock flag);
int		inventory_thystame(t_inventory *inventory, e_flag_rock flag);

/* Function(s) in file pointers_array.c */
int		is_cmd(const char *cmd);
void		exec_cmd(t_server *s, t_client *c);

/* Function(s) in file show_items_at_position.c */
int		*get_nb_items(t_block *block);
int		get_last_wrote(int *nb_items);
char		*fill_final_string(int size_malloc, int *nb_items);
int		get_size_malloc_at_position(t_server* s, int x, int y);
char		*show_items_at_position(t_server * s, int x, int y);

/* ---------------------$(LIST)--------------------- */

/* Function(s) in file create_list.c */
t_list		*create_list();

/* Function(s) in file free_list.c */
void		free_list(t_list *list);

/* Function(s) in file get_client_in_list.c */
t_client	*get_client_by_id(t_list *list, int id);

/* Function(s) in file get_nbr_of.c */
int		get_nbr_of_rock(e_rock_type type, t_list *list);
int		get_nbr_of(e_node_type type, t_list *list);

/* Function(s) in file get_node_at_index.c */
t_node		*get_node_at_index(t_list *list, size_t index);

/* Function(s) in file get_team_in_list.c */
char		*get_team_name_at_index(t_list *list, int index);
void		set_slot_for_team(t_list *list, char *type, int value);
t_team		*get_team_by_name(t_list *list, char *name);

/* Function(s) in file push_at_index.c */
int		push_at_index(t_list *list, void *data, e_node_type type, int index);

/* Function(s) in file push_back.c */
int		push_back(t_list *list, void *data, e_node_type type);

/* Function(s) in file push_front.c */
int		push_front(t_list *list, void *data, e_node_type type);

/* Function(s) in file remove_at_index.c */
int		remove_at_index(t_list *list, int index);

/* Function(s) in file remove_back.c */
int		remove_back(t_list *list);

/* Function(s) in file remove_front.c */
int		remove_front(t_list *list);

/* Function(s) in file show_list.c */
void		show_list(t_list *list);

/* Function(s) in file size_list.c */
size_t		size_list(t_list *list);

#endif /* _FUNCTIONS_H_ */

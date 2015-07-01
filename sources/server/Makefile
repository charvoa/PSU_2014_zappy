##
## Makefile for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
##
## Made by Serge Heitzler
## Login   <heitzl_s@epitech.net>
##
## Started on  Sun May  3 11:26:21 2015 Serge Heitzler
## Last update Tue Jun 30 17:55:43 2015 Antoine Garcia
##

CC		= 	gcc

RM		= 	rm -rf

CFLAGS		+= 	-W -Wall -Werror -Wextra -g3
CFLAGS		+= 	-I ../../headers/

EXTERNLIB	=	-lm

X_DIR		=	../xfuncs/

CMD_DIR		=	./cmd/

LIST_DIR	=	./list/

FREE_DIR	=	./free_cmd/

SRCS		= 	main.c	 				\
			ring_buffer.c				\
			count_teams.c				\
			create_map.c				\
			create_cmd.c				\
			create_client.c				\
			create_team.c				\
			create_objects.c			\
			protocole_connexion.c			\
			check_exec.c				\
			check_death.c				\
			distances.c				\
			my_printf.c				\
			options.c				\
			options2.c				\
			rand_orientations.c			\
			send_data.c				\
			set_options.c				\
			server.c				\
			utilis.c				\
			size_of_tab.c				\
			check_eggs.c				\
			width_and_length.c			\
			$(X_DIR)xmalloc.c	 		\
			$(X_DIR)xlisten.c	 		\
			$(X_DIR)xbind.c		 		\
			$(X_DIR)xsocket.c		 	\
			$(CMD_DIR)cmd_team.c			\
			$(CMD_DIR)cmd_connect_nbr.c		\
			$(CMD_DIR)cmd_right.c			\
			$(CMD_DIR)cmd_left.c			\
			$(CMD_DIR)cmd_view.c			\
			$(CMD_DIR)cmd_advance.c			\
			$(CMD_DIR)cmd_inventory.c		\
			$(CMD_DIR)cmd_take_object.c		\
			$(CMD_DIR)inventory_rocks.c		\
			$(CMD_DIR)inventory_rocks2.c		\
			$(CMD_DIR)block_rocks.c			\
			$(CMD_DIR)block_rocks2.c		\
			$(CMD_DIR)add_or_remove_id.c		\
			$(CMD_DIR)cmd_drop_object.c		\
			$(CMD_DIR)cmd_kick.c			\
			$(CMD_DIR)cmd_incantation.c		\
			$(CMD_DIR)cmd_fork.c			\
			$(CMD_DIR)cmd_dead.c			\
			$(CMD_DIR)cmd_broadcast.c		\
			$(CMD_DIR)cmd_msz.c			\
			$(CMD_DIR)cmd_sgt.c			\
			$(CMD_DIR)cmd_sst.c			\
			$(CMD_DIR)cmd_tna.c			\
			$(CMD_DIR)cmd_bct.c			\
			$(CMD_DIR)cmd_mct.c			\
			$(CMD_DIR)cmd_ppo.c			\
			$(CMD_DIR)cmd_plv.c			\
			$(CMD_DIR)cmd_pin.c			\
			$(CMD_DIR)cmd_pex.c			\
			$(CMD_DIR)cmd_pfk.c			\
			$(CMD_DIR)cmd_pnw.c			\
			$(CMD_DIR)cmd_pdr.c			\
			$(CMD_DIR)cmd_pgt.c			\
			$(CMD_DIR)cmd_pic.c			\
			$(CMD_DIR)cmd_pie.c			\
			$(CMD_DIR)cmd_pbc.c			\
			$(CMD_DIR)cmd_enw.c			\
			$(CMD_DIR)cmd_eht.c			\
			$(CMD_DIR)cmd_ebo.c			\
			$(CMD_DIR)cmd_edi.c			\
			$(CMD_DIR)cmd_graphic.c			\
			$(CMD_DIR)advance_funcs.c		\
			$(CMD_DIR)int_size_to_malloc.c		\
			$(CMD_DIR)pointers_array.c		\
			$(CMD_DIR)show_items_at_position.c	\
			$(CMD_DIR)determine_pos.c		\
			$(LIST_DIR)push_back.c 			\
			$(LIST_DIR)push_at_index.c 		\
			$(LIST_DIR)push_front.c 		\
			$(LIST_DIR)create_list.c		\
			$(LIST_DIR)get_node_at_index.c		\
			$(LIST_DIR)get_client_in_list.c		\
			$(LIST_DIR)get_team_in_list.c		\
			$(LIST_DIR)free_list.c			\
			$(LIST_DIR)size_list.c			\
			$(LIST_DIR)show_list.c			\
			$(LIST_DIR)get_nbr_of.c			\
			$(LIST_DIR)remove_at_index.c		\
			$(LIST_DIR)remove_front.c		\
			$(LIST_DIR)remove_back.c		\
			$(FREE_DIR)free_struct_cmd.c

NAME		= 	zappy_server

OBJS		= 	$(SRCS:.c=.o)

all		: 	$(NAME)

$(NAME)		: 	$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(EXTERNLIB)
			cp $(NAME) ../../
			@echo "\033[33;33m Compiling server binary\t\t\t[DONE]\033[1;37m"

clean		:
			$(RM) $(OBJS)
			$(RM) *~ *#

fclean		: 	clean
			$(RM) $(NAME)
			$(RM) ../../$(NAME)

re		: 	fclean all

.PHONY		: 	all clean fclean re

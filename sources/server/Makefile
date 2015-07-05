##
## Makefile for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
##
## Made by Serge Heitzler
## Login   <heitzl_s@epitech.net>
##
## Started on  Sun May  3 11:26:21 2015 Serge Heitzler
## Last update Sun Jul  5 19:51:31 2015 Audibert Louis
##

CC		= 	gcc

RM		= 	rm -rf

CFLAGS		+= 	-W -Wall -Werror -Wextra
CFLAGS		+= 	-I ../../headers/

EXTERNLIB	=	-lm

X_DIR		=	../xfuncs/

CMD_DIR		=	./cmd/

LIST_DIR	=	./list/

FREE_DIR	=	./free/

CREATE_DIR	=	./create/

CHECK_DIR	=	./check/

OPT_DIR		=	./options/

UTIL_DIR	=	./utilities/

SRCS		= 	main.c	 				\
			server.c				\
			fill_struct_serv.c			\
			protocole_connexion.c			\
			$(UTIL_DIR)ring_buffer.c		\
			$(UTIL_DIR)ring_buffer_support.c	\
			$(UTIL_DIR)count_teams.c		\
			$(UTIL_DIR)distances.c			\
			$(UTIL_DIR)my_printf.c			\
			$(UTIL_DIR)rand_orientations.c		\
			$(UTIL_DIR)send_data.c			\
			$(UTIL_DIR)utilis.c			\
			$(UTIL_DIR)size_of_tab.c		\
			$(UTIL_DIR)width_and_length.c		\
			$(OPT_DIR)options.c			\
			$(OPT_DIR)options2.c			\
			$(OPT_DIR)set_options.c			\
			$(X_DIR)xmalloc.c	 		\
			$(X_DIR)xlisten.c	 		\
			$(X_DIR)xbind.c		 		\
			$(X_DIR)xsocket.c		 	\
			$(CMD_DIR)cmd_team.c			\
			$(CMD_DIR)cmd_connect_nbr.c		\
			$(CMD_DIR)cmd_right.c			\
			$(CMD_DIR)cmd_left.c			\
			$(CMD_DIR)cmd_view.c			\
			$(CMD_DIR)cmd_view_support.c		\
			$(CMD_DIR)cmd_advance.c			\
			$(CMD_DIR)cmd_inventory.c		\
			$(CMD_DIR)cmd_take_object.c		\
			$(CMD_DIR)cmd_take_object_support.c	\
			$(CMD_DIR)inventory_rocks.c		\
			$(CMD_DIR)inventory_rocks2.c		\
			$(CMD_DIR)block_rocks.c			\
			$(CMD_DIR)block_rocks2.c		\
			$(CMD_DIR)add_or_remove_id.c		\
			$(CMD_DIR)cmd_drop_object.c		\
			$(CMD_DIR)cmd_kick.c			\
			$(CMD_DIR)cmd_incantation.c		\
			$(CMD_DIR)cmd_incantation_support.c	\
			$(CMD_DIR)cmd_fork.c			\
			$(CMD_DIR)cmd_broadcast.c		\
			$(CMD_DIR)cmd_broadcast_support.c	\
			$(CMD_DIR)cmd_msz.c			\
			$(CMD_DIR)cmd_sgt.c			\
			$(CMD_DIR)cmd_sst.c			\
			$(CMD_DIR)cmd_tna.c			\
			$(CMD_DIR)cmd_bct.c			\
			$(CMD_DIR)cmd_mct.c			\
			$(CMD_DIR)cmd_ppo.c			\
			$(CMD_DIR)cmd_plv.c			\
			$(CMD_DIR)cmd_pin.c			\
			$(CMD_DIR)cmd_sbp.c			\
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
			$(CMD_DIR)cmd_pdi.c			\
			$(CMD_DIR)cmd_seg.c			\
			$(CMD_DIR)cmd_suc.c			\
			$(CMD_DIR)cmd_smg.c			\
			$(CMD_DIR)cmd_tin.c			\
			$(CMD_DIR)cmd_graphic.c			\
			$(CMD_DIR)advance_funcs.c		\
			$(CMD_DIR)int_size_to_malloc.c		\
			$(CMD_DIR)pointers_array.c		\
			$(CMD_DIR)show_items_at_position.c	\
			$(CMD_DIR)determine_pos.c		\
			$(CMD_DIR)init_cmd_team.c		\
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
			$(CREATE_DIR)create_map.c		\
			$(CREATE_DIR)create_cmd.c		\
			$(CREATE_DIR)create_client.c		\
			$(CREATE_DIR)create_food.c		\
			$(CREATE_DIR)create_team.c		\
			$(CREATE_DIR)create_objects.c		\
			$(CHECK_DIR)check_exec.c		\
			$(CHECK_DIR)check_end_game.c		\
			$(CHECK_DIR)check_death.c		\
			$(CHECK_DIR)check_food.c		\
			$(CHECK_DIR)check_eggs.c		\
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

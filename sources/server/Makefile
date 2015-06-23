##
## Makefile for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
##
## Made by Serge Heitzler
## Login   <heitzl_s@epitech.net>
##
## Started on  Sun May  3 11:26:21 2015 Serge Heitzler
## Last update Tue Jun 23 13:32:12 2015 Audibert Louis
##

CC		= 	gcc

RM		= 	rm -rf

CFLAGS		+= 	-W -Wall -Werror -Wextra -g3
CFLAGS		+= 	-I ../../headers/

EXTERNLIB	=	-lm

X_DIR		=	../xfuncs/

CMD_DIR	=	./cmd/

LIST_DIR	=	./list/

SRCS		= 	main.c	 				\
			commands.c				\
			count_teams.c				\
			create_map.c				\
			create_client.c				\
			distances.c				\
			my_printf.c				\
			my_str_to_wordtab.c			\
			options.c				\
			options2.c				\
			rand_orientations.c			\
			parser.c				\
			send_data.c				\
			set_options.c				\
			server.c				\
			utilis.c				\
			size_of_tab.c				\
			$(X_DIR)xmalloc.c	 		\
			$(X_DIR)xlisten.c	 		\
			$(X_DIR)xbind.c		 		\
			$(X_DIR)xsocket.c		 	\
			$(CMD_DIR)cmd_right.c			\
			$(CMD_DIR)cmd_left.c			\
			$(CMD_DIR)cmd_view.c			\
			$(CMD_DIR)cmd_advance.c			\
			$(CMD_DIR)cmd_inventory.c		\
			$(CMD_DIR)cmd_take_object.c		\
			$(CMD_DIR)cmd_drop_object.c		\
			$(CMD_DIR)cmd_expel.c			\
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
			$(CMD_DIR)advance_funcs.c		\
			$(CMD_DIR)int_size_to_malloc.c		\
			$(CMD_DIR)pointers_array.c		\
			$(CMD_DIR)show_items_at_position.c	\
			$(LIST_DIR)push_back.c 			\
			$(LIST_DIR)push_at_index.c 		\
			$(LIST_DIR)push_front.c 		\
			$(LIST_DIR)create_list.c		\
			$(LIST_DIR)get_node_at_index.c		\
			$(LIST_DIR)get_client_in_list.c		\
			$(LIST_DIR)free_list.c			\
			$(LIST_DIR)size_list.c			\
			$(LIST_DIR)show_list.c			\
			$(LIST_DIR)get_nbr_of.c			\
			$(LIST_DIR)remove_at_index.c		\
			$(LIST_DIR)remove_front.c		\
			$(LIST_DIR)remove_back.c		\
			ring_buffer.c
			 # exec_cmd.c				\

NAME		= 	server

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

##
## Makefile for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
##
## Made by Serge Heitzler
## Login   <heitzl_s@epitech.net>
##
## Started on  Sun May  3 11:26:21 2015 Serge Heitzler
## Last update Tue May 26 23:56:32 2015 Serge Heitzler
##

CC		= 	gcc

RM		= 	rm -rf

CFLAGS		+= 	-W -Wall -Werror -Wextra -g3
CFLAGS		+= 	-I ../../headers/

EXTERNLIB	=	-lm

X_DIR		=	../xfuncs/

CMD_IA_DIR	=	./cmd_ia/

CMD_GR_DIR	=	./cmd_graph/

LIST_DIR	=	./list/

SRCS		= 	main.c	 				\
			commands.c				\
			count_teams.c				\
			create_map.c				\
			create_client.c				\
			distances.c				\
			exec_cmd.c				\
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
			write_to_client.c			\
			$(X_DIR)xmalloc.c	 		\
			$(X_DIR)xlisten.c	 		\
			$(X_DIR)xbind.c		 		\
			$(X_DIR)xsocket.c		 	\
			$(CMD_IA_DIR)cmd_right.c		\
			$(CMD_IA_DIR)cmd_left.c			\
			$(CMD_IA_DIR)cmd_advance.c		\
			$(CMD_IA_DIR)advance_funcs.c		\
			$(CMD_IA_DIR)int_size_to_malloc.c	\
			$(CMD_IA_DIR)cmd_get_time.c		\
			$(CMD_IA_DIR)cmd_set_time.c		\
			$(LIST_DIR)push_back.c 			\
			$(LIST_DIR)push_at_index.c 		\
			$(LIST_DIR)push_front.c 		\
			$(LIST_DIR)create_list.c		\
			$(LIST_DIR)get_node_at_index.c		\
			$(LIST_DIR)free_list.c			\
			$(LIST_DIR)size_list.c			\
			$(LIST_DIR)show_list.c			\
			$(LIST_DIR)remove_at_index.c		\
			$(LIST_DIR)remove_front.c		\
			$(LIST_DIR)remove_back.c		\

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

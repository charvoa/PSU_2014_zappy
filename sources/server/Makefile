##
## Makefile for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
##
## Made by Serge Heitzler
## Login   <heitzl_s@epitech.net>
##
## Started on  Sun May  3 11:26:21 2015 Serge Heitzler
## Last update Fri May 22 11:26:43 2015 Serge Heitzler
##

CC		= 	gcc

RM		= 	rm -rf

CFLAGS		+= 	-W -Wall -Werror -Wextra -g3
CFLAGS		+= 	-I ../../headers/

EXTERNLIB	=	-lm

XDIR		=	../xfuncs/

CMDIA		=	./cmd_ia/

CMDGR		=	./cmd_graph/

SRCS		= 	main.c	 			\
			add_in_list.c		 	\
			commands.c			\
			create_map.c			\
			create_client.c			\
			distances.c			\
			exec_cmd.c			\
			list.c	 			\
			my_printf.c			\
			my_str_to_wordtab.c		\
			options.c			\
			options2.c			\
			rand_orientations.c		\
			parser.c			\
			send_data.c			\
			set_options.c			\
			server.c			\
			utilis.c			\
			write_to_client.c		\
			$(XDIR)xmalloc.c	 	\
			$(XDIR)xlisten.c	 	\
			$(XDIR)xbind.c		 	\
			$(XDIR)xsocket.c	 	\
			$(CMDIA)cmd_right.c		\
			$(CMDIA)cmd_left.c		\
			$(CMDIA)cmd_advance.c		\
			$(CMDIA)advance_funcs.c		\
			$(CMDIA)int_size_to_malloc.c	\
			$(CMDIA)cmd_get_time.c		\
			$(CMDIA)cmd_set_time.c		\

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

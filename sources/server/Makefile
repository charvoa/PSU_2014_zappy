##
## Makefile for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
##
## Made by Serge Heitzler
## Login   <heitzl_s@epitech.net>
##
## Started on  Sun May  3 11:26:21 2015 Serge Heitzler
## Last update Sat May 16 19:59:59 2015 Serge Heitzler
##

CC		= 	gcc

RM		= 	rm -f

CFLAGS		+= 	-W -Wall -Werror -Wextra -g3
CFLAGS		+= 	-I.

EXTERNLIB	=	-lm

XDIR		=	../xfuncs/

CMDIA		=	./cmd_ia/

CMDGR		=	./cmd_graph/

SRCS		= 	main.c	 			\
			list.c	 			\
			add_in_list.c		 	\
			$(XDIR)xmalloc.c	 	\
			$(XDIR)xlisten.c	 	\
			$(XDIR)xbind.c		 	\
			$(XDIR)xsocket.c	 	\
			utilis.c			\
			set_options.c			\
			server.c			\
			options.c			\
			options2.c			\
			my_printf.c			\
			exec_cmd.c			\
			distances.c			\
			rand_orientations.c		\
			commands.c			\
			create_map.c			\
			create_client.c			\
			my_str_to_wordtab.c		\
			parser.c			\
			write_to_client.c

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

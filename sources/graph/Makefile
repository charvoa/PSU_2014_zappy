##
## Makefile for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/graph
##
## Made by Serge Heitzler
## Login   <heitzl_s@epitech.net>
##
## Started on  Sun May  3 11:27:24 2015 Serge Heitzler
## Last update Wed May 13 10:48:39 2015 Nicolas Girardot
##

CC		= 	gcc

RM		= 	rm -f

CFLAGS		+= 	-W -Wall -Werror -Wextra
CFLAGS		+= 	-I.
CFLAGS		+=	-llibGDL/includes/ -LlibGDL/libs/ -lgdl_gl -lGL -IGLEW \
			-ldl -lrt -lfbxsdk -lSDL2 -lpthread

XDIR		=	../xfuncs/

SRCS		= 	main.c 			\
			$(XDIR)xmalloc.c	\

NAME		= 	graph

OBJS		= 	$(SRCS:.c=.o)

all		: 	$(NAME)

$(NAME)		: 	$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
			cp $(NAME) ../../
			@echo "\033[33;34m Compiling graph binary\t\t\t\t[DONE]\033[1;37m"

clean		:
			$(RM) $(OBJS)
			$(RM) *~ *#

fclean		: 	clean
			$(RM) $(NAME)
			$(RM) ../../$(NAME)

re		: 	fclean all

.PHONY		: 	all clean fclean re

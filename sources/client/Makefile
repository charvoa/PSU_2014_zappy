##
## Makefile for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/client
##
## Made by Serge Heitzler
## Login   <heitzl_s@epitech.net>
##
## Started on  Sun May  3 11:25:37 2015 Serge Heitzler
## Last update Wed May 13 10:15:25 2015 Nicolas Charvoz
##

CC		= 	gcc

RM		= 	rm -f

CFLAGS		+= 	-W -Wall -Werror -Wextra
CFLAGS		+= 	-I.

XDIR		=	../xfuncs/

SRCS		= 	main.c				\
			$(XDIR)xmalloc.c		\

NAME		= 	client

OBJS		= 	$(SRCS:.c=.o)

all		: 	$(NAME)

$(NAME)		: 	$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
			cp $(NAME) ../../
			@echo "\033[33;32m Compiling client binary\t\t\t[DONE]\033[1;37m"

clean		:
			$(RM) $(OBJS)
			$(RM) *~ *#

fclean		: 	clean
			$(RM) $(NAME)
			$(RM) ../../$(NAME)

re		: 	fclean all

.PHONY		: 	all clean fclean re

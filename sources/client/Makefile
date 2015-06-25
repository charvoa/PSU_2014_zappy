##
## Makefile for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/client
##
## Made by Serge Heitzler
## Login   <heitzl_s@epitech.net>
##
## Started on  Sun May  3 11:25:37 2015 Serge Heitzler
## Last update Thu Jun 25 17:24:35 2015 Audibert Louis
##

CC		= 	gcc

RM		= 	rm -f

CFLAGS		+= 	-W -Wall -Werror -Wextra
CFLAGS		+= 	-I.

XDIR		=	../xfuncs/

SRCS		= 	main.c				\
			$(XDIR)xmalloc.c		\

NAME		= 	zappy_ai

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

##
## Makefile for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
##
## Made by Serge Heitzler
## Login   <heitzl_s@epitech.net>
##
## Started on  Sun May  3 11:26:21 2015 Serge Heitzler
## Last update Sat Jun 27 19:14:13 2015 Nicolas Charvoz
##

CC		= 	gcc

RM		= 	rm -rf

CFLAGS		+= 	-W -Wall -Werror -Wextra -g3
CFLAGS		+= 	-I ../../headers/

EXTERNLIB	=	-lm

X_DIR		=	../xfuncs/

CMD_DIR		=	./cmd/

LIST_DIR	=	./list/

SRCS		= 	main.c

NAME		= 	zappy_ai

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

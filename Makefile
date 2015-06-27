##
## Makefile for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy
##
## Made by Serge Heitzler
## Login   <heitzl_s@epitech.net>
##
## Started on  Sun May  3 11:23:38 2015 Serge Heitzler
## Last update Sat Jun 27 19:13:17 2015 Nicolas Charvoz
##

MAKE		= 	make -C
CP		= 	cp -f

DIR_CLIENT	=	sources/client
EXE_SERV	=	sources/client/zappy_ai

DIR_SERV	=	sources/server
EXE_SERV	=	sources/server/zappy_server

DIR_GRAPH	=	sources/graph/
EXE_GRAPH	=	sources/graph/graph

all		:	zappy_ai zappy_server graph

zappy_ai	:
			$(MAKE) $(DIR_CLIENT)

zappy_server	:
			$(MAKE) $(DIR_SERV)

graph		:
			$(MAKE) $(DIR_GRAPH)

clean		:
			$(MAKE) $(DIR_CLIENT) clean
			$(MAKE) $(DIR_SERV) clean
			$(MAKE) $(DIR_GRAPH) clean
			rm -rf *~ *#

fclean		:
			$(MAKE) $(DIR_CLIENT) fclean
			$(MAKE) $(DIR_SERV) fclean
			$(MAKE) $(DIR_GRAPH) fclean

re		:	 fclean all

.PHONY		:	 all clean fclean re client serveur graph

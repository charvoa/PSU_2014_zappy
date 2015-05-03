##
## Makefile for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy
##
## Made by Serge Heitzler
## Login   <heitzl_s@epitech.net>
##
## Started on  Sun May  3 11:23:38 2015 Serge Heitzler
## Last update Sun May  3 11:23:40 2015 Serge Heitzler
##

MAKE		= 	make -C
CP		= 	cp -f

DIR_CLIENT	= 	sources/client/
EXE_CLIENT	= 	sources/client/client

DIR_SERV	=	sources/server
EXE_SERV	=	sources/server/server

DIR_GRAPH	=	sources/graph/
EXE_GRAPH	=	sources/graph/graph

all		:	client server graph

client		:
			$(MAKE) $(DIR_CLIENT)

server		:
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

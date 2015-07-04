##
## Makefile for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/graph
##
## Made by Serge Heitzler
## Login   <heitzl_s@epitech.net>
##
## Started on  Sun May  3 11:27:24 2015 Serge Heitzler
## Last update Fri Jul  3 18:06:29 2015 Antoine Garcia
##

MAIN		=	zappy_graph

RUN		=	run.sh

EXEC		=	$(MAIN)

SRC		+=	GameEngine.cpp					\
			Command.cpp					\
			GraphMap.cpp					\
			Socket.cpp					\
			AObject.cpp					\
			HUD.cpp						\
			IACharacter.cpp					\
			Case.cpp					\
			Egg.cpp						\
			./Sound/SoundManager.cpp			

SRC_MAIN	=	$(SRC) main.cpp

OBJ_MAIN	=	$(SRC_MAIN:.cpp=.o)

LDFLAGS		=	-L./libGDL/libs/ -lgdl_gl	\
			-lGLEW -lrt -lfbxsdk -lSDL2 -lpthread		\
			-lSDL2_ttf					\
			-lSDL2_image						\
			-ldl -lGL -lGLU -lSDL_image			\
			-L ./Sound/lib -lfmodex64 -lglut		\

CPPFLAGS	=	-Wall -Wextra -std=c++11 -Wno-ignored-qualifiers -g3
CPPFLAGS	+=	-I./libGDL/includes/

ifeq ($(DEBUG), YES)
	CPPFLAGS = -g -std=c++11
	CPPFLAGS += -I./libGDL/includes/
	DEBUGFLAGS = -\033[1;31mDEBUG\033[0m-

endif

CPP		=	g++

DEL_FILE	=	rm -f

all:		$(EXEC)
		@printf "\r[\033[2;35mMAKE\033[0m] Zappy Graphic Client\n"

$(MAIN):	$(OBJ_MAIN)
		@$(CPP) -o $@ $^ $(LDFLAGS)

%.o:		%.cpp
		@$(CPP) -o $@ -c $< $(CPPFLAGS)
		@printf "\r$(DEBUGFLAGS)$(PROFILFLAGS)[\033[1;32mBUILD\033[0m] $<\n"

clean:
		@$(DEL_FILE) $(OBJ_MAIN)
		@printf "\r[\033[1;31mDELETE\033[0m] *.o\n"
		@$(DEL_FILE)
		@printf "\r[\033[1;31mDELETE\033[0m] *~\n"

fclean:		clean
		@$(DEL_FILE) $(MAIN)
		@printf "\r[\033[1;31mDELETE\033[0m] $(EXEC)\n"

re:		fclean all

.PHONY:		all clean fclean re

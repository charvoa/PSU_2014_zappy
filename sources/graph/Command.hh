//
// Command.hh for zappy in /home/nicolas/test/ptrfunc
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May 20 15:23:17 2015 Nicolas Girardot
// Last update Mon Jun 22 17:42:00 2015 Nicolas Girardot
//

#ifndef COMMAND_HH_
# define COMMAND_HH_

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include "AObject.hpp"
#include "GameEngine.hh"

class GameEngine;

class Command
{
private:
  typedef void(Command::*funcs)(std::string, GameEngine *);
  funcs _ptr;
  typedef std::map<std::string, funcs>map_funcs;
  map_funcs	_functions;

public:
  Command();
  ~Command();
  void	Exec();
  void	Parse(std::string, GameEngine *);
  void	msz(std::string, GameEngine *);
  void	bct(std::string, GameEngine *);
  void	mct(std::string, GameEngine *);
  void	tna(std::string, GameEngine *);
  void	pnw(std::string, GameEngine *);
  void	ppo(std::string, GameEngine *);
  void	plv(std::string, GameEngine *);
};

#endif

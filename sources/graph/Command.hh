//
// Command.hh for zappy in /home/nicolas/test/ptrfunc
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May 20 15:23:17 2015 Nicolas Girardot
// Last update Wed May 27 10:36:58 2015 Florian PERU
//

#ifndef COMMAND_HH_
# define COMMAND_HH_

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include "AObject.hpp"

class Command
{
private:
  typedef void(Command::*funcs)(std::string);
  funcs _ptr;
  typedef std::map<std::string, funcs>map_funcs;
  map_funcs	_functions;

public:
  Command();
  ~Command();
  void	Exec();
  void	Parse(std::string);
  void	msz(std::string);
  void	bct(std::string);
  void	mct(std::string);
  void	tna(std::string);
  void	pnw(std::string);
  void	ppo(std::string);
  void	plv(std::string);
};

#endif

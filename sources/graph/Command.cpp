//
// Command.cpp for zappy in /home/nicolas/test/ptrfunc
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May 20 15:23:21 2015 Nicolas Girardot
// Last update Thu May 21 12:22:49 2015 Florian PERU
//

#include "Command.hh"

Command::Command()
{
  Exec();
}

Command::~Command(){}

void Command::msz(std::string)
{
  std::vector<std::string>	parse;
  std::string			current;
  std::istringstream		ss(str);

  while(std::getline(ss, current, ' '))
    parse.push_back(current);

  createMap(parse);
}

void Command::Exec()
{
  _functions["msz"] = &Command::msz;
  /* faire de même pour chaque fonctions */
}

void Command::Parse(std::string command)
{
  std::string cmd(command, 0, 3);
  for (std::map<std::string, funcs>::iterator it = _functions.begin(); it!=_functions.end(); ++it)
    {
      if (it->first == cmd)
	(*this.*_functions[cmd])(command);
    }
}

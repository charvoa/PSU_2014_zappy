//
// Command.cpp for zappy in /home/nicolas/test/ptrfunc
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May 20 15:23:21 2015 Nicolas Girardot
// Last update Wed May 27 10:13:58 2015 Florian PERU
//

#include "Command.hh"

Command::Command()
{
  Exec();
}

Command::~Command(){}

void Command::msz(std::string cmd)
{
  std::vector<std::string>	parse;
  std::string			current;
  std::istringstream		ss(cmd);

  while(std::getline(ss, current, ' '))
    if (current != "msz")
      parse.push_back(current);

  //  createMap(parse);
}

void	Command::bct(std::string cmd)
{
  std::vector<std::string>	parse;
  std::string			current;
  std::istringstream		ss(cmd);

  while (std::getline(ss, current, ' '))
    if (current != "bct")
      parse.push_back(current);

  //  affObject(parse);
}

void	Command::mct(std::string cmd)
{
  std::string		newCmd;
  std::istringstream	ss(cmd);

  while (std::getline(ss, newCmd, '\n'))
    this->bct(newCmd);
}

void	Command::tna(std::string cmd)
{
  // TODO
}

void Command::Exec()
{
  _functions["msz"] = &Command::msz;
  _functions["bct"] = &Command::bct;
  _functions["mct"] = &Command::mct;
  _functions["tna"] = &Command::tna;
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

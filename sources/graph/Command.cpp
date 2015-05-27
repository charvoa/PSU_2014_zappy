//
// Command.cpp for zappy in /home/nicolas/test/ptrfunc
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May 20 15:23:21 2015 Nicolas Girardot
// Last update Wed May 27 10:45:16 2015 Florian PERU
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
  std::string			singleCmd;
  std::string			name;
  std::istringstream		ss(cmd);
  std::vector<std::string>	vecName;

  while (std::getline(ss, singleCmd, '\n'))
    {
      std::istringstream	iss(singleCmd);
      while (std::getline(iss, name, ' '))
	if (name != "tna")
	  vecName.push_back(name);
    }
}


void	Command::pnw(std::string cmd)
{
  std::string			param;
  std::vector<std::string>	detPlayer;
  std::istringstream		ss(cmd);

  while (std::getline(ss, param, ' '))
    if (param != "pnw")
      detPlayer.push_back(param);

  // affPlayer(param);
}

void	Command::ppo(std::string cmd)
{
  std::string			param;
  std::vector<std::string>	detPlayer;
  std::istringstream		ss(cmd);

  while (std::getline(ss, param, ' '))
    if (param != "ppo")
      detPlayer.push_back(param);

  // affPlayer(param);
}

void	Command::plv(std::string cmd)
{
  std::string			current;
  std::vector<std::string>	lvlPlayer;
  std::istringstream		ss(cmd);

  while (std::getline(ss, current, ' '))
    if (current != "plv")
      lvlPlayer.push_back(current);

  // defLVL(lvlPlayer);
}

void Command::Exec()
{
  _functions["msz"] = &Command::msz;
  _functions["bct"] = &Command::bct;
  _functions["mct"] = &Command::mct;
  _functions["tna"] = &Command::tna;
  _functions["pnw"] = &Command::pnw;
  _functions["ppo"] = &Command::ppo;
  _functions["plv"] = &Command::plv;
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

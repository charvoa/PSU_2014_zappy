//
// Command.cpp for zappy in /home/nicolas/test/ptrfunc
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May 20 15:23:21 2015 Nicolas Girardot
// Last update Fri Jun 26 17:13:07 2015 Antoine Garcia
//

#include "Command.hh"

Command::Command()
{
  Exec();
}

Command::~Command(){}

void Command::pin(std::string cmd, GameEngine *game)
{
  (void)game;
  std::vector<int>	vector;
  std::string		parse(cmd.begin() + 5, cmd.end());
  std::istringstream	ss(parse);

  for (int i = 0; i < 10 ; i++)
    {
      int val;
      ss >> val;
      vector.push_back(val);
    }
}

void Command::msz(std::string cmd, GameEngine *game)
{
  std::vector<std::string>	parse;
  std::string			current;
  std::istringstream		ss(cmd);

  std::cout << cmd << std::endl;
  std::cout << "test a linstant meme du jour d'aujourd'hui" << std::endl;
  while(std::getline(ss, current, ' '))
    {
      if (current != "msz")
	parse.push_back(current);
    }
  game->createMap(parse);
}

void	Command::bct(std::string cmd, GameEngine *game)
{
  (void) game;
  std::vector<std::string>	parse;
  std::string			current;
  std::istringstream		ss(cmd);

  while (std::getline(ss, current, ' '))
    {
      if (current != "bct")
	parse.push_back(current);
      //game->setCase(parse);
    }
}

void	Command::mct(std::string cmd, GameEngine *game)
{
  (void) game;
  std::string		newCmd;
  std::istringstream	ss(cmd);

  while (std::getline(ss, newCmd, '\n'))
    this->bct(newCmd, game);
}

void	Command::tna(std::string cmd, GameEngine *game)
{
  (void) game;
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


void	Command::pnw(std::string cmd, GameEngine *game)
{
  (void) game;
  std::string			param;
  std::vector<std::string>	detPlayer;
  std::istringstream		ss(cmd);

  while (std::getline(ss, param, ' '))
    if (param != "pnw")
      detPlayer.push_back(param);

  // affPlayer(param);
}

void	Command::ppo(std::string cmd, GameEngine *game)
{
  (void) game;
  std::string			param;
  std::vector<std::string>	detPlayer;
  std::istringstream		ss(cmd);

  while (std::getline(ss, param, ' '))
    if (param != "ppo")
      detPlayer.push_back(param);

  // affPlayer(param);
}

void	Command::plv(std::string cmd, GameEngine *game)
{
  (void) game;
  std::string			current;
  std::vector<std::string>	lvlPlayer;
  std::istringstream		ss(cmd);

  while (std::getline(ss, current, ' '))
    if (current != "plv")
      lvlPlayer.push_back(current);

  // defLVL(lvlPlayer);
}

void Command::pgt(std::string cmd, GameEngine *game)
{
  (void) game;
  std::string		str(cmd.begin() + 5, cmd.end());
  std::vector<int>	vec;
  std::istringstream	ss(str);

  for (int i = 0 ; i < 2 ; i++)
    {
      int	val;
      ss >> val;
      vec.push_back(val);
    }
}

void Command::pdi(std::string cmd, GameEngine *game)
{
  (void)game;

  std::string		str(cmd.begin() + 5, cmd.end());
  std::istringstream	ss(str);
  int			id;

  ss >> id;
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
  _functions["pin"] = &Command::pin;
  _functions["pgt"] = &Command::pgt;
  _functions["pdi"] = &Command::pdi;
  /* faire de même pour chaque fonctions */
}

void Command::Parse(std::string command, GameEngine *game)
{
  std::string cmd(command, 0, 3);
  std::cout << "command" << command << std::endl;
  for (std::map<std::string, funcs>::iterator it = _functions.begin(); it!=_functions.end(); ++it)
    {
      if (it->first == cmd)
	(*this.*_functions[cmd])(command, game);
    }
}

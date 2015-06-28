//
// Command.cpp for zappy in /home/nicolas/test/ptrfunc
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed May 20 15:23:21 2015 Nicolas Girardot
// Last update Sun Jun 28 23:04:19 2015 Antoine Garcia
//

#include "Command.hh"
#include <tuple>
Command::Command()
{
  Exec();
}

Command::~Command(){}

void Command::pin(std::string cmd, GameEngine *game)
{
  std::vector<int>	vector;
  std::string		parse(cmd.begin() + 4, cmd.end());
  std::istringstream	ss(parse);

  for (int i = 0; i < 10 ; i++)
    {
      int val;
      ss >> val;
      vector.push_back(val);
    }
  game->updateInventory(vector);
}

void Command::msz(std::string cmd, GameEngine *game)
{
  std::vector<std::string>	parse;
  std::string			current;
  std::istringstream		ss(cmd);

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
    }
  game->setCase(parse);
}

void	Command::mct(std::string cmd, GameEngine *game)
{
  (void) game;
  std::string		newCmd;
  std::istringstream	ss(cmd);

  while (std::getline(ss, newCmd, '\n'))
    {
      ss.str("");
      ss.clear();
      this->bct(newCmd, game);
    }
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

  game->addPlayer(detPlayer);
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
  game->updatePlayer(detPlayer);
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
  std::string		str(cmd.begin() + 4, cmd.end());
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

  std::string		str(cmd.begin() + 4, cmd.end());
  std::istringstream	ss(str);
  int			id;

  ss >> id;
  std::cout << "Deleted id is " << id << std::endl;
  game->deletePlayer(id);
}

void Command::pfk(std::string cmd, GameEngine *game)
{
  (void)game;

  std::string		str(cmd.begin() + 4, cmd.end());
  std::istringstream	ss(str);
  int			id;

  ss >> id;
}

void Command::seg(std::string cmd, GameEngine *game)
{
  (void)game;

  std::string		str(cmd.begin() + 4, cmd.end());
  std::istringstream	ss(str);
  int			id;

  ss >> id;
}

void Command::pbc(std::string cmd, GameEngine *game)
{
  (void)game;

  std::string		str(cmd.begin() + 4, cmd.end() - 1);
  std::istringstream	ss(str);
  int val;
  std::string	string;

  ss >> val;
  ss >> string;
  std::tuple<int, std::string> tuple = std::make_tuple(val, str);
}

void Command::pie(std::string cmd, GameEngine *game)
{
  (void)game;
  std::string		str(cmd.begin() + 4, cmd.end());
  std::istringstream	ss(str);
  std::vector<int>	vector;

  for (int i = 0 ; i < 3 ; i++)
    {
      int val;
      ss >> val;
      vector.push_back(val);
    }
}

void Command::pic(std::string cmd, GameEngine *game)
{
  (void)game;
  std::string		str(cmd.begin() + 4, cmd.end());
  std::istringstream	ss(str);
  int x;
  int y;
  int l;
  std::vector<int>	vector;
  std::string		var;

  ss >> x;
  ss >> y;
  ss >> l;
  vector.push_back(x);
  vector.push_back(y);
  vector.push_back(l);
  while (ss >> var)
    {
      std::string val(var.begin() + 1, var.end());
      int value;
      value = std::stoi(val);
      vector.push_back(value);
    }
}

void Command::pdr(std::string cmd, GameEngine *game)
{
  (void)game;

  std::string		str(cmd.begin() + 4, cmd.end());
  std::istringstream	ss(str);
  int id;
  int id_ressource;
  ss >> id;
  ss >> id_ressource;
  std::tuple<int, int> tuple = std::make_tuple(id, id_ressource);
}

void Command::smg(std::string cmd, GameEngine *game)
{
  (void) game;
  std::string		str(cmd.begin() + 4, cmd.end());
}

void Command::eht(std::string cmd, GameEngine *game)
{
  (void)game;

  std::string		str(cmd.begin() + 4, cmd.end());
  int val = std::stoi(str);
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
  _functions["pfk"] = &Command::pfk;
  _functions["pnw"] = &Command::pnw;
  _functions["seg"] = &Command::seg;
  _functions["pbc"] = &Command::pbc;
  _functions["pie"] = &Command::pie;
  _functions["pic"] = &Command::pic;
  _functions["pdr"] = &Command::pdr;
  _functions["smg"] = &Command::smg;
  /* faire de même pour chaque fonctions */
}

void Command::Parse(std::string command, GameEngine *game)
{
  std::string cmd(command, 0, 3);
  std::cout << command << std::endl;
  for (std::map<std::string, funcs>::iterator it = _functions.begin(); it!=_functions.end(); ++it)
    {
      if (it->first == cmd)
	(*this.*_functions[cmd])(command, game);
    }
}

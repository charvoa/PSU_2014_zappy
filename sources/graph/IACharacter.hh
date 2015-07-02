//
// IACharacter.hh for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/graph
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Thu Jun 25 17:22:59 2015 Serge Heitzler
// Last update Thu Jul  2 15:16:42 2015 Nicolas Girardot
//

#ifndef IACharacter_HH_
# define IACharacter_HH_

#include "Position.hpp"
#include <iostream>
#include <vector>

class		IACharacter
{
public:
  typedef enum e_type
    {
      FOOD = 0,
      LIMEMATE = 1,
      DERAUMERE = 2,
      SIBUR = 3,
      MENDIANE = 4,
      PHIRAS = 5,
      THYSTAME = 6
    }	e_type;

public:
  IACharacter(std::vector<int> &, std::string&);
  ~IACharacter();

  void		increment(e_type type);
  void		decrement(e_type type);
  int		getId();
  void		setLVL(int);
  bool		isBroadcasting();
  void		updateBroadcast();
  int		getLVL();
  int		getOrientation();
  void		broadcast();
  void		updateInventory(std::vector<int> &);
  void		updateAtt(std::vector<int> &);
  int		get(e_type type);
  std::string	&getTeam();
  Position	&getPosition();

 private:
  Position	*_position;
  int		_limemate;
  int		_deraumere;
  int		_sibur;
  int		_mendiane;
  int		_phiras;
  int		_thystame;
  int		_food;
  int		_orientation;
  int		_id;
  int		_lvl;
  std::string	_team;
  bool		_broadcasting = false;
  int		_broadcastCountdown;
};

#endif /* IACharacter_HH_ */

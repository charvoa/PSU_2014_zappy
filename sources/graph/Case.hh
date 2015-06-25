//
// Case.hh for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/graph
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Thu Jun 25 10:50:43 2015 Serge Heitzler
// Last update Thu Jun 25 11:36:18 2015 Nicolas Girardot
//

#ifndef CASE_HH_
# define CASE_HH_

#include <vector>

class		Case
{
  typedef enum e_type
  {
    FOOD,
    LIMEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  }	e_type;

 public:
  Case(int, int, int, int, int, int, int);
  ~Case();

  void		increment(e_type type);
  void		decrement(e_type type);

 private:
  int		_limemate;
  int		_deraumere;
  int		_sibur;
  int		_mendiane;
  int		_phiras;
  int		_thystame;
  int		_food;
  //  std::vector<IACharacter *>	_list;


};

#endif /* CASE_HH_ */

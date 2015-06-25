//
// IACharacter.hh for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/graph
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Thu Jun 25 17:22:59 2015 Serge Heitzler
// Last update Thu Jun 25 17:26:33 2015 Serge Heitzler
//

#ifndef IACharacter_HH_
# define IACharacter_HH_

class		IACharacter
{

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
  IACharacter();
  ~IACharacter();

  void		increment(e_type type);
  void		decrement(e_type type);
  int		get(e_type type);

 private:
  int		_limemate;
  int		_deraumere;
  int		_sibur;
  int		_mendiane;
  int		_phiras;
  int		_thystame;
  int		_food;

};

#endif /* IACharacter_HH_ */

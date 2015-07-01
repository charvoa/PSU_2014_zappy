//
// Case.hh for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/graph
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Thu Jun 25 10:50:43 2015 Serge Heitzler
// Last update Wed Jul  1 10:43:14 2015 Nicolas Girardot
//

#ifndef CASE_HH_
# define CASE_HH_

# include <vector>
# include "IACharacter.hh"
# include <stdlib.h>
# include <time.h>

class		Case
{
public:
  typedef enum e_texture_type
    {
      GRASS,
      DIRT
    }		e_texture_type;

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
  Case(int, int, int, int, int, int, int);
  ~Case();

  void		increment(e_type type);
  void		decrement(e_type type);
  void		setAll(int, int, int, int, int, int, int);
  int		getType();
  void		setIncant(bool);
  int		get(e_type type);
  bool		getIncant();
 private:
  int			_limemate;
  int			_deraumere;
  int			_sibur;
  int			_mendiane;
  int			_phiras;
  int			_thystame;
  int			_food;
  e_texture_type       	_textureType;
  std::vector<IACharacter *>	_list;
  bool			_isIncant = false;
  int			_hasEgg = 0;
};

#endif /* CASE_HH_ */

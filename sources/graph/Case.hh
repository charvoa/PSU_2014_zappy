//
// Case.hh for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/graph
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Thu Jun 25 10:50:43 2015 Serge Heitzler
// Last update Thu Jun 25 20:07:23 2015 Serge Heitzler
//

#ifndef CASE_HH_
# define CASE_HH_

# include <vector>
# inclulde "IACharacter.hh"

class		Case
{
  typedef enum e_texture_type
    {
      
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
  void		setAll(std::vector<int> &vector);

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

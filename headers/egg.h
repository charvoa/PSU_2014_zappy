/*
** egg.h for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Sat Jun 27 09:31:12 2015 Audibert Louis
** Last update Sat Jun 27 09:39:49 2015 Audibert Louis
*/

#ifndef _EGG_H_
# define _EGG_H_

# include "position.h"

typedef enum e_state_egg
  {
    ASLEEP,
    BORN,
    DEAD
  }	     e_state_egg;

typedef struct	s_egg
{
  int		num_egg;
  int		father;
  t_position	*pos;
  char		*team_name;
  e_state_egg	state;
}		t_egg;

#endif /* _EGG_H_ */
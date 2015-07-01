/*
** egg.h for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Sat Jun 27 09:31:12 2015 Audibert Louis
** Last update Tue Jun 30 20:10:36 2015 Serge Heitzler
*/

#ifndef _EGG_H_
# define _EGG_H_

# include "position.h"

typedef struct		s_egg
{
  int			id;
  int			fd;
  int			fd_father;
  t_position		*pos;
  char			*team_name;
  struct timespec	eclos;
}			t_egg;

#endif /* _EGG_H_ */

/*
** map.h for zappy in /home/audibe_l/rendu/PSU_2014_zappy/headers
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Sat Jun 27 09:44:55 2015 Audibert Louis
** Last update Sun Jul  5 19:11:29 2015 Serge Heitzler
*/

#ifndef _MAP_H_
# define _MAP_H_

typedef struct		s_objects
{
  char			*label;
  int			(*ptr_func)();
}			t_objects;

typedef struct		s_block
{
  int			food;
  int			linemate;
  int			deraumere;
  int			sibur;
  int			mendiane;
  int			phiras;
  int			thystame;
  int			*ids;
  int			nb_clients;
}			t_block;

typedef struct		s_size
{
  int		       	width;
  int		       	height;
}			t_size;

typedef struct		s_map
{
  t_size		*size;
  t_block		***objects;
}			t_map;

#endif /* _MAP_H_ */

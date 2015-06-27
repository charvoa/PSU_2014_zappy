/*
** ressources.h for zappy in /home/audibe_l/rendu/PSU_2014_zappy/headers
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Sat Jun 27 09:46:56 2015 Audibert Louis
** Last update Sat Jun 27 17:39:22 2015 Audibert Louis
*/

#ifndef _RESSOURCES_H_
# define _RESSOURCES_H_

typedef enum		e_flag_rock
  {
    ADD,
    REMOVE,
  }			e_flag_rock;

typedef enum		e_rock_type
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
  }			e_rock_type;

typedef struct		s_food
{
  t_position		*pos;
}			t_food;

typedef struct		s_rock
{
  t_position		*pos;
  e_rock_type		type;
}			t_rock;

#endif /* _RESSOURCES_H_ */

/*
** client.h for zappy in /home/audibe_l/rendu/PSU_2014_zappy/headers
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Sat Jun 27 09:41:12 2015 Audibert Louis
** Last update Sun Jul  5 19:10:39 2015 Serge Heitzler
*/

#ifndef _CLIENT_H_
# define _CLIENT_H_

# include "team.h"

typedef enum		e_orientation
  {
    NORD = 1,
    EST = 2,
    SUD = 3,
    OUEST = 4,
    NONE
  }			e_orientation;

typedef enum		e_client_type
  {
    IA,
    GUI,
    NORMAL
  }			e_client_type;

typedef enum		e_client_state
  {
    CHILD,
    ADULT
  }			e_client_state;

typedef struct		s_inventory
{
  int			food;
  int			linemate;
  int			deraumere;
  int			sibur;
  int			mendiane;
  int			phiras;
  int			thystame;
}			t_inventory;

typedef struct		s_client
{
  int			fd;
  int			level;
  e_orientation		orientation;
  char			*team_name;
  e_client_type		type;
  t_position		*pos;
  t_inventory		*inventory;
  t_list		*cmds;
  e_client_state	state;
  t_ring_buffer		*buffer;
}			t_client;

#endif /* _CLIENT_H_ */

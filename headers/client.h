/*
** client.h for zappy in /home/audibe_l/rendu/PSU_2014_zappy/headers
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Sat Jun 27 09:41:12 2015 Audibert Louis
** Last update Sat Jun 27 09:44:06 2015 Audibert Louis
*/

#ifndef _CLIENT_H_
# define _CLIENT_H_

typedef enum		e_orientation
  {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3,
    NONE
  }			e_orientation;

typedef enum		e_client_type
  {
    IA,
    GUI
  }			e_client_type;

typedef struct		s_inventory
{
  int			food;
  int			limemate;
  int			deraumere;
  int			sibur;
  int			mendiane;
  int			phiras;
  int			thystame;
}			t_inventory;

typedef struct		s_team
{
  char			*name;
  int			slot_rest;
  int			slot_max;
}			t_team;

typedef struct		s_client
{
  int			fd;
  unsigned int		level;
  e_orientation		orientation;
  char			*team_name;
  e_client_type		type;
  t_position		*pos;
  t_inventory		*inventory;
  t_list		*cmds;

  t_ring_buffer		*buffer;
}			t_client;

#endif /* _CLIENT_H_ */

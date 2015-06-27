/*
** client.h for zappy in /home/audibe_l/rendu/PSU_2014_zappy/headers
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Sat Jun 27 09:41:12 2015 Audibert Louis
<<<<<<< HEAD
** Last update Sat Jun 27 13:47:55 2015 Audibert Louis
=======
** Last update Sat Jun 27 14:16:22 2015 Serge Heitzler
>>>>>>> 259e19031ff2b08ec43886cb2b86d64848eeaefe
*/

#ifndef _CLIENT_H_
# define _CLIENT_H_

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
  int			level;
  e_orientation		orientation;
  char			*team_name;
  e_client_type		type;
  t_position		*pos;
  t_inventory		*inventory;
  t_list		*cmds;

  t_ring_buffer		*buffer;
}			t_client;

#endif /* _CLIENT_H_ */

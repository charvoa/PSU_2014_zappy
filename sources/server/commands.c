/*
** commands.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu May  7 16:30:08 2015 Audibert Louis
** Last update Sun May 17 11:40:01 2015 Serge Heitzler
*/

#include "server.h"

int	cmd_team(t_server *s)
{
  char	trame[3];

  bzero(trame, 3);
  //if s->tab[1] correspond a un nom de s->team_names alors OK else NTM
  /* if (s->teams->slot_rest >= 1) */
  /*   { */
  /*     sprintf(trame, "%d", s->teams->slot_rest); */
  /*     write_to_client(s, trame); */
  /*     s->teams->slot_rest --; */
  /*   } */
  /* else */
  /*   write_to_client(s, "NO_SLOT_REST"); */

  //tmp
  write_to_client(s, "2\r\n");
  write_to_client(s, "20 - 20\r\n");
  //end

  /* bzero(trame, 3); */
  /* sprintf(trame, "%d\r\n", s->map->width); */
  /* write_to_client(s, trame); */
  /* bzero(trame, 3); */
  /* sprintf(trame, "%d\r\n", s->map->height); */
  /* write_to_client(s, trame); */
  return (0);
}

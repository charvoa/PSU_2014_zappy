/*
** cmd_broadcast_support.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jul  3 18:08:32 2015 Serge Heitzler
** Last update Fri Jul  3 18:16:26 2015 Serge Heitzler
*/

#include "functions.h"

void		generate_broadcast(t_server *s, t_client *c,
				   t_client *cli, char *msg)
{
  char		*tmp;
  int		size_malloc;
  int		l;
  int		w;
  int		sound;
  
  sound = 0;
  l = get_l(s->map, c->pos->x, cli->pos->x);
  w = get_w(s->map, c->pos->y, cli->pos->y);
  sound = determine_last_case(c, cli, l, w);
  size_malloc = 10 + istm(sound) + strlen(msg);
  tmp = xmalloc(sizeof(char) * size_malloc);
  bzero(tmp, size_malloc);
  sprintf(tmp, "message %d, %s", sound, msg);
  send_data(cli->fd, tmp);
  printf("%s", tmp);
  free(tmp);
}

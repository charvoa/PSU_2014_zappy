/*
** cmd_expel.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:12 2015 Serge Heitzler
** Last update Sun Jun 28 23:10:21 2015 Serge Heitzler
*/

#include "functions.h"

char		*get_trame_deplacement(t_client *c)
{
  char		*trame;
  int		x;
  int		y;

  x = c->pos->x;
  y = c->pos->y;
  if (c->orientation == NORD)
    y = c->pos->y - 1;
  else if (c->orientation == EST)
    x = c->pos->x - 1;
  else if (c->orientation == SUD)
    y = c->pos->y + 1;
  else
    x = c->pos->x + 1;
  trame = xmalloc((strlen("deplacement: ") + 8) * sizeof(char));
  bzero(trame, strlen("deplacement: ") + 8);
  sprintf(trame, "deplacement: %d %d\n", x, y);
  printf("trame = %s", trame);
  return (trame);
}

void		move_client_from_ori(t_server *s, t_client *caller, t_client *moved)
{
  if (caller->orientation == NORD)
    moved->pos->y = caller->pos->y - 1;
  else if (caller->orientation == EST)
    moved->pos->x = caller->pos->x - 1;
  else if (caller->orientation == SUD)
    moved->pos->y = caller->pos->y + 1;
  else
    moved->pos->x = caller->pos->x + 1;
  cmd_ppo(s, moved, "protocole", GUI);
}

int		cmd_kick(t_server *s, t_client *c,
			 const char *cmd, e_client_type type)
{
  t_client	*client;
  char		*final;
  int		i;

  (void)type;
  (void)cmd;
  i = 0;
  client = xmalloc(sizeof(t_client));
  final = get_trame_deplacement(c);
  cmd_pex(c, s->clients);
  while (i < s->map->objects[c->pos->y][c->pos->x]->nb_clients)
    {
      client = get_client_by_id(s->clients,
				s->map->objects[c->pos->y][c->pos->x]->ids[i]);
      if ((client->pos->x == c->pos->x) && (client->pos->y == c->pos->x)
	  && client->fd != c->fd)
  	    {
	      move_client_from_ori(s, c, client);
  	      send_data(client->fd, final);
  	      send_data(c->fd, "ok\n");
  	    }
      i++;
    }
  send_data(c->fd, "ko\n");
  return (SUCCESS);
}

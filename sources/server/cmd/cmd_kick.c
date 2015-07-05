/*
** cmd_expel.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:12 2015 Serge Heitzler
** Last update Sun Jul  5 19:27:00 2015 Audibert Louis
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
  trame = xmalloc((strlen("deplacement: ")
		   + 3 + istm(x) + istm(y)) * sizeof(char));
  bzero(trame, strlen("deplacement: ") + 3 + istm(x) + istm(y));
  sprintf(trame, "deplacement: %d %d\n", x, y);
  return (trame);
}

void		move_client_from_ori(t_server *s, t_client *caller,
				     t_client *moved)
{
  s->map->objects[moved->pos->y][moved->pos->x]->nb_clients--;
  s->map->objects[moved->pos->y][moved->pos->x]->ids =
    remove_id(s->map->objects[moved->pos->y][moved->pos->x], moved->fd);
  if (caller->orientation == NORD)
    moved->pos->y = caller->pos->y - 1;
  else if (caller->orientation == EST)
    moved->pos->x = caller->pos->x - 1;
  else if (caller->orientation == SUD)
    moved->pos->y = caller->pos->y + 1;
  else
    moved->pos->x = caller->pos->x + 1;
  s->map->objects[moved->pos->y][moved->pos->x]->nb_clients++;
  s->map->objects[moved->pos->y][moved->pos->x]->ids =
    add_id(s->map->objects[moved->pos->y][moved->pos->x], moved->fd);
  cmd_ppo(s, moved, "protocole", GUI);
}

int		cmd_kick(t_server *s, t_client *c,
			 char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;
  t_client	*client;
  char		*final;
  int		i;

  if (c->state == CHILD)
    return (ERROR);
  i = -1;
  final = get_trame_deplacement(c);
  cmd_pex(c, s->clients);
  while (++i < s->map->objects[c->pos->y][c->pos->x]->nb_clients)
    {
      client = get_client_by_id(s->clients,
				s->map->objects[c->pos->y][c->pos->x]->ids[i]);
      if ((client->pos->x == c->pos->x) && (client->pos->y == c->pos->y)
	  && client->fd != c->fd)
  	    {
	      move_client_from_ori(s, c, client);
  	      send_data(client->fd, final);
  	      send_data(c->fd, "ok\n");
  	    }
    }
  free(final);
  return (SUCCESS);
}

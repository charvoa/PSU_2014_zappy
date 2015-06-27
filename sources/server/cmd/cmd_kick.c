/*
** cmd_expel.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:29:12 2015 Serge Heitzler
** Last update Sat Jun 27 17:30:10 2015 Serge Heitzler
*/

#include "functions.h"

static void	cmd_pex(t_client *c, t_list *clients)
{
  int		size_malloc;
  char	*str;

  size_malloc = (6 + istm(c->fd));
  str = xmalloc(sizeof(char) * size_malloc);
  bzero(str, size_malloc);
  sprintf(str, "pex #%d\n", c->fd);
  send_data_to_gui(clients, str);
}

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

int		cmd_kick(t_server *s, t_client *c,
			 const char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;
  t_client	*client;
  char		*final;
  int		i;

  i = 0;
  client = xmalloc(sizeof(t_client));
  final = get_trame_deplacement(c);
  cmd_pex(c, s->clients);
  while (i <= s->map->objects[c->pos->y][c->pos->x]->nb_clients)
    {
      client = get_client_by_id(s->clients,
				s->map->objects[c->pos->y][c->pos->x]->ids[i]);
      if ((client->pos->x == c->pos->x) && (client->pos->y == c->pos->x)
	  && client->fd != c->fd)
  	    {
  	      send_data(client->fd, final);
  	      send_data(c->fd, "ok\r\n");
  	    }
      client = NULL;
      i++;
    }
  send_data(c->fd, "ko\r\n");
  return (SUCCESS);
}

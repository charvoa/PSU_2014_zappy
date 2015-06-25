/*
** cmd_expel.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:12 2015 Serge Heitzler
** Last update Thu Jun 25 15:20:03 2015 Audibert Louis
*/

#include "server.h"

char		*get_trame_deplacement(t_client *c)
{
  char		*trame;
  int		x;
  int		y;

  if (c->orientation == UP)
    {
      x = c->pos->x;
      y = c->pos->y - 1;
    }
  else if (c->orientation == RIGHT)
    {
      x = c->pos->x - 1;
      y = c->pos->y;
    }
  else if (c->orientation == DOWN)
    {
      x = c->pos->x;
      y = c->pos->y + 1;
    }
  else
    {
      x = c->pos->x + 1;
      y = c->pos->y;
    }
  trame = xmalloc((strlen("deplacement: ") + 8) * sizeof(char));
  bzero(trame, strlen("deplacement: ") + 8);
  sprintf(trame, "deplacement: %d %d\n", x, y);
  printf("trame = %s", trame);
  return (trame);
}

int		cmd_kick(t_server *s, t_client *c, const char *cmd)
{
  (void)s;
  (void)c;
  (void)cmd;

  //PARCOURIR S->MAPS[Y][X]->OBJECTS == PLAYER && != CLIENT *C
  //ET DU COUP SEND_DATA TO EVERYBODY "deplacement: direction = orientation t_client *c
  t_node	*tmp;
  t_client	*client;
  char		*final;
  
  client = xmalloc(sizeof(t_client));
  tmp = s->map->objects[c->pos->y][c->pos->x]->start;
  final = get_trame_deplacement(c);
  while (tmp)
    {
      if (tmp->type == PLAYER)
  	{
  	  client = tmp->data;
  	  if ((client->pos->x == c->pos->x) && (client->pos->y == c->pos->x)
  	      && client->fd != c->fd)
	    {
	      send_data(client->fd, final);
	      send_data(c->fd, "ok\r\n");
	    }
  	}
      tmp = tmp->next;
    }
  send_data(c->fd, "ko\r\n");
  return (SUCCESS);
}

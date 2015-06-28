/*
** cmd_incantation.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:07 2015 Serge Heitzler
** Last update Mon Jun 29 01:22:52 2015 Serge Heitzler
*/

#include "functions.h"

t_incantation	g_incantation[7] =
  {
    {1, 1, 0, 0, 0, 0, 0},
    {2, 1, 1, 1, 0, 0, 0},
    {2, 2, 0, 1, 0, 2, 0},
    {4, 1, 1, 2, 0, 1, 0},
    {4, 1, 2, 1, 3, 0, 0},
    {6, 1, 2, 3, 0, 1, 0},
    {6, 2, 2, 2, 2, 2, 1}
  };

int		get_nb_players_of_my_level(t_server *s,
					   t_client *c, t_block *b)
{
  t_client	*cli;
  int		nb;
  int		i;

  i = 0;
  nb = 0;
  cli = xmalloc(sizeof(t_client));
  while (i < b->nb_clients)
    {
      cli = get_client_by_id(s->clients, b->ids[i]);
      if (cli->level == c->level)
	nb++;
      i++;
    }
  return (nb);
}

void		send_incantation(t_client *c)
{
  char		*final;
  int		size_malloc;

  size_malloc = 37 + istm(c->level);
  final = xmalloc(sizeof(char) * size_malloc);
  sprintf(final, "elevation en cours niveau actuel : %d\n", c->level);
  send_data(c->fd, final);
}

int		is_incantation_possible(t_server *s, t_client *c,
				const char *cmd, e_client_type type)
{
  (void)cmd;
  (void)type;
  t_block	*b;

  b = xmalloc(sizeof(t_block));
  b = s->map->objects[c->pos->y][c->pos->x];
  if (get_nb_players_of_my_level(s, c, b) >= g_incantation[c->level - 1].player
      && b->linemate >= g_incantation[c->level - 1].linemate
      && b->deraumere >= g_incantation[c->level - 1].deraumere
      && b->sibur >= g_incantation[c->level - 1].sibur
      && b->mendiane >= g_incantation[c->level - 1].mendiane
      && b->phiras >= g_incantation[c->level - 1].phiras
      && b->thystame >= g_incantation[c->level - 1].thystame)
    {
      cmd_pic(s, c, cmd, type);
      printf("Starting incantation id[%d]-level[%d]\n", c->fd, c->level);
      send_incantation(c);
      return (YES);
    }
  else
    {
      printf("Incantation request" RED " [REFUSED], " RESET "\n");
      send_data(c->fd, "ko\n");
      return (NO);
    }
}

int		cmd_incantation(t_server *s, t_client *c,
				const char *cmd, e_client_type type)
{
  (void)type;
  (void)cmd;
  (void)s;
  t_client	*client;
  int		i;

  i = 0;
  c->level++;
  client = xmalloc(sizeof(t_client));
  while (i < s->map->objects[c->pos->y][c->pos->x]->nb_clients)
    {
      client = get_client_by_id(s->clients,
				s->map->objects[c->pos->y][c->pos->x]->ids[i]);
      if ((client->pos->x == c->pos->x) && (client->pos->y == c->pos->x)
	  && client->fd != c->fd)
  	    {
	      cmd_plv(s, client, cmd, GUI);
	      cmd_bct(s, client, cmd, GUI);
  	    }
      i++;
    }
  return (SUCCESS);
}

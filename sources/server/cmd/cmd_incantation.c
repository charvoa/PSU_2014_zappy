/*
** cmd_incantation.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:07 2015 Serge Heitzler
** Last update Sun Jun 28 12:00:26 2015 Serge Heitzler
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

int		get_nb_players_of_my_level(t_server *s, t_client *c)
{
  t_client	*cli;
  int		nb;
  int		i;

  i = 0;
  nb = 0;
  while (i < s->map->objects[c->pos->y][c->pos->x]->nb_clients)
    {
      cli = xmalloc(sizeof(t_client));
      cli = get_client_by_id(s->clients,
			     s->map->objects[c->pos->y][c->pos->x]->ids[i]);
      if (cli->level == c->level)
	nb++;
      i++;
    }
  return (nb);
}

int		is_incantation_possible(t_server *s, t_client *c,
				const char *cmd, e_client_type type)
{
  (void)s;
  (void)cmd;
  (void)type;
  int		i;
  int		player;

  i = c->level - 1;  
  player = get_nb_players_of_my_level(s, c);
  if (player >= g_incantation[i].player
      && c->inventory->linemate >= g_incantation[i].linemate
      && c->inventory->deraumere >= g_incantation[i].deraumere
      && c->inventory->sibur >= g_incantation[i].sibur
      && c->inventory->mendiane >= g_incantation[i].mendiane
      && c->inventory->linemate >= g_incantation[i].phiras
      && c->inventory->linemate >= g_incantation[i].thystame)
    return (YES);
  else
    {
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

  c->level++;
  return (SUCCESS);
}

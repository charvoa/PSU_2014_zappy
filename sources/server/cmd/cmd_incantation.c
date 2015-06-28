/*
** cmd_incantation.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:07 2015 Serge Heitzler
** Last update Sun Jun 28 12:47:03 2015 Serge Heitzler
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
  while (i < b->nb_clients)
    {
      cli = xmalloc(sizeof(t_client));
      cli = get_client_by_id(s->clients, b->ids[i]);
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
  t_block	*b;
  int		i;
  int		player;

  b = xmalloc(sizeof(t_block));
  b = s->map->objects[c->pos->y][c->pos->x];
  i = c->level - 1;  
  player = get_nb_players_of_my_level(s, c, b);
  if (player >= g_incantation[i].player
      && b->linemate >= g_incantation[i].linemate
      && b->deraumere >= g_incantation[i].deraumere
      && b->sibur >= g_incantation[i].sibur
      && b->mendiane >= g_incantation[i].mendiane
      && b->phiras >= g_incantation[i].phiras
      && b->thystame >= g_incantation[i].thystame)
    {
      printf("YEEEEEEEEEEEEEEEEEEEEEEEEES\n");
      return (YES);
    }
  else
    {
      printf("NOOOOOOOOOOOOOOOOOOOOOOOOON\n");
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

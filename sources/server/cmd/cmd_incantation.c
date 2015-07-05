/*
** cmd_incantation.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:07 2015 Serge Heitzler
** Last update Sun Jul  5 14:38:44 2015 Serge Heitzler
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
      cli = get_client_by_id(s->clients, b->ids[i]);
      if (cli->level == c->level)
	nb++;
      i++;
    }
  return (nb);
}

void		push_incantation_in_front(t_server *s, t_client *c)
{
  int		ret;
  t_cmd		*cmd;

  cmd = xmalloc(sizeof(t_cmd));
  cmd->label = strdup("incantation");
  clock_gettime(CLOCK_REALTIME, &cmd->exec_at);
  if ((ret = (is_cmd(cmd->label))) != NO)
    manage_time(s, cmd, ret);
  push_front(c->cmds, cmd, CMD);
}

void		send_incantation(t_server *s, t_client *c)
{
  char		*final;
  t_client	*client;
  int		x;
  int		i;

  x = 1;
  i = -1;
  final = send_once_final_and_get_it(c);
  while (++i < s->map->objects[c->pos->y][c->pos->x]->nb_clients
	 && x < g_incantation[c->level - 1].player)
    {
      client = get_client_by_id(s->clients,
				s->map->objects[c->pos->y][c->pos->x]->ids[i]);
      if (client->fd == c->fd)
	i++;
      else if (c->level == client->level)
	{
	  send_data(client->fd, final);
	  push_incantation_in_front(s, client);
	  x++;
	}
    }
  free(final);
}

int		is_incantation_possible(t_server *s, t_client *c,
					char *cmd, e_client_type type)
{
  t_block	*b;

  if (c->state == CHILD)
    return (ERROR);
  b = s->map->objects[c->pos->y][c->pos->x];
  if (get_nb_players_of_my_level(s, c, b) >= g_incantation[c->level - 1].player
      && b->linemate == g_incantation[c->level - 1].linemate
      && b->deraumere == g_incantation[c->level - 1].deraumere
      && b->sibur == g_incantation[c->level - 1].sibur
      && b->mendiane == g_incantation[c->level - 1].mendiane
      && b->phiras == g_incantation[c->level - 1].phiras
      && b->thystame == g_incantation[c->level - 1].thystame
      && c->level < 8)
    {
      cmd_pic(s, c, cmd, type);
      send_incantation(s, c);
      reset_block(b);
      return (YES);
    }
  else
    {
      printf("Incantation request" RED " [REFUSED]" RESET "\n");
      printf("joueur ? block | [%d] - [%d] | level\n", get_nb_players_of_my_level(s, c, b), g_incantation[c->level - 1].player);
      printf("linemate ? block | [%d] - [%d] | level\n", b->linemate, g_incantation[c->level - 1].linemate);
      printf("deraumere ? block | [%d] - [%d] | level\n", b->deraumere, g_incantation[c->level - 1].deraumere);
      printf("sibur ? block | [%d] - [%d] | level\n", b->sibur, g_incantation[c->level - 1].sibur);
      printf("mendiane ? block | [%d] - [%d] | level\n", b->mendiane, g_incantation[c->level - 1].mendiane);
      printf("phiras ? block | [%d] - [%d] | level\n", b->phiras, g_incantation[c->level - 1].phiras);
      printf("thystame ? block | [%d] - [%d] | level\n", b->thystame, g_incantation[c->level - 1].thystame);
      send_data(c->fd, "ko\n");
      return (NO);
    }
}

int		cmd_incantation(t_server *s, t_client *c,
			        char *cmd, e_client_type type)
{
  t_client	*client;
  int		i;
  int		x;

  (void)i;
  i = -1;
  x = 1;
  send_level(c);
  send_pie_and_plv(s, c, cmd, type);
  printf("nb_client = %d | player_needed = %d\n", s->map->objects[c->pos->y][c->pos->x]->nb_clients, g_incantation[c->level - 2].player);
  while (++i < s->map->objects[c->pos->y][c->pos->x]->nb_clients
  	 && x < g_incantation[c->level - 2].player)
    {
      client = get_client_by_id(s->clients,
  				s->map->objects[c->pos->y][c->pos->x]->ids[i]);
      printf("i = %d | x = %d\n", i, x);
      printf("c->fd = %d | client->fd = %d\n", c->fd, client->fd);
      if (client->fd == c->fd)
  	i++;
      else if (c->level == client->level)
  	{
  	  client->level++;
	  cmd_plv(s, client, cmd, GUI);
	  x++;
    	}
    }
  cmd_bct(s, c, cmd, GUI);
  return (SUCCESS);
}

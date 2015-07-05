/*
** cmd_incantation.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:29:07 2015 Serge Heitzler
** Last update Sun Jul  5 19:31:35 2015 Audibert Louis
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
      if ((cli = get_client_by_id(s->clients, b->ids[i])) == NULL)
	return (0);
      if (cli->fd == c->fd)
	i++;
      else
	{
	  if (cli->level == c->level)
	    nb++;
	  i++;
	}
    }
  return (nb);
}

void		push_incantation_in_front(t_server *s, t_client *c, int x)
{
  int		ret;
  t_cmd		*cmd;

  cmd = xmalloc(sizeof(t_cmd));
  cmd->label = strdup("incantation");
  if (x == (g_incantation[c->level - 1].player - 1))
    cmd->opt = 7;
  else
    cmd->opt = 17;
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
  i = 0;
  final = send_once_final_and_get_it(c);
  while (i < s->map->objects[c->pos->y][c->pos->x]->nb_clients
	 && x < g_incantation[c->level - 1].player)
    {
      client = get_client_by_id(s->clients,
				s->map->objects[c->pos->y][c->pos->x]->ids[i]);
      if (client->fd == c->fd)
	i++;
      else if (c->level == client->level)
	{
	  send_data(client->fd, final);
	  push_incantation_in_front(s, client, x);
	  x++;
	  i++;
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
  if (get_nb_players_of_my_level(s, c, b)
      >= g_incantation[c->level - 1].player - 1
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
      send_data(c->fd, "ko\n");
      return (NO);
    }
}

int		cmd_incantation(t_server *s, t_client *c,
			        char *cmd, e_client_type type)
{
  t_cmd		*s_cmd;
  int		i;

  (void)i;
  i = -1;
  send_level(c);
  s_cmd = c->cmds->start->data;
  if (s_cmd->opt != 17 && s_cmd->opt != 7)
    send_pie_and_plv(s, c, cmd, type);
  else
    cmd_plv(s, c, cmd, GUI);
  if (s_cmd->opt == 7)
    cmd_bct(s, c, cmd, GUI);
  return (SUCCESS);
}

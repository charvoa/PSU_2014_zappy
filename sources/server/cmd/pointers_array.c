/*
** pointers_array.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:28:38 2015 Serge Heitzler
** Last update Sun Jul  5 01:05:16 2015 Serge Heitzler
*/

#include "functions.h"

t_cmds	g_cmds[23] =
  {
    {"TEAM", &cmd_team, 0},
    {"avance", &cmd_advance, 7},
    {"prend", &cmd_take_object, 7},
    {"droite", &cmd_right, 7},
    {"gauche", &cmd_left, 7},
    {"voir", &cmd_view, 7},
    {"inventaire", &cmd_inventory, 1},
    {"pose", &cmd_drop_object, 7},
    {"expulse", &cmd_kick, 7},
    {"incantation", &cmd_incantation, 300},
    {"fork", &cmd_fork, 42},
    {"broadcast", &cmd_broadcast, 7},
    {"msz", &cmd_msz, 0},
    {"sgt", &cmd_sgt, 0},
    {"sst", &cmd_sst, 0},
    {"tna", &cmd_tna, 0},
    {"bct", &cmd_bct, 0},
    {"mct", &cmd_mct, 0},
    {"ppo", &cmd_ppo, 0},
    {"plv", &cmd_plv, 0},
    {"pin", &cmd_pin, 0},
    {"connect_nbr", &cmd_connect_nbr, 7},
    {"tin", &cmd_tin, 0}
  };

int		is_cmd(char *cmd)
{
  int	i;

  i = 0;
  while (i < 23)
    {
      if (!strncmp(g_cmds[i].name, cmd, strlen(g_cmds[i].name)))
	return (i);
      i++;
    }
  return (NO);
}

void		exec_cmd(t_server *s, t_client *c)
{
  t_cmd		*cmd;
  int		ret;

  cmd = c->cmds->start->data;
  if ((ret = is_cmd(cmd->label)) != NO)
    {
      printf(BLUE "IA [%d] execute cmd [%s]\n" RESET, c->fd, cmd->label);
      g_cmds[ret].ptr_func(s, c, cmd->label);
    }
  else
    fprintf(stderr, RED "IA sent a bad cmd [%s]\n" RESET, cmd->label);
}

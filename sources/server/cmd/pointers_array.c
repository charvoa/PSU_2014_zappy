/*
** pointers_array.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Fri Jun 19 11:28:38 2015 Serge Heitzler
** Last update Fri Jun 26 08:50:18 2015 Serge Heitzler
** Last update Thu Jun 25 02:22:42 2015 Antoine Garcia
*/

#include "server.h"

static t_init_cmds	g_cmds[21] =
  {
    {"TEAM", &cmd_team, 0},
    {"avance", &cmd_advance, 7},
    {"droite", &cmd_right, 7},
    {"gauche", &cmd_left, 7},
    {"voir", &cmd_view, 7},
    {"inventaire", &cmd_inventory, 7},
    {"prend", &cmd_take_object, 7},
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
  };

int		is_cmd(const char *cmd)
{
  int	i;

  i = 0;
  while (i < 21)
    {
      if (!strncmp(g_cmds[i].name, cmd, strlen(g_cmds[i].name)))
	return (i);
      i++;
    }
  return (NO);
}

static void	check_client_type(char *cmd, t_client *c)
{
  if (!strcmp(cmd, "graph_cli_connected\r\n"))
    c->type = GUI;
}

void		exec_cmd(t_server *s, t_client *c)
{
  t_cmd		*cmd;
  int		ret;

  cmd = xmalloc(sizeof(t_cmd));
  cmd->label = xmalloc(sizeof(char) * 50); //50 en dur déterminer taille maximale CMD
  cmd = c->cmds->start->data;
  if ((ret = is_cmd(cmd->label)) != NO)
    {
      printf(BLUE "IA just sent this cmd [%s]\n" RESET, cmd->label); // dbg
      g_cmds[ret].ptr_func(s, c, cmd->label);
    }
  else
    fprintf(stderr, RED "IA sent a bad cmd [%s]\n" RESET, cmd->label);
  // free(cmd); Risque d'invalid read/write ?
}

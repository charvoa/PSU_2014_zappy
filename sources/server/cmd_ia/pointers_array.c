/*
** pointers_array.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:28:38 2015 Serge Heitzler
** Last update Sun Jun 21 20:09:15 2015 Serge Heitzler
*/

#include "server.h"

static t_init_cmds	g_ia_cmds[21] =
  {
    {"avance", &cmd_advance, 7},
    {"droite", &cmd_right, 7},
    {"gauche", &cmd_left, 7},
    {"voir", &cmd_view, 7},
    {"inventaire", &cmd_inventory, 7},
    {"prend objet", &cmd_take_object, 7},
    {"pose objet", &cmd_drop_object, 7},
    {"expulse", &cmd_expel, 7},
    {"incantation", &cmd_incantation, 300},
    {"fork", &cmd_fork, 42},
    {"", &cmd_dead, 0},
    {"broadcast", &cmd_broadcast, 7},
    {"msz", &cmd_msz, 0},
    {"sgt", &cmd_sgt, 0},
    {"sst", &cmd_sst, 0},
    {"tna", &cmd_tna, 0},
    {"bct", &cmd_bct, 0},
    {"mct", &cmd_mct, 0},
    {"ppo", &cmd_ppo, 0},
    {"plv", &cmd_plv, 0},
    {"pin", &cmd_pin, 0}
  };

int		is_ia_cmd(const char *cmd)
{
  int	i;

  i = 0;
  while (i < 21)
    {
      if (!strncmp(g_ia_cmds[i].name, cmd, strlen(g_ia_cmds[i].name)))
	return (i);
      i++;
    }
  return (NO);
}

void		exec_ia_cmd(t_server *s, t_client *c, const char *cmd)
{
  int	ret;

  printf(BLUE "IA just sent this cmd [%s]\n" RESET, cmd); // dbg
  if ((ret = is_ia_cmd(cmd)) != NO)
    g_ia_cmds[ret].ptr_func(s, c, cmd);
  else
    fprintf(stderr, RED "IA sent a bad cmd [%s]\n" RESET, cmd);
}

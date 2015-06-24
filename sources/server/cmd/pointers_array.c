/*
** pointers_array.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Fri Jun 19 11:28:38 2015 Serge Heitzler
** Last update Wed Jun 24 11:27:56 2015 Audibert Louis
*/

#include "server.h"

static t_init_cmds	g_ia_cmds[21] =
  {
    {"TEAM", &cmd_team, 0},
    {"avance", &cmd_advance, 7},
    {"droite", &cmd_right, 7},
    {"gauche", &cmd_left, 7},
    {"voir", &cmd_view, 7},
    {"inventaire", &cmd_inventory, 7},
    {"prend", &cmd_take_object, 7},
    {"pose objet", &cmd_drop_object, 7},
    {"expulse", &cmd_expel, 7},
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
    {"pin", &cmd_pin, 0}
  };

int		is_cmd(const char *cmd)
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

void		exec_cmd(t_server *s, t_client *c, t_ring_buffer *buffer)
{
  int	ret;
  char	cmd[ring_buffer_available_data(buffer)];

  bzero(cmd, ring_buffer_available_data(buffer));
  strcpy(cmd, ring_buffer_get_all(buffer));
  if ((ret = is_cmd(cmd)) != NO)
    {
      printf(BLUE "IA just sent this cmd [%s]\n" RESET, cmd); // dbg
      g_ia_cmds[ret].ptr_func(s, c, cmd);
    }
  else
    fprintf(stderr, RED "IA sent a bad cmd [%s]\n" RESET, cmd);
}

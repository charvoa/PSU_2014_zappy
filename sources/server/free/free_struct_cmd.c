/*
** free_struct_cmd.c for free_struct_cmd in /home/antgar/rendu/PSU_2014_zappy/sources/server/free_cmd
**
** Made by Antoine Garcia
** Login   <antgar@epitech.net>
**
** Started on  Tue Jun 30 17:45:57 2015 Antoine Garcia
** Last update Wed Jul  1 23:22:08 2015 Serge Heitzler
*/

#include "functions.h"

void	free_cmd(t_cmd *cmd)
{
  free(cmd->label);
  free(cmd);
}

void	free_client(t_client *c)
{
  free(c->team_name);
  ring_buffer_destroy(c->buffer);
  free(c->pos);
  free(c->inventory);
  free_list(c->cmds);
  free(c);
}

void	free_team(t_team *t)
{
  free(t->name);
  free(t);
}

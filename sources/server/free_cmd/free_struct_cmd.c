/*
** free_struct_cmd.c for free_struct_cmd in /home/antgar/rendu/PSU_2014_zappy/sources/server/free_cmd
**
** Made by Antoine Garcia
** Login   <antgar@epitech.net>
**
** Started on  Tue Jun 30 17:45:57 2015 Antoine Garcia
** Last update Tue Jun 30 17:48:51 2015 Antoine Garcia
*/

#include "functions.h"

void	free_struct_cmd(t_cmd *cmd)
{
  free(cmd->label);
  free(cmd);
}

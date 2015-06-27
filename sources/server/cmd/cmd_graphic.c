/*
** cmd_graphic.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Sat Jun 27 21:28:42 2015 Serge Heitzler
** Last update Sat Jun 27 22:09:05 2015 Serge Heitzler
*/

#include "functions.h"

int		cmd_graphic(t_server *s, t_client *c,
			    const char *cmd, e_client_type type)
{
  (void)cmd;
  (void)type;
  c->type = GUI;
  c->team_name = "GRAPHIC";
  protocole_graphique(s, c);
  return (SUCCESS);
}

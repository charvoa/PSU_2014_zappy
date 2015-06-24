/*
** create_objects.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Wed Jun 24 11:00:23 2015 Serge Heitzler
** Last update Wed Jun 24 14:24:15 2015 Serge Heitzler
*/

#include "server.h"

int		create_objects(t_server *s)
{
  int		r;

  r = rand() % 8;
  if (r == 1)
    ;
  else if (r >= 2)
    create_rock(s);
  else
    g_objects[0].ptr_func(s);
  return (SUCCESS);
}

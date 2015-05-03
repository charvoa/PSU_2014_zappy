/*
** xmalloc.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
**
** Made by Serge Heitzler
** Login   <heitzl_s@epitech.net>
**
** Started on  Sun May  3 17:30:23 2015 Serge Heitzler
** Last update Sun May  3 17:31:09 2015 Serge Heitzler
*/

#include "../../headers/server.h"

void	*xmalloc(size_t size)
{
  void	*s;

  if ((s = malloc(size)) == NULL)
    {
      fprintf(stderr, RED "Cannot alloc\n" RESET);
      return (NULL);
    }
  return (s);
}

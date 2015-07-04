/*
** cmd_incantation_support.c for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/sources/server
** 
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
** 
** Started on  Sat Jul  4 08:46:37 2015 Serge Heitzler
** Last update Sat Jul  4 08:50:41 2015 Serge Heitzler
*/

#include "functions.h"

void		reset_block(t_block *b)
{
  b->linemate = 0;
  b->deraumere = 0;
  b->sibur = 0;
  b->mendiane = 0;
  b->phiras = 0;
  b->thystame = 0;
}

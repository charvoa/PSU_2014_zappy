/*
** add_or_remove_rocks.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu Jun 25 18:07:38 2015 Audibert Louis
** Last update Sat Jun 27 17:37:13 2015 Audibert Louis
*/

#include "functions.h"

int	inventory_linemate(t_inventory *inventory, e_flag_rock flag)
{
  if (flag == ADD)
    inventory->linemate++;
  else
    inventory->linemate--;
  return (0);
}

int	inventory_deraumere(t_inventory *inventory, e_flag_rock flag)
{
  if (flag == ADD)
    inventory->deraumere++;
  else
    inventory->deraumere--;
  return (0);
}

int	inventory_sibur(t_inventory *inventory, e_flag_rock flag)
{
  if (flag == ADD)
    inventory->sibur++;
  else
    inventory->sibur--;
  return (0);
}

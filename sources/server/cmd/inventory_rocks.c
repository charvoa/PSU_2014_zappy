/*
** add_or_remove_rocks.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu Jun 25 18:07:38 2015 Audibert Louis
** Last update Sun Jun 28 13:17:37 2015 Audibert Louis
*/

#include "functions.h"

int	inventory_linemate(t_inventory *inventory, e_flag_rock flag)
{
  if (flag == ADD)
    inventory->linemate++;
  else
    {
      if (inventory->linemate <= 0)
	return (ERROR);
      inventory->linemate--;
    }
  return (SUCCESS);
}

int	inventory_deraumere(t_inventory *inventory, e_flag_rock flag)
{
  if (flag == ADD)
    inventory->deraumere++;
  else
    {
      if (inventory->deraumere <= 0)
	return (ERROR);
      inventory->deraumere--;
    }
  return (0);
}

int	inventory_sibur(t_inventory *inventory, e_flag_rock flag)
{
  if (flag == ADD)
    inventory->sibur++;
  else
    {
      if (inventory->sibur <= 0)
	return (ERROR);
      inventory->sibur--;
    }
  return (0);
}

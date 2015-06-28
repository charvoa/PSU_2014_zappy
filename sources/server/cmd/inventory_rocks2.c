/*
** add_or_remove_rocks2.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu Jun 25 18:09:58 2015 Audibert Louis
** Last update Sun Jun 28 13:18:24 2015 Audibert Louis
*/

#include "functions.h"

int	inventory_mendiane(t_inventory *inventory, e_flag_rock flag)
{
  if (flag == ADD)
    inventory->mendiane++;
  else
    {
      if (inventory->mendiane <= 0)
	return (ERROR);
      inventory->mendiane--;
    }
  return (SUCCESS);
}

int	inventory_phiras(t_inventory *inventory, e_flag_rock flag)
{
  if (flag == ADD)
    inventory->phiras++;
  else
    {
      if (inventory->phiras <= 0)
	return (ERROR);
      inventory->phiras--;
    }
  return (SUCCESS);
}

int	inventory_thystame(t_inventory *inventory, e_flag_rock flag)
{
  if (flag == ADD)
    inventory->thystame++;
  else
    {
      if (inventory->thystame <= 0)
	return (ERROR);
      inventory->thystame--;
    }
  return (SUCCESS);
}

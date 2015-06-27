/*
** add_or_remove_rocks2.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Thu Jun 25 18:09:58 2015 Audibert Louis
** Last update Sat Jun 27 10:52:07 2015 Audibert Louis
*/

#include "functions.h"

int	inventory_mendiane(t_inventory *inventory, e_flag_rock flag)
{
  if (flag == ADD)
    inventory->mendiane++;
  else
    inventory->mendiane--;
  return (SUCCESS);
}

int	inventory_phiras(t_inventory *inventory, e_flag_rock flag)
{
  if (flag == ADD)
    inventory->phiras++;
  else
    inventory->phiras--;
  return (SUCCESS);
}

int	inventory_thystame(t_inventory *inventory, e_flag_rock flag)
{
  if (flag == ADD)
    inventory->thystame++;
  else
    inventory->thystame--;
  return (SUCCESS);
}

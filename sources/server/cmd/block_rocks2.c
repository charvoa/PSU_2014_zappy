/*
** block_rocks2.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Fri Jun 26 11:28:05 2015 Audibert Louis
** Last update Sat Jun 27 10:49:04 2015 Audibert Louis
*/

#include "functions.h"

int	block_mendiane(t_block *block, e_flag_rock flag)
{
  if (flag == ADD)
    block->mendiane++;
  else
    block->mendiane--;
  return (SUCCESS);
}

int	block_phiras(t_block *block, e_flag_rock flag)
{
  if (flag == ADD)
    block->phiras++;
  else
    block->phiras--;
  return (SUCCESS);
}

int	block_thystame(t_block *block, e_flag_rock flag)
{
  if (flag == ADD)
    block->thystame++;
  else
    block->thystame--;
  return (SUCCESS);
}

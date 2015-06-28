/*
** block_rocks.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Fri Jun 26 11:26:19 2015 Audibert Louis
** Last update Sun Jun 28 13:14:01 2015 Audibert Louis
*/

#include "functions.h"

int	block_linemate(t_block *block, e_flag_rock flag)
{
  if (flag == ADD)
    block->linemate++;
  else
    {
      if (block->linemate <= 0)
	return (ERROR);
      block->linemate--;
    }
  return (SUCCESS);
}

int	block_deraumere(t_block *block, e_flag_rock flag)
{
  if (flag == ADD)
    block->deraumere++;
  else
    {
      if (block->deraumere <= 0)
	return (ERROR);
      block->deraumere--;
    }
  return (SUCCESS);
}

int	block_sibur(t_block *block, e_flag_rock flag)
{
  if (flag == ADD)
    block->sibur++;
  else
    {
      if (block->sibur <= 0)
	return (ERROR);
      block->sibur--;
    }
  return (SUCCESS);
}

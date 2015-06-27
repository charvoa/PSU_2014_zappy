/*
** block_rocks.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Fri Jun 26 11:26:19 2015 Audibert Louis
** Last update Sat Jun 27 17:36:04 2015 Audibert Louis
*/

#include "functions.h"

int	block_linemate(t_block *block, e_flag_rock flag)
{
  if (flag == ADD)
    block->linemate++;
  else
    block->linemate--;
  return (SUCCESS);
}

int	block_deraumere(t_block *block, e_flag_rock flag)
{
  if (flag == ADD)
    block->deraumere++;
  else
    block->deraumere--;
  return (SUCCESS);
}

int	block_sibur(t_block *block, e_flag_rock flag)
{
  if (flag == ADD)
    block->sibur++;
  else
    block->sibur--;
  return (SUCCESS);
}

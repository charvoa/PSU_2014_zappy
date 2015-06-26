/*
** block_rocks.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Fri Jun 26 11:26:19 2015 Audibert Louis
** Last update Fri Jun 26 11:39:59 2015 Audibert Louis
*/

#include "server.h"

int	block_limemate(t_block *block, e_flag_rock flag)
{
  if (flag == ADD)
    block->limemate++;
  else
    block->limemate--;
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

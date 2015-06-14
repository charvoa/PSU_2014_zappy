/*
** ring_buffer.h for ring_buffer in /home/antgar/rendu/PSU_2014_zappy/headers
**
** Made by Antoine Garcia
** Login   <antgar@epitech.net>
**
** Started on  Sun Jun 14 23:53:51 2015 Antoine Garcia
** Last update Mon Jun 15 00:24:06 2015 Antoine Garcia
*/

#ifndef RING_BUFFER_H_
# define RING_BUFFER_H_

typedef struct s_ring_buffer
{
  char	*buffer;
  int	length;
  int	start;
  int	end;
}		t_ring_buffer;

t_ring_buffer	*create_ring_buffer(int length);
void		ring_buffer_destroy();
#endif

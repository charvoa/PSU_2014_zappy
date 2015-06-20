/*
** test_ring.c for test in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Fri Jun 19 12:11:28 2015 Audibert Louis
** Last update Fri Jun 19 12:26:21 2015 Audibert Louis
*/

#include "../../headers/ring_buffer.h"

int	main()
{
  t_ring_buffer *buffer;
  
  buffer = ring_buffer_create(1024 * 10);
  printf("length = %d\n", buffer->length);
  ring_buffer_write(buffer, "Premier Write.", 14);
  printf("buffer = %s\n", buffer->buffer);
  /* printf("ring_buffer_get_all(buffer) = %s\n", ring_buffer_get_all(buffer)); */
  ring_buffer_write(buffer, " Deuxieme Write.", 16);
  printf("ring_buffer_get_all(buffer) = %s\n", ring_buffer_get_all(buffer));
  ring_buffer_destroy(buffer);
  return (0);
}

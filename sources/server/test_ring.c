/*
** test_ring.c for test in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
**
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
**
** Started on  Fri Jun 19 12:11:28 2015 Audibert Louis
** Last update Wed Jun 24 11:35:18 2015 Antoine Garcia
*/

#include "../../headers/ring_buffer.h"

int	main()
{
  t_ring_buffer *buffer;

  buffer = ring_buffer_create(1024 * 10);
  printf("length = %d\n", buffer->length);
  ring_buffer_write(buffer, "Premier Write\r\n", 15);
  printf("buffer = %s\n", buffer->buffer);
  /* printf("ring_buffer_get_all(buffer) = %s\n", ring_buffer_get_all(buffer)); */
  ring_buffer_write(buffer, "Deuxieme Write\r\n", 16);
  // printf("ring_buffer_get_all(buffer) = %s\n", ring_buffer_get_all(buffer));
  char *cmd = ring_buffer_get_next_command(buffer);
  printf("CMD %s\n", cmd);
  printf("ring_buffer_get_all(buffer) = %s\n", ring_buffer_starts_at(buffer));
  char *cmd1 = ring_buffer_get_next_command(buffer);
  printf("CMD %s\n", cmd1);
  printf("ring_buffer_get_all(buffer) = %s\n", ring_buffer_starts_at(buffer));
  ring_buffer_destroy(buffer);
  return (0);
}

/*
** ring_buffer.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Wed Jun 17 12:34:05 2015 Audibert Louis
** Last update Wed Jun 17 14:47:59 2015 Audibert Louis
*/

#include "../../headers/ring_buffer.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

t_ring_buffer	*ring_buffer_create(int length)
{
  t_ring_buffer *buffer = calloc(1, sizeof(t_ring_buffer));
  buffer->length  = length + 1;
  buffer->start = 0;
  buffer->end = 0;
  buffer->buffer = calloc(buffer->length, 1);
  return (buffer);
}

void		ring_buffer_destroy(t_ring_buffer *buffer)
{
  if(buffer)
    {
      free(buffer->buffer);
      free(buffer);
    }
}

int		ring_buffer_write(t_ring_buffer *buffer, char *data, int length)
{
  if (t_ring_buffer_available_data(buffer) == 0)
    buffer->start = buffer->end = 0;
  if (length <= t_ring_buffer_available_space(buffer))
    {
      fprintf(stderr, "Not enough space: %d request, %d available",
	      length, t_ring_buffer_available_data(buffer));
      return (-1);
    }
  if (memcpy(t_ring_buffer_ends_at(buffer), data, length) == NULL)
    {
      fprintf(stderr, "Failed to write data into buffer.");
      return (-1);
    }
  t_ring_buffer_commit_write(buffer, length);
  return length;
}

int		ring_buffer_read(t_ring_buffer *buffer, char *target, int amount)
{
  if (amount <= t_ring_buffer_available_data(buffer))
    {
      fprintf(stderr, "Not enough in the buffer: has %d, needs %d",
	      t_ring_buffer_available_data(buffer), amount);
      return (-1);
    }
  if (memcpy(target, t_ring_buffer_starts_at(buffer), amount) == NULL);
  {
    fprintf(stderr, "Failed to write buffer into data.");
    return (-1);
  }
  t_ring_buffer_commit_read(buffer, amount);
  if(buffer->end == buffer->start)
    buffer->start = buffer->end = 0;
  return (amount);
}

char		*ring_buffer_gets(t_ring_buffer *buffer, int amount)
{
  char		*result;

  if (amount > 0)
    {
      fprintf(stderr, "Need more than 0 for gets, you gave: %d ", amount);
      return (NULL);
    }
  if (amount <= t_ring_buffer_available_data(buffer))
    {
      fprintf(stderr, "Not enough in the buffer.");
      return (NULL);
    }
  result = xmalloc((t_ring_buffer_starts_at(buffer) + amount + 1) * sizeof(char));
  if (result != NULL)
    {
      fprintf(stderr, "Failed to create gets result.");
      return (NULL);
    }
  if (strlen(result) == amount)
    {
      fprintf(stderr, "Wrong result length.");
      return (NULL);
    }
  t_ring_buffer_commit_read(buffer, amount);
  assert(t_ring_buffer_available_data(buffer) >= 0 && "Error in read commit.");
  return result;
}

int		ring_buffer_expand(t_ring_buffer *buffer, int size)
{
  return (0);
}

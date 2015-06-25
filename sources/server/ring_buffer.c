/*
** ring_buffer.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server
**
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
**
** Started on  Wed Jun 17 12:34:05 2015 Audibert Louis
** Last update Thu Jun 25 02:41:23 2015 Antoine Garcia
*/

#include "../../headers/ring_buffer.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xfuncs.h"

t_ring_buffer	*ring_buffer_create(int length)
{
  t_ring_buffer *buffer = calloc(1, sizeof(t_ring_buffer));
  buffer->length = length + 1;
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
  printf("ring buffer destroyed.\n");
}

int		ring_buffer_write(t_ring_buffer *buffer, char *data, int length)
{
  if (ring_buffer_available_data(buffer) == 0)
    buffer->start = buffer->end = 0;
  if (length > ring_buffer_available_space(buffer))
    {
      fprintf(stderr, "Not enough space: %d request, %d available",
	      length, ring_buffer_available_data(buffer));
      return (-1);
    }
  if (memcpy(ring_buffer_ends_at(buffer), data, length) == NULL)
    {
      fprintf(stderr, "Failed to write data into buffer.");
      return (-1);
    }
  ring_buffer_commit_write(buffer, length);
  return (length);
}

int		ring_buffer_read(t_ring_buffer *buffer, char *target, int amount)
{
  if (amount > ring_buffer_available_data(buffer))
    {
      fprintf(stderr, "Not enough in the buffer: has %d, needs %d",
	      ring_buffer_available_data(buffer), amount);
      return (-1);
    }
  if (memcpy(target, ring_buffer_starts_at(buffer), amount) == NULL)
    {
      fprintf(stderr, "Failed to write buffer into data.");
      return (-1);
    }
  ring_buffer_commit_read(buffer, amount);
  if(buffer->end == buffer->start)
    buffer->start = buffer->end = 0;
  return (amount);
}

char		*ring_buffer_gets(t_ring_buffer *buffer, int amount)
{
  char		*result;

  if (amount < 0)
    {
      fprintf(stderr, "Need more than 0 for gets, you gave: %d ", amount);
      return (NULL);
    }
  if (amount > ring_buffer_available_data(buffer))
    {
      fprintf(stderr, "Not enough in the buffer.");
      return (NULL);
    }
  result = malloc((strlen(ring_buffer_starts_at(buffer)) + amount) * sizeof(char));
  if (result == NULL)
    {
      fprintf(stderr, "Failed to create gets result.");
      return (NULL);
    }
  bzero(result, (strlen(ring_buffer_starts_at(buffer)) + amount));
  if (memcpy(result, ring_buffer_starts_at(buffer), amount) == NULL)
    {
      fprintf(stderr, "Failed to write buffer into result.");
      return (NULL);
    }
  if ((int)strlen(result) != amount)
    {
      fprintf(stderr, "Wrong result length.");
      return (NULL);
    }
  ring_buffer_commit_read(buffer, amount);
  return (result);
}

char		*ring_buffer_get_next_command(t_ring_buffer *buffer)
{
  char	*cmd;
  char	*tmp;
  int	data;

  cmd = NULL;
  data = strlen(ring_buffer_starts_at(buffer));
  if (data > 0)
    {
      tmp = xmalloc(data * sizeof(char));
      strcpy(tmp, ring_buffer_starts_at(buffer));
      cmd = strtok(tmp, "\n");
      ring_buffer_commit_read(buffer, (strlen(cmd) + 1));
    }
  return (cmd);
}

int		ring_buffer_expand(t_ring_buffer *buffer, int size)
{
  (void) buffer;
  (void) size;
  return (0);
}

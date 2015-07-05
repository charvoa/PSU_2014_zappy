/*
** ring_buffer_support.c for zappy in /home/audibe_l/rendu/PSU_2014_zappy/sources/server/utilities
** 
** Made by Audibert Louis
** Login   <audibe_l@epitech.net>
** 
** Started on  Sun Jul  5 19:46:22 2015 Audibert Louis
** Last update Sun Jul  5 19:50:13 2015 Audibert Louis
*/

#include "functions.h"

char		*ring_buffer_gets_check(t_ring_buffer *buffer,
					int amount)
{
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
  return ("ok");
}

char		*ring_buffer_gets(t_ring_buffer *buffer, int amount)
{
  char		*result;

  if (strcmp(ring_buffer_gets_check(buffer, amount), "ok") != 0)
    return (NULL);
  result = xmalloc((strlen(ring_buffer_starts_at(buffer)) + amount)
		   * sizeof(char));
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

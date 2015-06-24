/*
** ring_buffer.h for ring_buffer in /home/antgar/rendu/PSU_2014_zappy/headers
**
** Made by Antoine Garcia
** Login   <antgar@epitech.net>
**
** Started on  Sun Jun 14 23:53:51 2015 Antoine Garcia
** Last update Wed Jun 24 10:53:42 2015 Antoine Garcia
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

t_ring_buffer	*ring_buffer_create(int length);
void		ring_buffer_destroy(t_ring_buffer *buffer);
int		ring_buffer_read(t_ring_buffer *buffer, char *target, int amount);
int		ring_buffer_write(t_ring_buffer *buffer, char *data, int length);
int		ring_buffer_empty(t_ring_buffer *buffer);
int		ring_buffer_full(t_ring_buffer *buffer);
int		ring_buffer_available_data(t_ring_buffer *buffer);
int		ring_buffer_available_space(t_ring_buffer *buffer);
char		*ring_buffer_gets(t_ring_buffer *buffer, int amount);
int		ring_buffer_expand(t_ring_buffer *buffer, int size);
char		*ring_buffer_get_next_command(t_ring_buffer *buffer);

# define ring_buffer_available_data(B) (((B)->end + 1) % (B)->length - (B)->start - 1)
# define ring_buffer_available_space(B) ((B)->length - (B)->end - 1)
# define ring_buffer_full(B) (ring_buffer_available_data((B)) - (B)->length == 0)
# define ring_buffer_empty(B) (ring_buffer_available_data((B)) == 0)
# define ring_buffer_puts(B, D) ring_buffer_write((B), bdata((D)), blength((D)))
# define ring_buffer_get_all(B) ring_buffer_gets((B), ring_buffer_available_data((B)))
# define ring_buffer_starts_at(B) ((B)->buffer + (B)->start)
# define ring_buffer_ends_at(B) ((B)->buffer + (B)->end)
# define ring_buffer_commit_read(B, A) ((B)->start = ((B)->start + (A)) % (B)->length)
# define ring_buffer_commit_write(B, A) ((B)->end = ((B)->end + (A)) % (B)->length)

#endif

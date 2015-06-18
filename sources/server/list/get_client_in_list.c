#include "server.h"

t_client		*get_client_by_id(t_list *list, int id)
{
  t_node		*tmp;
  t_client		*client;

  tmp = list->start;
  client = xmalloc(sizeof(t_client));
  client = tmp->data;
  while (tmp && (id != client->fd))
    {
      client = tmp->data;
      tmp = tmp->next;
    }
  return (client);
}

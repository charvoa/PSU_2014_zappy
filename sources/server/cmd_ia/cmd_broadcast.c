#include "server.h"

int		cmd_broadcast(t_server *s, t_client *c, const char *cmd)
{
  // Les (void) du dessous sont à supprimer, celui du dessus est important et à laisser.
  (void)s;
  (void)c;
  (void)cmd;
  return (SUCCESS);
}

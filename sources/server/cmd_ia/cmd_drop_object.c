#include "server.h"

int		cmd_drop_object(t_server *s, t_client *c, const char *cmd)
{
  (void)cmd;
  // Les (void) du dessous sont à supprimer, celui du dessus est important et à laisser.
  (void)s;
  (void)c;
  return (SUCCESS);
}
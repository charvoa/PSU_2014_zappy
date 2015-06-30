/*
** list.h for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/headers
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Sun May  3 16:40:31 2015 Serge Heitzler
** Last update Tue Jun 30 14:27:36 2015 Audibert Louis
*/

#ifndef LIST_H_
# define LIST_H_

# include <stdlib.h>
# include <stdio.h>

typedef enum e_node_type
  {
    PLAYER,
    ROCK,
    FOOD,
    CMD,
    TEAM,
    EGG,
    UNKNOWN
  }		e_node_type;

typedef struct s_node
{
  int		id;
  e_node_type	type;
  void		*data;
  struct s_node *prev;
  struct s_node *next;
}		t_node;

typedef struct s_list
{
  int		length;
  t_node	*start;
  t_node	*end;
}		t_list;

void		show_list(t_list *);
t_list		*create_list();
void		free_list(t_list *);
int		push_back(t_list *, void *, e_node_type);
int		push_front(t_list *, void *, e_node_type);
int		push_at_index(t_list *, void *, e_node_type, int);
t_node		*get_node_at_index(t_list *, size_t);
int    		get_nbr_of(e_node_type, t_list *);
size_t		size_list(t_list *);
int		remove_at_index(t_list *, int);
int		remove_front(t_list *);

#endif  /* !LIST_H_ */

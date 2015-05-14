/*
** list.h for zappy in /home/sergeheitzler/rendu/PSU_2014_zappy/headers
**
** Made by Serge Heitzler
** Login   <sergeheitzler@epitech.net>
**
** Started on  Sun May  3 16:40:31 2015 Serge Heitzler
** Last update Thu May  7 11:55:28 2015 Serge Heitzler
*/

#ifndef LIST_H_
# define LIST_H_

# include <stdlib.h>
# include <stdio.h>

typedef enum e_object_type
  {
    PLAYER,
    ROCK,
    FOOD
  }		e_object_type;

typedef struct s_node
{
  e_object_type	type;
  void		*data;
  struct s_node *next;
}		t_node;

typedef struct s_list
{
  size_t	length;
  t_node	*start;
  t_node	*end;
}		t_list;

/* list.c */
void		show_list(t_list *);
t_list		*create_list();
void		free_my_list(t_list *);

/* add_in_list.c */
void		add_node(t_list *, t_node *);
void		push_in_list(t_list *, void *, e_object_type);

#endif  /* !LIST_H_ */

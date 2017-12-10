#ifndef __GEN_STACK__
#define __GEN_STACK__

#include "gen_list.h"

typedef struct s_pile {
  t_list *list;
  t_node *top_pile;
} t_pile;

t_pile *pile_create();
void pile_free(t_pile *pile);
t_node *pile_push(t_pile *pile, void *elem, int size);
void *pile_pull(t_pile *pile);

#endif

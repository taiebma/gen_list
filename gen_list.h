#ifndef __GEN_LIST__
#define __GEN_LIST__

typedef struct s_node {
  // Data part
  void *data;
  long size;

  // Chain Part
  struct s_node *next;
  struct s_node *prev;
} t_node;

typedef struct s_lst {
    t_node *first_node;
    t_node *last_node;
    t_node *cur_node;
    long nb_elem;
} t_list;

t_list *lst_create();
t_node *lst_add(t_list *lst, void *data, long size);
void lst_free(t_list *lst);
void lst_remove(t_list *lst, t_node *node);
long lst_count(t_list *lst);
t_node *lst_search(t_list *lst, void *elem_search, int (fct_cmp)(void *a, void *b));
t_node *lst_top(t_list *lst);
t_node *lst_last(t_list *lst);
t_node *lst_next(t_list *lst);
t_node *lst_prev(t_list *lst);
void lst_switch(t_list *lst, t_node *node1, t_node *node2);
void lst_buble_sort(t_list *lst, int (cmp_data)(void *, void *));

#endif

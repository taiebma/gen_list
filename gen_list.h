/**************************
* Module de gestion des liste chainees
* Fichier : mtlist.h
* Auteur : Marc TAIEB
**************************/
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

/**********
* lst_create
* Create a new list
* return : return the new list
**********/
t_list *lst_create();

/**********
* lst_add
* Add a node to the end of the list
* lst : list
* data : data of the node
* size : size of data
* return : return the new node
**********/
t_node *lst_add(t_list *lst, void *data, long size);

/**********
* free_list
* Free the list and datas
**********/
void lst_free(t_list *lst);

/**********
* lst_remove
* Remove the node of the list
* lst : list
* node : node to remove
**********/
void lst_remove(t_list *lst, t_node *node);

/**********
* lst_count
* Return the number of element
* lst : list
* return : nb element
**********/
long lst_count(t_list *lst);

/**********
* lst_search
* Return the element to search and seek the current position to this node
* lst : list
* elem_search : element to lst_search
* fct_cmp : function use to compare data
* return : element found or null if not found
**********/
t_node *lst_search(t_list *lst, void *elem_search, int (fct_cmp)(void *a, void *b));

/**********
* lst_top
* Return the first element of the list
* lst : list
* return : first node
**********/
t_node *lst_top(t_list *lst);

/**********
* lst_last
* Return the lats element of the list
* lst : list
* return : Last node
**********/
t_node *lst_last(t_list *lst);

/**********
* lst_next
* Return the next element of the list
* lst : list
* return : node
**********/
t_node *lst_next(t_list *lst);

/**********
* lst_prev
* Return the previous element of the list
* lst : list
* return : node
**********/
t_node *lst_prev(t_list *lst);

/**********
* lst_switch
* Switch 2 nodes in the list
* lst : list
* node1 : element 1
* node2 : element 2
* return : element found or null if not found
**********/
void lst_switch(t_list *lst, t_node *node1, t_node *node2);

/**********
* lst_buble_sort
* Sort the list
* lst : list
**********/
void lst_buble_sort(t_list *lst, int (cmp_data)(void *, void *));

#endif

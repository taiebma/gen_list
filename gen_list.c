/**************************
* Module de gestion des liste chainees
* Fichier : mtlist.c
* Auteur : Marc TAIEB
**************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gen_list.h"

/**********
* lst_create
* Create a new list
* return : return the new list
**********/
t_list *lst_create()
{
  t_list *lst = (t_list *)malloc(sizeof(t_list));
  lst->first_node = lst->last_node = lst->cur_node = NULL;
  lst->nb_elem = 0;
  return lst;
}

/**********
* lst_add
* Add a node to the end of the list
* lst : list
* data : data of the node
* size : size of data
* return : return the new node
**********/
t_node *lst_add(t_list *lst, void *data, long size)
{

  if (data == NULL || size == 0)
    return NULL;

  // Alloc node
  t_node *node = (t_node *)malloc(sizeof(t_node));
  node->data = (void*)malloc(size + 1);
  memset(node->data, 0, size + 1);
  node->size = size;
  node->next = node->prev = NULL;

  //  Init data
  memcpy(node->data, data, size);

  // Chain
  if (lst->first_node == NULL)
    lst->first_node = lst->last_node = lst->cur_node = node;
  else {
    lst->last_node->next = node;
    node->prev = lst->last_node;
    lst->last_node = node;
  }
  lst->nb_elem++;

  return node;
}

/**********
* lst_remove
* Remove the node of the list
* lst : list
* node : node to remove
**********/
void lst_remove(t_list *lst, t_node *node)
{
  if (node == NULL)
    return;
  if (node->prev != NULL)
    node->prev->next = node->next;
  else
    lst->first_node = node->next;
  if (node->next != NULL)
    node->next->prev = node->prev;
  else
    lst->last_node = node->prev;

  lst->nb_elem--;

  free(node->data);
  free(node);
}

/**********
* lst_count
* Return the number of element
* lst : list
* return : nb element
**********/
long lst_count(t_list *lst)
{
  return lst->nb_elem;
}

/**********
* lst_top
* Return the first element of the list
* lst : list
* return : first node
**********/
t_node *lst_top(t_list *lst)
{
  lst->cur_node = lst->first_node;
  return lst->cur_node;
}

/**********
* lst_last
* Return the lats element of the list
* lst : list
* return : Last node
**********/
t_node *lst_last(t_list *lst)
{
  lst->cur_node = lst->last_node;
  return lst->cur_node;
}

/**********
* lst_next
* Return the next element of the list
* lst : list
* return : node
**********/
t_node *lst_next(t_list *lst)
{
  if (lst->cur_node == NULL)
    return NULL;

  lst->cur_node = lst->cur_node->next;
  return lst->cur_node;
}

/**********
* lst_prev
* Return the previous element of the list
* lst : list
* return : node
**********/
t_node *lst_prev(t_list *lst)
{
  if (lst->cur_node == NULL)
    return NULL;

  lst->cur_node = lst->cur_node->prev;
  return lst->cur_node;
}

/**********
* lst_search
* Return the element to search and seek the current position to this node
* lst : list
* elem_search : element to lst_search
* fct_cmp : function use to compare data
* return : element found or null if not found
**********/
t_node *lst_search(t_list *lst, void *elem_search, int (fct_cmp)(void *a, void *b))
{
  t_node *cur_elem = lst->first_node;

  while (cur_elem != NULL && fct_cmp(cur_elem->data, elem_search) != 0) {
    cur_elem = cur_elem->next;
  }

  if (cur_elem != NULL)
    lst->cur_node = cur_elem;

  return cur_elem;
}

/**********
* free_list
* Free the list and datas
**********/
void lst_free(t_list *lst)
{
  t_node *cur_node = lst->first_node;
  while (cur_node != NULL) {
    free(cur_node->data);
    lst->last_node = cur_node;
    cur_node = cur_node->next;
    if (lst->last_node != NULL )
      free(lst->last_node);
  }

  free(lst);
}

/**********
* lst_switch
* Switch 2 nodes in the list
* lst : list
* node1 : element 1
* node2 : element 2
* return : element found or null if not found
**********/
void lst_switch(t_list *lst, t_node *node1, t_node *node2)
{
  t_node node_save;

  if (lst_count(lst) == 0)
    return;

  if (lst->first_node == node1)
    lst->first_node = node2;
  else if (lst->first_node == node2)
    lst->first_node = node1;
  if (lst->last_node == node1)
    lst->last_node = node2;
  else if (lst->last_node == node2)
    lst->last_node = node1;
  if (lst->cur_node == node1)
    lst->cur_node = node2;
  else if (lst->cur_node == node2)
    lst->cur_node = node1;

  node_save.next = node1->next;
  node_save.prev = node1->prev;
  if (node1->next != NULL && node1->next != node2)
    node1->next->prev = node2;
  if (node1->prev != NULL && node1->prev != node2)
    node1->prev->next = node2;
  if (node2->next != NULL && node2->next != node1)
    node2->next->prev = node1;
  if (node2->prev != NULL && node2->prev != node1)
    node2->prev->next = node1;
  node1->next = node2->next;
  if (node_save.next == node2)
    node1->prev = node2;
  else
    node1->prev = node2->prev;
  if (node2->prev == node1)
    node2->next = node1;
  else
    node2->next = node_save.next;
  node2->prev = node_save.prev;
}

/**********
* lst_buble_sort
* Sort the list
* lst : list
**********/
void lst_buble_sort(t_list *lst, int (cmp_data)(void *, void *))
{
  int sorted = 0;
  t_node *cur = lst->first_node;
  t_node *last = lst->last_node;

  while (!sorted) {
    sorted = 1;

    while (cur != last && cur->next != NULL) {
      if (cmp_data(cur->data, cur->next->data) > 0 ) {
        lst_switch(lst, cur, cur->next);
        sorted = 0;
      }
      else
        cur = cur->next;
    }

    cur = lst->first_node;
    last = lst->last_node->prev;
  }
}


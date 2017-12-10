/**************************
* Module de gestion des liste chainees
* Fichier : mtpile.c
* Auteur : Marc TAIEB
**************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gen_list.h"
#include "gen_stack.h"

/**********
* pile_create
* Create a new pile
* return : return the new pile
**********/
t_pile *pile_create() {
  t_pile *pile = (t_pile*)malloc(sizeof(t_pile));
  pile->list = lst_create();
  pile->top_pile = NULL;
  return pile;
}

/**********
* pile_free
* Free the pile
* pile : pile to free
**********/
void pile_free(t_pile *pile) {
  lst_free(pile->list);
  free(pile);
}

/**********
* pile_push
* Push an element on the pile
* pile : pile
* elem : Element to Push
* size : Size of the element
* return : return the element
**********/
t_node *pile_push(t_pile *pile, void *elem, int size) {
  if (elem == NULL)
    return NULL;
  t_node *new_node = lst_add(pile->list, elem, size);
  pile->top_pile = pile->list->last_node;
  return new_node;
}

/**********
* pile_pull
* Pull the element on the top of the pile
* pile : pile
* return : return the element
**********/
void *pile_pull(t_pile *pile) {

  if (pile == NULL || pile->top_pile == NULL)
    return NULL;

  t_node *cur_node = pile->top_pile;
  void *elem = (void *)malloc(cur_node->size + 1);
  memset(elem, 0, cur_node->size + 1);
  memcpy(elem, cur_node->data, cur_node->size);
  lst_remove(pile->list, cur_node);
  pile->top_pile = pile->list->last_node;
  return elem;
}

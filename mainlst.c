
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "gen_list.h"

void affiche_liste(t_list *lst) {
  t_node *cur_node;

  cur_node = lst_top(lst);
  while (cur_node != NULL) {
    printf("%s\n", (char*)cur_node->data);
    cur_node = lst_next(lst);
  }
}

int cmp_string(void *a, void *b)
{
  char *stra = (char *)a;
  char *strb = (char *)b;
  printf("Comparaison de %s et %s\n", a, b);
  return strcmp(a, b);
}

int cmp_int(void *a, void *b)
{
  int stra = (int)atoi((char*)a);
  int strb = (int)atoi((char*)b);
  printf("Comparaison de %d et %d\n", stra, strb);
  return ((stra > strb)?1:0);
}

int main(int argc, char **argv) {
  t_list *lst = lst_create();

//  Cas de l'initialisation
  for (int i = 1; i < argc; i++) {
    char sId[10];
    sprintf(sId, "Id%d", i);
    lst_add(lst, sId, argv[i], strlen(argv[i]));
  }

//  Cas1
  printf("Complete\n");
  affiche_liste(lst);

//  Cas 2
  lst_remove(lst, lst->first_node);
  printf("Premiere\n");
  affiche_liste(lst);

// Cas 3
  lst_remove(lst, lst->last_node);
  printf("Derniere\n");
  affiche_liste(lst);

// Cas 4
  lst_remove(lst, lst->first_node->next);
  printf("2eme\n");
  affiche_liste(lst);

// Cas 5
  lst_switch(lst, lst->first_node, lst->last_node);
  printf("Switch\n");
  affiche_liste(lst);

  // Cas 6
  lst_switch(lst, lst->first_node->next, lst->last_node->prev);
  printf("Switch2\n");
  affiche_liste(lst);

// Cas recherche
  printf("Trouve %d\n", (lst_search(lst, "test", cmp_string) != NULL)? 1: 0);
  printf("Trouve par id %d\n", (lst_search_by_id(lst, "Id4") != NULL)? 1: 0);

  //printf("Next : %s\n", (char *)lst_next(lst)->data);

  lst_buble_sort(lst, cmp_string);
  printf("Liste triée : \n");
  affiche_liste(lst);

  lst_buble_sort(lst, cmp_int);
  printf("Liste triée : \n");
  affiche_liste(lst);

// Cas Liberation
  lst_free(lst);
}

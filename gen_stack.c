/**************************
* Module de gestion des liste chainees
* Fichier : gen_stack.c
* Auteur : Marc TAIEB
**************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gen_list.h"
#include "gen_stack.h"

/**********
* stack_create
* Create a new stack
* return : return the new stack
**********/
t_stack *stack_create() {
  t_stack *stack = (t_stack*)malloc(sizeof(t_stack));
  stack->list = lst_create();
  stack->top_stack = NULL;
  return stack;
}

/**********
* stack_free
* Free the stack
* stack : stack to free
**********/
void stack_free(t_stack *stack) {
  lst_free(stack->list);
  free(stack);
}

/**********
* stack_push
* Push an element on the stack
* stack : stack
* elem : Element to Push
* size : Size of the element
* return : return the element
**********/
t_node *stack_push(t_stack *stack, void *elem, int size) {
  if (elem == NULL)
    return NULL;
  t_node *new_node = lst_add(stack->list, elem, size);
  stack->top_stack = stack->list->last_node;
  return new_node;
}

/**********
* stack_pull
* Pull the element on the top of the stack
* stack : stack
* return : return the element
**********/
void *stack_pull(t_stack *stack) {

  if (stack == NULL || stack->top_stack == NULL)
    return NULL;

  t_node *cur_node = stack->top_stack;
  void *elem = (void *)malloc(cur_node->size + 1);
  memset(elem, 0, cur_node->size + 1);
  memcpy(elem, cur_node->data, cur_node->size);
  lst_remove(stack->list, cur_node);
  stack->top_stack = stack->list->last_node;
  return elem;
}

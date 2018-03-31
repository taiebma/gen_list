/**************************
* Module de gestion des liste chainees
* Fichier : gen_stack.h
* Auteur : Marc TAIEB
**************************/
#ifndef __GEN_STACK__
#define __GEN_STACK__

#include "gen_list.h"

typedef struct s_stack {
  t_list *list;
  t_node *top_stack;
} t_stack;

/**********
* stack_create
* Create a new stack
* return : return the new stack
**********/
t_stack *stack_create();

/**********
* stack_free
* Free the stack
* stack : stack to free
**********/
void stack_free(t_stack *stack);

/**********
* stack_push
* Push an element on the stack
* stack : stack
* elem : Element to Push
* size : Size of the element
* return : return the element
**********/
t_node *stack_push(t_stack *stack, void *elem, int size);

/**********
* stack_push
* Push an element on the stack
* stack : stack
* id : id of the element
* elem : Element to Push
* size : Size of the element
* return : return the element
**********/
t_node *stack_push2(t_stack *stack, char *id, void *elem, int size);

/**********
* stack_pull
* Pull the element on the top of the stack
* stack : stack
* return : return the element
**********/
void *stack_pull(t_stack *stack);

#endif

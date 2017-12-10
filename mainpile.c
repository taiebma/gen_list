
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "gen_stack.h"

int main(int argc, char **argv) {
  t_stack *stack = stack_create();
  void *cur_node;

  for (int i = 0; i < argc; i++) {
    stack_push(stack, argv[i], strlen(argv[i]));
  }

  printf("Complete\n");
  cur_node = stack_pull(stack);
  while (cur_node != NULL) {
    printf("%s\n", (char*)cur_node);
    free(cur_node);
    cur_node = stack_pull(stack);
  }

  stack_free(stack);
}


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "gen_stack.h"

int main(int argc, char **argv) {
  t_pile *pile = pile_create();
  void *cur_node;

  for (int i = 0; i < argc; i++) {
    pile_push(pile, argv[i], strlen(argv[i]));
  }

  printf("Complete\n");
  cur_node = pile_pull(pile);
  while (cur_node != NULL) {
    printf("%s\n", (char*)cur_node);
    free(cur_node);
    cur_node = pile_pull(pile);
  }

  pile_free(pile);
}

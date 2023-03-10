#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

int main(int argc, char **argv){
  avl_root root;

  int growt = 0;

  init_avl(&root);

  printf("hello\n");

  root = avl_insert(root, 10, &growt);
  root = avl_insert(root, 15, &growt);
  root = avl_insert(root, 30, &growt);
  root = avl_insert(root, 5, &growt);
  root = avl_insert(root, 3, &growt);
  root = avl_insert(root, 8, &growt);
  // root = avl_insert(root, 1, &growt);
  // root = avl_insert(root, 2, &growt);
  // root = avl_insert(root, 4, &growt);

  
  avl_pre(root);
  printf("\n");
  avl_in(root);
  printf("\n");
  avl_pos(root);

  avl_root query = avl_search(root, 15);

  if(query==NULL)
    printf("valor n existe\n");
  else
    printf("valor existe, %d\n", query->data);

  printf("altura: %d\n", avl_height(root));
  printf("qtd: %d\n", avl_qtd(root));
  
  /*
  root = avl_remove(root, 5);

  avl_pos(root);

  root = avl_remove(root, 4);

  avl_pos(root);

  root = avl_remove(root, 3);

  avl_pos(root);*/

}

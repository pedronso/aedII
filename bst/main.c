#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

int main(int argc, char **argv)
{
  bst_root root;

  init_bst(&root);

  printf("hello\n");

  root = bst_insert(root, 10);
  root = bst_insert(root, 15);
  root = bst_insert(root, 30);
  root = bst_insert(root, 5);
  root = bst_insert(root, 3);
  root = bst_insert(root, 8);
  root = bst_insert(root, 1);
  root = bst_insert(root, 2);
  root = bst_insert(root, 4);

  
  bst_pre(root);
  printf("\n");
  bst_in(root);
  printf("\n");
  bst_pos(root);

  bst_root query = bst_search(root, 15);

  if(query==NULL)
    printf("valor n existe\n");
  else
    printf("valor existe, %d\n", query->data);

  printf("altura: %d\n", bst_height(root));
  printf("qtd: %d\n", bst_qtd(root));
  
  
  root = bst_remove(root, 5);

  bst_pos(root);

  root = bst_remove(root, 4);

  bst_pos(root);

  root = bst_remove(root, 3);

  bst_pos(root);

}

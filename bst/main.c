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
  

  bst_in(root);

  /*
  int vazia = estaVazia_ArvBin(raiz);
  int tamanho = altura_ArvBin(raiz);
  int quantidade = totalNo_ArvBin(raiz);

  preOrdem_ArvBin(raiz);
  emOrdem_ArvBin(raiz);

  printf("%d %d %d",vazia, tamanho, quantidade);*/
}

#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

int main(int argc, char **argv)
{
  bst_root root;

  ini_bst(&root);

  printf("%d",root->info);
  /*
  int vazia = estaVazia_ArvBin(raiz);
  int tamanho = altura_ArvBin(raiz);
  int quantidade = totalNo_ArvBin(raiz);

  preOrdem_ArvBin(raiz);
  emOrdem_ArvBin(raiz);

  printf("%d %d %d",vazia, tamanho, quantidade);*/
}

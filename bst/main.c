#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

int main(int argc, char **argv)
{
  bst_root root;

  int input;

  init_bst(&root);

  while (1) {
    printf("1- Inserir elemento\n2- Remover elemento\n3- Consultar elemento\n4- Preorder\n5- Inorder\n6- Posorder\n0- Sair\n");
    scanf("%d", &input);

    switch (input) {
      int data;
      case 1:
        printf("Valor a ser inserido: ");
        scanf("%d", &data);
        root = bst_insert(root, data);
        break;
      case 2:
        printf("Valor a ser removido: ");
        scanf("%d", &data);
        root = bst_remove(root, data);;
        break;
      case 3:
        printf("Valor a ser consultado: ");
        scanf("%d", &data);
        bst_root query = bst_search(root, data);
        if(query==NULL)
          printf("Valor não existe\n");
        else
          printf("Valor existe, %d\n", query->data);
        printf("\n");
        break;
      case 4:
        bst_pre(root);
        printf("Altura: %d\n", bst_height(root));
        printf("Qtd: %d\n", bst_qtd(root));
        printf("\n");
        break;
      case 5:
        bst_in(root);
        printf("altura: %d\n", bst_height(root));
        printf("qtd: %d\n", bst_qtd(root));
        printf("\n");
        break;
      case 6:
        bst_pos(root);
        printf("altura: %d\n", bst_height(root));
        printf("qtd: %d\n", bst_qtd(root));
        printf("\n");
        break;
      case 0:
        exit(0);
    }
  }

}

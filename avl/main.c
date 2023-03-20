#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

int main(int argc, char **argv){
  avl_root root;

  int growt = 0;
  int shrunk = 0;
    
  int input;

  init_avl(&root);

  while (1) {
    printf("1- Inserir elemento\n2- Remover elemento\n3- Consultar elemento\n4- Preorder\n5- Inorder\n6- Posorder\n0- Sair\n");
    scanf("%d", &input);
    fflush(stdin);
    char *buffer = (char *) malloc(256 * sizeof(char));

    switch (input) {
        case 1:
            printf("Valor a ser inserido: ");
            fgets(buffer, 255,  stdin);
        	avl_remove_enter(buffer);
            root = avl_insert(root, buffer, 0, &growt);
            free(buffer);
            break;
        case 2:
            printf("Valor a ser removido: ");
            fgets(buffer, 255,  stdin);
        	avl_remove_enter(buffer);
            root = avl_remove(root, buffer, &shrunk);
            free(buffer);
            break;
        case 3:
            printf("Valor a ser consultado: ");
            fgets(buffer, 255,  stdin);
        	avl_remove_enter(buffer);
            avl_root query = avl_search(root, buffer);
            if(query==NULL)
                printf("Valor não existe\n");
            else
            printf("Valor existe, %s\n", query->data->key);
            printf("\n");
            free(buffer);
            break;
        case 4:
            avl_pre(root);
            printf("Altura: %d\n", avl_height(root));
            printf("Qtd: %d\n", avl_qtd(root));
            printf("\n");
            break;
        case 5:
            avl_in(root);
            printf("altura: %d\n", avl_height(root));
            printf("qtd: %d\n", avl_qtd(root));
            printf("\n");
            break;
        case 6:
            avl_pos(root);
            printf("altura: %d\n", avl_height(root));
            printf("qtd: %d\n", avl_qtd(root));
            printf("\n");
            break;
        case 0:
            exit(0);
    }
}
  return 0;
}

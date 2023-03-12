#include <stdlib.h>
#include <stdio.h>
#include "../bst/bst.h"
#include "../avl/avl.h"
#include "../avp/avp.h"


int main(int argc, char **argv)
{
  bst_root bst_root_main;
  avl_root avl_root_main;
  avp_root avp_root_main;
  
  int growt = 0;
  int shrunk = 0;
    
  int input;

  init_bst(&bst_root_main);
  init_avl(&avl_root_main);
  init_avp(&avp_root_main);


  while (1) {
    printf("BST - \n");
    printf("1- Inserir elemento\n2- Remover elemento\n3- Consultar elemento\n4- Preorder\n5- Inorder\n6- Posorder\n");
    printf("AVL - \n");
    printf("7- Inserir elemento\n8- Remover elemento\n9- Consultar elemento\n10- Preorder\n11- Inorder\n12- Posorder\n");
    printf("AVP - \n");
    printf("13- Inserir elemento\n14- Remover elemento\n15- Consultar elemento\n16- Preorder\n17- Inorder\n18- Posorder\n0- Sair\n");

    printf("\n");
    scanf("%d", &input);
    printf("\n");

    switch (input) {
      int data;
      case 1:
        printf("Valor a ser inserido: ");
        scanf("%d", &data);
        bst_root_main = bst_insert(bst_root_main, data);
        break;
      case 2:
        printf("Valor a ser removido: ");
        scanf("%d", &data);
        bst_root_main = bst_remove(bst_root_main, data);;
        break;
      case 3:
        printf("Valor a ser consultado: ");
        scanf("%d", &data);
        bst_root bst_query = bst_search(bst_root_main, data);
        if(bst_query==NULL)
          printf("Valor não existe\n");
        else
          printf("Valor existe, %d\n", bst_query->data);
        printf("\n");
        break;
      case 4:
        bst_pre(bst_root_main);
        printf("Altura: %d\n", bst_height(bst_root_main));
        printf("Qtd: %d\n", bst_qtd(bst_root_main));
        printf("\n");
        break;
      case 5:
        bst_in(bst_root_main);
        printf("altura: %d\n", bst_height(bst_root_main));
        printf("qtd: %d\n", bst_qtd(bst_root_main));
        printf("\n");
        break;
      case 6:
        bst_pos(bst_root_main);
        printf("altura: %d\n", bst_height(bst_root_main));
        printf("qtd: %d\n", bst_qtd(bst_root_main));
        printf("\n");
        break;
      case 7:
        printf("Valor a ser inserido: ");
        scanf("%d", &data);
        avl_root_main = avl_insert(avl_root_main, data, &growt);
        break;
      case 8:
        printf("Valor a ser removido: ");
        scanf("%d", &data);
        avl_root_main = avl_remove(avl_root_main, data, &shrunk);;
        break;
      case 9:
        printf("Valor a ser consultado: ");
        scanf("%d", &data);
        avl_root avl_query = avl_search(avl_root_main, data);
        if(avl_query==NULL)
            printf("Valor não existe\n");
        else
        printf("Valor existe, %d\n", avl_query->data);
        printf("\n");
        break;
      case 10:
        avl_pre(avl_root_main);
        printf("Altura: %d\n", avl_height(avl_root_main));
        printf("Qtd: %d\n", avl_qtd(avl_root_main));
        printf("\n");
        break;
      case 11:
        avl_in(avl_root_main);
        printf("altura: %d\n", avl_height(avl_root_main));
        printf("qtd: %d\n", avl_qtd(avl_root_main));
        printf("\n");
        break;
      case 12:
        avl_pos(avl_root_main);
        printf("altura: %d\n", avl_height(avl_root_main));
        printf("qtd: %d\n", avl_qtd(avl_root_main));
        printf("\n");
        break;
      case 13:
        printf("Valor a ser inserido: ");
        scanf("%d", &data);
        avp_insert(&avp_root_main, data);
        break;
      case 14:
        printf("Valor a ser removido: ");
        scanf("%d", &data);
        avp_remove(&avp_root_main, data);
        break;
      case 15:
        printf("Valor a ser consultado: ");
        scanf("%d", &data);
        avp_root avp_query = avp_search(avp_root_main, data);
        if(avp_query==NULL)
            printf("Valor não existe\n");
        else
        printf("Valor existe, %d\n", avp_query->data);
        printf("\n");
        break;
      case 16:
        avp_pre(avp_root_main);
        printf("Altura: %d\n", avp_height(avp_root_main));
        printf("Qtd: %d\n", avp_qtd(avp_root_main));
        printf("\n");
        break;
      case 17:
        avp_in(avp_root_main);
        printf("altura: %d\n", avp_height(avp_root_main));
        printf("qtd: %d\n", avp_qtd(avp_root_main));
        printf("\n");
        break;
      case 18 :
        avp_pos(avp_root_main);
        printf("altura: %d\n", avp_height(avp_root_main));
        printf("qtd: %d\n", avp_qtd(avp_root_main));
        printf("\n");
        break;    
      case 0:
        exit(0);
    }
  }

}
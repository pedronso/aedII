#include <stdlib.h>
#include <stdio.h>
#include "avp.h"

int main(int argc, char **argv){
    avp_root root;
    int input;
    init_avp(&root);

    while (1) {
    printf("1- Inserir elemento\n2- Remover elemento\n3- Consultar elemento\n4- Preorder\n5- Inorder\n6- Posorder\n0- Sair\n");
    scanf("%d", &input);

    switch (input) {
        int data;
        case 1:
            printf("Valor a ser inserido: ");
            scanf("%d", &data);
            avp_insert(&root, data,0);
            break;
        case 2:
            printf("Valor a ser removido: ");
            scanf("%d", &data);
            avp_remove(&root, data);
            break;
        case 3:
            printf("Valor a ser consultado: ");
            scanf("%d", &data);
            avp_root query = avp_search(root, data);
            if(query==NULL)
                printf("Valor não existe\n");
            else
            printf("Valor existe, %d\n", query->data);
            printf("\n");
            break;
        case 4:
            avp_pre(root);
            printf("Altura: %d\n", avp_height(root));
            printf("Qtd: %d\n", avp_qtd(root));
            printf("\n");
            break;
        case 5:
            avp_in(root);
            printf("altura: %d\n", avp_height(root));
            printf("qtd: %d\n", avp_qtd(root));
            printf("\n");
            break;
        case 6:
            avp_pos(root);
            printf("altura: %d\n", avp_height(root));
            printf("qtd: %d\n", avp_qtd(root));
            printf("\n");
            break;
        case 0:
            exit(0);
    }
}
    return 0;
}

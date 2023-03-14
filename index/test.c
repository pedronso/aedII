#include <stdio.h>
#include <stdlib.h>
#include "index.h"

int main(int argc, char ** argv) {
    Table table;
    Movie *movie;
	int option, key;
    float rating;

	if (!init_table(&table)) {
        printf("Erro ao carregar tabela de dados.");
        exit(0);
    }

	while (1) {
        printf("\n1- Inserir elemento\n2- Remover elemento\n3- Consultar na BST\n4- Consultar na AVL\n5- Consultar na AVP\n6- Pre-order (BST)\n7- Pre-order (AVL)\n8- Pre-order (AVP)\n9- Exibir registros em ordem (Code)\n0- Sair\n");
		scanf("%d", &option);
        printf("\n");

		switch (option) {
            int valor;
            case 1:
                insert_movie(&table, input_aux());
                break;
            case 2:
                printf("Codigo do filme: ");
                scanf("%d", &key);
                remove_movie(&table, key);
                break;    
            case 3:
                printf("Codigo do filme: ");
                scanf("%d", &key);
                movie = bst_search_movie(&table, key);
                if (movie != NULL) {
                    printf("\nCode: %d\n", movie->code);
                    printf("Name: %s\n", movie->name);
                    printf("Director: %s\n", movie->director);
                    printf("Year: %d\n", movie->year);
                    printf("Rating: %d\n", movie->rating);
                } else
                    printf("Filme nao encontrado!\n");
                break;
            case 4:
                printf("Nota do filme: ");
                scanf("%d", &key);
                movie = avl_search_movie(&table, key);
                if (movie != NULL) {
                    printf("\nCode: %d\n", movie->code);
                    printf("Name: %s\n", movie->name);
                    printf("Director: %s\n", movie->director);
                    printf("Year: %d\n", movie->year);
                    printf("Rating: %d\n", movie->rating);
                } else
                    printf("Filme nao encontrado!\n");
                break;
            case 5:
                printf("Ano do filme: ");
                scanf("%d", &key);
                movie = avp_search_movie(&table, key);
                if (movie != NULL) {
                    printf("\nCode: %d\n", movie->code);
                    printf("Name: %s\n", movie->name);
                    printf("Director: %s\n", movie->director);
                    printf("Year: %d\n", movie->year);
                    printf("Rating: %d\n", movie->rating);
                } else
                    printf("Filme nao encontrado!\n");
                break;    
            case 6:
                bst_pre(table.bst_index);
                printf("\n");
                break;
            case 7:
                avl_pre(table.avl_index);
                printf("\n");
                break;
            case 8:
                avp_pre(table.avp_index);
                printf("\n");
                break;
            case 9:
                bst_order_search(&table, table.bst_index);
                printf("\n");
                break;
            case 0:
                finish(&table);
                exit(0);
		}
	}

    return 0;
}
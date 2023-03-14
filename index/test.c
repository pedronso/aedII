#include <stdio.h>
#include <stdlib.h>
#include "index.h"

int main(int argc, char ** argv) {
    Table table;
    Movie *movie;
	int option, key;

	if (!init_table(&table)) {
        printf("Erro ao carregar tabela de dados.");
        exit(0);
    }

	while (1) {
        printf("\n1- Inserir elemento\n2- Consultar elemento\n3- Pre-order dos indices\n4- Consultar (AVL)\n5- Pre-order (AVL)\n6-Pre-order (AVP)\n0- Sair\n");
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
                movie = bst_search_movie(&table, key);
                if (movie != NULL) {
                    printf("\nCode: %d\n", movie->code);
                    printf("Title: %s\n", movie->name);
                    printf("Author: %s\n", movie->director);
                    printf("Year: %d\n", movie->year);
                    printf("Rating: %d\n", movie->rating);
                } else
                    printf("Filme nao encontrado!\n");
                break;

            case 3:
                bst_pre(table.bst_index);
                printf("\n");
                break;
            case 4:
                printf("Classificacao do filme: ");
                scanf("%d", &key);
                movie = avl_search_movie(&table, key);
                if (movie != NULL) {
                    printf("\nCode: %d\n", movie->code);
                    printf("Title: %s\n", movie->name);
                    printf("Author: %s\n", movie->director);
                    printf("Year: %d\n", movie->year);
                    printf("Rating: %d\n", movie->rating);
                } else
                    printf("Filme nao encontrado!\n");
                break;    
            case 5:
                avl_pre(table.avl_index);
                printf("\n");
                break;
            case 6:
                avp_pre(table.avp_index);
                printf("\n");
                break;
            case 0:
                finish(&table);
                exit(0);
		}
	}

    return 0;
}
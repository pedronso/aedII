#include <stdio.h>
#include <stdlib.h>
#include "index.h"

int main(int argc, char ** argv) {
    Table table;
    Movie *movie;
	int option, key;
    float rating;
    char *buffer = (char *) malloc(256 * sizeof(char));

	if (!init_table(&table)) {
        printf("Erro ao carregar tabela de dados.");
        exit(0);
    }

	while (1) {
        printf("\n1- Inserir elemento\n2- Remover elemento\n3- Consultar na BST\n4- Consultar na AVL\n5- Consultar na AVP\n6- Pre-order (BST)\n7- Pre-order (AVL)\n8- Pre-order (AVP)\n9- Exibir registros em ordem\n0- Sair\n");
		scanf("%d", &option);
        printf("\n");
        // getchar();
        fflush(stdin);
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
                    printf("\nCodigo: %d\n", movie->code);
                    printf("Nome: %s\n", movie->name);
                    printf("Diretor: %s\n", movie->director);
                    printf("Ano: %d\n", movie->year);
                    printf("Nota: %d\n", movie->rating);
                } else
                    printf("Filme nao encontrado!\n");
                break;
            case 4:
                printf("Nome do filme: ");
                fgets(buffer, 255,  stdin);
                remove_enter(buffer);
                printf("buffer: _%s_\n",buffer);
                movie = avl_search_movie(&table, buffer);
                if (movie != NULL) {
                    printf("\nCodigo: %d\n", movie->code);
                    printf("Nome: %s\n", movie->name);
                    printf("Diretor: %s\n", movie->director);
                    printf("Ano: %d\n", movie->year);
                    printf("Nota: %d\n", movie->rating);
                } else
                    printf("Filme nao encontrado!\n");
                break;
            case 5:
                printf("Ano do filme: ");
                scanf("%d", &key);
                movie = avp_search_movie(&table, key);
                if (movie != NULL) {
                    printf("\nCodigo: %d\n", movie->code);
                    printf("Nome: %s\n", movie->name);
                    printf("Diretor: %s\n", movie->director);
                    printf("Ano: %d\n", movie->year);
                    printf("Nota: %d\n", movie->rating);
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
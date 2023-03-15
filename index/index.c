#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "index.h"

int init_table(Table *table) {
    init_bst(&table->bst_index);	
    init_avl(&table->avl_index);	
    init_avp(&table->avp_index);
	table->data_file = fopen(DATA_PATH, "a+");
	bst_load_file(BST_INDEX_PATH, &table->bst_index);
	avl_load_file(AVL_INDEX_PATH, &table->avl_index);
	avp_load_file(AVP_INDEX_PATH, &table->avp_index);

	if (table->data_file != NULL) {
		return 1;
    } else {
		return 0;
    }
}

void insert_movie(Table *table, Movie *movie) {
    if(table->data_file != NULL) {
        bst_root bst_new = (bst_root) malloc(sizeof(bst_node));
        bst_Index *bst_new_index = (bst_Index *) malloc(sizeof(bst_Index*));
        bst_new_index->key = movie->code;

        avl_root avl_new = (avl_root) malloc(sizeof(avl_node));
        avl_Index *avl_new_index = (avl_Index *) malloc(sizeof(avl_Index*));
        avl_new_index->key = movie->rating;

        int growt = 0;

        avp_Index *avp_new_index = (avp_Index *) malloc(sizeof(avp_Index*));
        avp_new_index->key = movie->year;

        fseek(table->data_file, 0L, SEEK_END);
        avp_new_index->index = avl_new_index->index = bst_new_index->index = ftell(table->data_file);

        
        fprintf(table->data_file, "CODE=%d\n", movie->code);
        fprintf(table->data_file, "NAME=%s\n", movie->name);
        fprintf(table->data_file, "DIRECTOR=%s\n", movie->director);
        fprintf(table->data_file, "YEAR=%d\n", movie->year);
        fprintf(table->data_file, "RATING=%d\n", movie->rating);
        fprintf(table->data_file, "#\n");
        
        printf("Filme armazenado em disco!\n");

        bst_new = bst_insert(table->bst_index, bst_new_index->key, bst_new_index->index);
        avl_new = avl_insert(table->avl_index, avl_new_index->key, avl_new_index->index, &growt);
        avp_insert(&table->avp_index, avp_new_index->key, avp_new_index->index);

        table->bst_index = bst_new;
        table->avl_index = avl_new;
	}
}

void remove_movie(Table * table, int key){
    int shrink = 0;
    Movie * movie = bst_search_movie(table, key);
    // if (movie != NULL) {
    //     printf("\nCode: %d\n", movie->code);
    //     printf("Name: %s\n", movie->name);
    //     printf("Director: %s\n", movie->director);
    //     printf("Year: %d\n", movie->year);
    //     printf("Rating: %d\n", movie->rating);
    // } else
    //     printf("Filme nao encontrado!\n");

    if (movie != NULL) {
        printf("\nFilme encontrado:\n");

        printf("\nCode: %d\n", movie->code);
        printf("Name: %s\n", movie->name);
        printf("Director: %s\n", movie->director);
        printf("Year: %d\n", movie->year);
        printf("Rating: %d\n", movie->rating);
        

        bst_remove(table->bst_index, key);
        avl_remove(table->avl_index, movie->rating, &shrink);
        avp_remove(&table->avp_index, movie->year);
    } else
        printf("\nFilme nao encontrado!\n");
    

}

Movie * bst_search_movie(Table *table, int key) {
    if (table->data_file != NULL) {
        bst_root temp = table->bst_index;
        while (temp != NULL) {
            if (temp->data->key == key) {
                Movie * movie = (Movie *) malloc(sizeof(Movie));
                char *buffer = (char *) malloc(256 * sizeof(char));
                fseek(table->data_file, temp->data->index, SEEK_SET);
                fgets(buffer, 256, table->data_file);
                if (strcmp(buffer, "#\n") != 0) {
                    movie->code = atoi(select_field(buffer));
                    fgets(buffer, 256, table->data_file);
                    movie->name = strdup(select_field(buffer));
                    fgets(buffer, 256, table->data_file);
                    movie->director = strdup(select_field(buffer));
                    fgets(buffer, 256, table->data_file);
                    movie->year = atoi(select_field(buffer));
                    fgets(buffer, 256, table->data_file);
                    movie->rating = atoi(select_field(buffer));
                }
                free(buffer);
                return movie;
            } else {
                if (key >= temp->data->key) {
                    temp = temp->right;
                } else {
                    temp = temp->left;                
                }
            }
        }
    }
    return NULL;
}

Movie * avl_search_movie(Table *table, int key) {
    if (table->data_file != NULL) {
        avl_root temp = table->avl_index;
        while (temp != NULL) {
            if (temp->data->key == key) {
                Movie * movie = (Movie *) malloc(sizeof(Movie));
                char *buffer = (char *) malloc(256 * sizeof(char));
                fseek(table->data_file, temp->data->index, SEEK_SET);
                fgets(buffer, 256, table->data_file);
                if (strcmp(buffer, "#\n") != 0) {
                    movie->code = atoi(select_field(buffer));
                    fgets(buffer, 256, table->data_file);
                    movie->name = strdup(select_field(buffer));
                    fgets(buffer, 256, table->data_file);
                    movie->director = strdup(select_field(buffer));
                    fgets(buffer, 256, table->data_file);
                    movie->year = atoi(select_field(buffer));
                    fgets(buffer, 256, table->data_file);
                    movie->rating = atoi(select_field(buffer));
                }
                free(buffer);
                return movie;
            } else {
                if (key >= temp->data->key) {
                    temp = temp->right;
                } else {
                    temp = temp->left;                
                }
            }
        }
    }
    return NULL;
}

Movie * avp_search_movie(Table *table, int key) {
    if (table->data_file != NULL) {
        avp_root temp = table->avp_index;
        while (temp != NULL) {
            if (temp->data->key == key) {
                Movie * movie = (Movie *) malloc(sizeof(Movie));
                char *buffer = (char *) malloc(256 * sizeof(char));
                fseek(table->data_file, temp->data->index, SEEK_SET);
                fgets(buffer, 256, table->data_file);
                if (strcmp(buffer, "#\n") != 0) {
                    movie->code = atoi(select_field(buffer));
                    fgets(buffer, 256, table->data_file);
                    movie->name = strdup(select_field(buffer));
                    fgets(buffer, 256, table->data_file);
                    movie->director = strdup(select_field(buffer));
                    fgets(buffer, 256, table->data_file);
                    movie->year = atoi(select_field(buffer));
                    fgets(buffer, 256, table->data_file);
                    movie->rating = atoi(select_field(buffer));
                }
                free(buffer);
                return movie;
            } else {
                if (key >= temp->data->key) {
                    temp = temp->right;
                } else {
                    temp = temp->left;                
                }
            }
        }
    }
    return NULL;
}

void bst_order_search(Table * table, bst_root root) {
    if(root != NULL){
        bst_order_search(table, root->left);
        retrieve_data(table,root);
        bst_order_search(table, root->right);
    }
}

void retrieve_data(Table * table, bst_root root){
    Movie * movie = (Movie *) malloc(sizeof(Movie));
    char *buffer = (char *) malloc(256 * sizeof(char));
    fseek(table->data_file, root->data->index, SEEK_SET);
    fgets(buffer, 256, table->data_file);
    if (strcmp(buffer, "#\n") != 0) {
        movie->code = atoi(select_field(buffer));
        fgets(buffer, 256, table->data_file);
        movie->name = strdup(select_field(buffer));
        fgets(buffer, 256, table->data_file);
        movie->director = strdup(select_field(buffer));
        fgets(buffer, 256, table->data_file);
        movie->year = atoi(select_field(buffer));
        fgets(buffer, 256, table->data_file);
        movie->rating = atoi(select_field(buffer));
    }
    free(buffer);
    if (movie != NULL) {
        printf("\nCode: %d\n", movie->code);
        printf("Name: %s\n", movie->name);
        printf("Director: %s\n", movie->director);
        printf("Year: %d\n", movie->year);
        printf("Rating: %d\n", movie->rating);
    } else
        printf("Filme nao encontrado!\n");
}

Movie * input_aux() {
    Movie *new_movie = (Movie *) malloc(sizeof(Movie));
    char *buffer = (char *) malloc(256 * sizeof(char));

	printf("Code: ");
	scanf("%d", &new_movie->code);
    getchar();

	printf("Name: ");
	fgets(buffer, 255,  stdin);
	remove_enter(buffer);
    new_movie->name = strdup(buffer);

	printf("Director: ");
    fgets(buffer, 255,  stdin);
    remove_enter(buffer);
    new_movie->director = strdup(buffer);

	printf("Year: ");
	scanf("%d", &new_movie->year);
    getchar();

    printf("Rating: ");
	scanf("%d", &new_movie->rating);
    getchar();

    free(buffer);

    printf("\n");

	return new_movie;
}

void bst_save_file(char *name, bst_root root) {
    FILE *file;
	file = fopen(name, "wb");
	if (file != NULL) {
		bst_save_tree(root, file);
		fclose(file);
	}
}

void avl_save_file(char *name, avl_root root) {
    FILE *file;
	file = fopen(name, "wb");
	if (file != NULL) {
		avl_save_tree(root, file);
		fclose(file);
	}
}

void avp_save_file(char *name, avp_root root) {
    FILE *file;
	file = fopen(name, "wb");
	if (file != NULL) {
		avp_save_tree(root, file);
		fclose(file);
	}
}

void bst_save_tree(bst_root root, FILE *file) {
    if (root != NULL) {
        fwrite(root->data, sizeof(bst_Index), 1, file);
		bst_save_tree(root->left, file);
		bst_save_tree(root->right, file);
	}
}

void avl_save_tree(avl_root root, FILE *file) {
    if (root != NULL) {
        fwrite(root->data, sizeof(avl_Index), 1, file);
		avl_save_tree(root->left, file);
		avl_save_tree(root->right, file);
	}
}

void avp_save_tree(avp_root root, FILE *file) {
    if (root != NULL) {
        fwrite(root->data, sizeof(avp_Index), 1, file);
		avp_save_tree(root->left, file);
		avp_save_tree(root->right, file);
	}
}

void bst_load_file(char *bst_name, bst_root * bst) {
    FILE *bst_file = fopen(bst_name, "rb");
    bst_root bst_new = (bst_root) malloc(sizeof(bst_node));
	bst_Index *bst_temp;
	if (bst_file != NULL) {
		bst_temp = (bst_Index*) malloc(sizeof(bst_Index));
        printf("\nReconstruindo BST de indices com valores armazenados em disco:\n");
		while(fread(bst_temp, sizeof(bst_Index), 1, bst_file)) {
			bst_new = bst_insert(*bst, bst_temp->key, bst_temp->index);	
            *bst = bst_new;		
			bst_temp = (bst_Index *) malloc(sizeof(bst_Index));
		}
		fclose(bst_file);
	}else
        printf("BST nula.\n");
}

void avl_load_file(char *avl_name, avl_root * avl) {
    FILE *avl_file = fopen(avl_name, "rb");
    avl_root avl_new = (avl_root) malloc(sizeof(avl_node));
	avl_Index *avl_temp;
    int growt = 0;
	if (avl_file != NULL) {
		avl_temp = (avl_Index*) malloc(sizeof(avl_Index));
        printf("\nReconstruindo AVL de indices com valores armazenados em disco:\n");
		while(fread(avl_temp, sizeof(avl_Index), 1, avl_file)) {
			avl_new = avl_insert(*avl, avl_temp->key, avl_temp->index,&growt);	
            *avl = avl_new;		
			avl_temp = (avl_Index *) malloc(sizeof(avl_Index));
		}
		fclose(avl_file);
	}else
        printf("AVL nula\n");
}

void avp_load_file(char *avp_name, avp_root * avp) {
    FILE *avp_file = fopen(avp_name, "rb");
	avp_Index *avp_temp;
    int growt = 0;
	if (avp_file != NULL) {
		avp_temp = (avp_Index*) malloc(sizeof(avp_Index));
        printf("\nReconstruindo AVP de indices com valores armazenados em disco:\n");
		while(fread(avp_temp, sizeof(avp_Index), 1, avp_file)) {
			avp_insert(avp, avp_temp->key, avp_temp->index);	
			avp_temp = (avp_Index *) malloc(sizeof(avp_Index));
		}
		fclose(avp_file);
	}else
        printf("AVP nula\n");
}

void finish(Table *table) {
    fclose(table->data_file);
	bst_save_file(BST_INDEX_PATH, table->bst_index);
	avl_save_file(AVL_INDEX_PATH, table->avl_index);
	avp_save_file(AVP_INDEX_PATH, table->avp_index);
}

char * select_field(char *string) {
    int i = 0, j, k;
    char *value = (char *) malloc(256 * sizeof(char));
    while (string[i] != '=' && string[i] != '\0')
        i++;
    for (j = i + 1, k = 0; j < strlen(string) - 1; j++, k++)
        value[k] = string[j];
    value[k]='\0';
    return value;
}

void remove_enter(char *string) {
    string[strlen(string) -1] = '\0';
}   

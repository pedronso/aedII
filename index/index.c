#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "index.h"

int init_table(Table *table) {
    init_bst(&table->bst_index);	
	table->data_file = fopen(DATA_PATH, "a+");
	load_file(BST_INDEX_PATH, &table->bst_index);
	if (table->data_file != NULL) {
		return 1;
    } else {
		return 0;
    }
}


void insert_movie(Table *table, Movie *movie) {
    if(table->data_file != NULL) {
        bst_root new = (bst_root) malloc(sizeof(bst_node));
        bst_Index *new_index = (bst_Index *) malloc(sizeof(bst_Index*));
        new_index->key = movie->code;

        fseek(table->data_file, 0L, SEEK_END);
        new_index->index = ftell(table->data_file);
        
        fprintf(table->data_file, "CODE=%d\n", movie->code);
        fprintf(table->data_file, "NAME=%s\n", movie->name);
        fprintf(table->data_file, "DIRECTOR=%s\n", movie->director);
        fprintf(table->data_file, "YEAR=%d\n", movie->year);
        fprintf(table->data_file, "RATING=%d\n", movie->rating);
        fprintf(table->data_file, "#\n");

        new = bst_insert(table->bst_index, new_index->key, new_index->index);
        table->bst_index = new;
	}
}

Movie * search_movie(Table *table, int key) {
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
                    fgets(buffer, 355, table->data_file);
                    movie->name = strdup(select_field(buffer));
                    fgets(buffer, 355, table->data_file);
                    movie->director = strdup(select_field(buffer));
                    fgets(buffer, 355, table->data_file);
                    movie->year = atoi(select_field(buffer));
                    fgets(buffer, 355, table->data_file);
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

	return new_movie;
}

void save_file(char *name, bst_root root) {
    FILE *file;
	file = fopen(name, "wb");
	if (file != NULL) {
		save_tree(root, file);
		fclose(file);
	}
}

void save_tree(bst_root root, FILE *file) {
    if (root != NULL) {
        fwrite(root->data, sizeof(bst_Index), 1, file);
		save_tree(root->left, file);
		save_tree(root->right, file);
	}
}

void load_file(char *bst_name, bst_root * bst) {
    FILE *bst_file = fopen(bst_name, "rb");
    bst_root bst_new = (bst_root) malloc(sizeof(bst_node));
	bst_Index *bst_temp;
	if (bst_file != NULL) {
		bst_temp = (bst_Index*) malloc(sizeof(bst_Index));
		while(fread(bst_temp, sizeof(bst_Index), 1, bst_file)) {
			bst_new = bst_insert(*bst, bst_temp->key, bst_temp->index);	
            *bst = bst_new;		
			bst_temp = (bst_Index *) malloc(sizeof(bst_Index));
		}
		fclose(bst_file);
	}else
        printf("bst nula\n");
}

void finish(Table *table) {
    fclose(table->data_file);
	save_file(BST_INDEX_PATH, table->bst_index);
}

char * select_field(char *string) {
    int i = 0, j, k;
    char *value = (char *) malloc(256 * sizeof(char));

    while (string[i] != '=' && string[i] != '\0')
        i++;

    for (j = i + 1, k = 0; j < strlen(string) - 1; j++, k++)
        value[k] = string[j];

    return value;
}

void remove_enter(char *string) {
    string[strlen(string) -1] = '\0';
}   

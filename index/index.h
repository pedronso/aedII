#ifndef INDEX_H
#define INDEX_H

#include <stdio.h>
#include "../bst/bst.h"
#include "../avl/avl.h"
#include "../avp/avp.h"

#define DATA_PATH "data/data.txt"
#define BST_INDEX_PATH "data/bst_index.dat"
#define AVL_INDEX_PATH "data/avl_index.dat"


typedef struct movie {
	int code;
	char *name;
	char *director;
	int year;
	int rating;
} Movie;

typedef struct index {
	int data;
	int index;
} Index;

typedef struct table {
	FILE *data_file;
	bst_root bst_index;
	avl_root avl_index;
} Table;

int init_table(Table *table);
void insert_movie(Table *table, Movie *movie);
Movie * bst_search_movie(Table *table, int key);
Movie * avl_search_movie(Table *table, int key);
Movie * input_aux();

void bst_save_file(char *name, bst_root root);
void avl_save_file(char *name, avl_root root);
void bst_save_tree(bst_root root, FILE *file);
void avl_save_tree(avl_root root, FILE *file);
void bst_load_file(char *name, bst_root *root);
void avl_load_file(char *name, avl_root *root);


void finish(Table *table);
char * select_field(char *string);
void remove_enter(char *string);

#endif

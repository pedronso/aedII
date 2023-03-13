#ifndef INDEX_H
#define INDEX_H

#include <stdio.h>
#include "../bst/bst.h"
#include "../avl/avl.h"
#include "../avp/avp.h"

#define DATA_PATH "data/data.txt"
#define BST_INDEX_PATH "data/bst_index.dat"

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
} Table;

int init_table(Table *table);
void insert_movie(Table *table, Movie *movie);
Movie * search_movie(Table *table, int key);
Movie * input_aux();

void save_file(char *name, bst_root tree);
void save_tree(bst_root root, FILE *file);
void load_file(char *name, bst_root *tree);

void finish(Table *table);
char * select_field(char *string);
void remove_enter(char *string);

#endif

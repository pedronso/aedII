#ifndef INDEX_H
#define INDEX_H

#include <stdio.h>
#include "../bst/bst.h"
#include "../avl/avl.h"
#include "../avp/avp.h"

#define DATA_PATH "data/data3.txt"
#define BST_INDEX_PATH "data/bst_index2.dat"
#define AVL_INDEX_PATH "data/avl_index2.dat"
#define AVP_INDEX_PATH "data/avp_index2.dat"



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
	avp_root avp_index;
} Table;

int init_table(Table *table);
void insert_movie(Table *table, Movie *movie);
void remove_movie(Table *table, int key);
Movie * bst_search_movie(Table *table, int key);
Movie * avl_search_movie(Table *table, char * key);
Movie * avp_search_movie(Table *table, int key);
void bst_order_search(Table *table, bst_root root);
void retrieve_data(Table *table, bst_root root);

Movie * input_aux();

void bst_save_file(char *name, bst_root root);
void avl_save_file(char *name, avl_root root);
void avp_save_file(char *name, avp_root root);
void bst_save_tree(bst_root root, FILE *file);
void avl_save_tree(avl_root root, FILE *file);
void avp_save_tree(avp_root root, FILE *file);
void bst_load_file(char *name, bst_root *root);
void avl_load_file(char *name, avl_root *root);
void avp_load_file(char *name, avp_root *root);

void finish(Table *table);
char * select_field(char *string);
void remove_enter(char *string);

#endif

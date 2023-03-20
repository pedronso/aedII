#ifndef AVL_H
#define AVL_H

typedef struct avl_index {
	char key [25];
	int index;
} avl_Index;

typedef struct avl_node{
  avl_Index *data;
  int bf;
  struct avl_node *left, *right;
}avl_node;

typedef struct avl_node * avl_root;

//init
void init_avl(avl_root *root);

//insert
avl_root avl_insert(avl_root root, char * data, int index, int * grown);

//remove
avl_root avl_remove(avl_root root, char * data, int * shrink);
avl_Index * avl_bigger_left(avl_root root);

//rotation
avl_root rotate(avl_root root);
avl_root avl_left_rotation(avl_root root);
avl_root avl_right_rotation(avl_root root);
avl_root avl_double_left_rotation(avl_root root);
avl_root avl_double_right_rotation(avl_root root);

//free
void avl_free_root(avl_root *root);

//query
avl_root avl_search(avl_root root, char * data);

//avl info
int avl_qtd(avl_root root);
int avl_height(avl_root root);
int avl_max(int a, int b);
int avl_empty(avl_root root);
int avl_balance(avl_root root);

//print
void avl_pre(avl_root root);
void avl_pre_new(avl_root root);
void avl_pos(avl_root root);
void avl_in(avl_root root);

void avl_remove_enter(char *string);


#endif

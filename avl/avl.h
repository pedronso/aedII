#ifndef AVL_H
#define AVL_H

typedef struct avl_node{
  int data,bf;
  struct avl_node *left, *right;
}avl_node;

typedef struct avl_node * avl_root;

//init
void init_avl(avl_root *root);

//insert
avl_root avl_insert(avl_root root, int data, int * grown);

//remove
avl_root avl_remove(avl_root root, int data, int * shrink);
avl_root avl_remove_new(avl_root root, int data);
int bigger_left(avl_root root);

//rotation
avl_root rotate(avl_root root);
avl_root left_rotation(avl_root root);
avl_root right_rotation(avl_root root);
avl_root double_left_rotation(avl_root root);
avl_root double_right_rotation(avl_root root);

//free
void free_root(avl_root *root);

//query
avl_root avl_search(avl_root root, int data);

//avl info
int avl_qtd(avl_root root);
int avl_height(avl_root root);
int max(int a, int b);
int avl_empty(avl_root root);
int avl_balance(avl_root root);

//print
void avl_pre(avl_root root);
void avl_pre_new(avl_root root);
void avl_pos(avl_root root);
void avl_in(avl_root root);

#endif

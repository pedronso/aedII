#ifndef BST_H
#define BST_H

typedef struct bst_index {
	int key;
	int index;
} bst_Index;

typedef struct bst_node{
  bst_Index *data;
  struct bst_node *left, *right;
}bst_node;

typedef struct bst_node * bst_root;

//init
void init_bst(bst_root *root);

//insert
bst_root bst_insert(bst_root root, int data, int index);

//remove
bst_root bst_remove(bst_root root, int data);
int bst_bigger_left(bst_root root);

//free
void bst_free_root(bst_root *root);

//query
bst_root bst_search(bst_root root, int data);

//bst info
int bst_qtd(bst_root root);
int bst_height(bst_root root);
int bst_max(int a, int b);
int bst_empty(bst_root root);

//print
void bst_pre(bst_root root);
void bst_pos(bst_root root);
void bst_in(bst_root root);

#endif

#ifndef BST_H
#define BST_H

typedef struct bst_node{
  int data;
  struct bst_node *left, *right;
}bst_node;

typedef struct bst_node * bst_root;

//init
void init_bst(bst_root *root);

//insert
bst_root bst_insert(bst_root root, int data);

//remove
bst_root bst_remove(bst_root root, int data);
int bigger_left(bst_root root);

//free
void free_root(bst_root *root);

//query
bst_root bst_search(bst_root root, int data);

//bst info
int bst_qtd(bst_root root);
int bst_height(bst_root root);
int max(int a, int b);
int bst_empty(bst_root root);

//print
void bst_pre(bst_root root);
void bst_pos(bst_root root);
void bst_in(bst_root root);

#endif

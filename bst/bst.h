#ifndef BST_H
#define BST_H

typedef struct bst_node
{
  int info;
  struct bst_node *left, *right;
}bst_node;

typedef struct bst_node *bst_root;

//init
void ini_bst(bst_root *root);

//insert
int bst_insert(bst_root *root, int data);

//remove
int bst_remove(bst_root *root, int data);
struct bst_node* bst_remove_this(struct bst_node* this_node);

//free
void free_node(bst_node *node);

//query
int bst_search(bst_root *root, int data);

//bst info
int bst_qtd(bst_root *root);
int bst_height(bst_root *root);
int bst_empty(bst_root *root);

//print
void bst_pre(bst_root root);
void bst_pos(bst_root root);
void bst_in(bst_root root);

#endif

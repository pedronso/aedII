#ifndef AVP_H
#define AVP_H

enum color {RED, BLACK, DBLACK};

typedef struct avp_index {
	int key;
	int index;
} avp_Index;

typedef struct avp_node{
  avp_Index *data;
  struct avp_node *left, *right, *parent;
  enum color color;
}avp_node;

typedef struct avp_node * avp_root;

//init
void init_avp(avp_root *root);

//insert
void avp_insert(avp_root * root, int data, int index);
enum color color(avp_root root);
void fixup_insert(avp_root *root, avp_root new_root);
int is_root(avp_root root);
int is_left(avp_root root);
avp_root brother(avp_root root);
avp_root uncle(avp_root root);

//remove
void avp_remove(avp_root * root, int data);
void fixup_remove(avp_root *root, avp_root dblack);
void remove_double_black(avp_root *root, avp_root node);
avp_Index * avp_bigger_left(avp_root root);

//rotation
void avp_left_rotation(avp_root *root, avp_root pivot);
void avp_right_rotation(avp_root *root, avp_root pivot);
void avp_double_left_rotation(avp_root *root, avp_root pivot);
void avp_double_right_rotation(avp_root *root, avp_root pivot);

//free
void avp_free_root(avp_root *root);

//query
avp_root avp_search(avp_root root, int data);

//avp info
int avp_qtd(avp_root root);
int avp_height(avp_root root);
int avp_max(int a, int b);
int avp_empty(avp_root root);
int avp_balance(avp_root root);

//print
void avp_pre(avp_root root);
void avp_pos(avp_root root);
void avp_in(avp_root root);

#endif

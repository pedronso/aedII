#include <stdio.h>
#include <stdlib.h>
#include "avp.h"

avp_root null_root;

void init_avp(avp_root *root){
  *root = NULL;
  null_root = (avp_root) malloc(sizeof(avp_node));
	null_root->data = 0;
  null_root->left = NULL;
  null_root->right = NULL;
	null_root->color = DBLACK;
}

void avp_insert(avp_root * root, int data){
    avp_root current, parent, new_root;
    current = *root;
    parent = NULL;

    while(current!=NULL){
        parent = current;
        if(data<current->data)
    	    current = current->left;
        else
    	    current = current->right;
    }       

    new_root = (avp_root) malloc(sizeof(avp_node));
    new_root->data = data;
    new_root->left = NULL;
    new_root->right = NULL;
    new_root->parent = parent;
    new_root->color = RED;

    if (is_root(new_root))
        *root = new_root;
    else{
        if(data<parent->data)
            parent->left=new_root;
        else
            parent->right=new_root;
    }
    printf("%d inserido!\n",data);
    fixup_insert(root,new_root);
}

void fixup_insert(avp_root *root, avp_root new_root){
    while(color(new_root) == RED && color(new_root->parent)==RED ){
        if(color(uncle(new_root))==RED){
            uncle(new_root)->color = BLACK;
            new_root->parent->color = BLACK;
            new_root->parent->parent->color = RED;
            new_root = new_root->parent->parent;
            continue;
        }
        if (is_left(new_root) && is_left(new_root->parent)){
            right_rotation(root, new_root->parent->parent);
            new_root->parent->color = BLACK;
            new_root->parent->right->color = RED;
            continue;
        }
        if (is_left(new_root)==0 && is_left(new_root->parent)==0){
            left_rotation(root, new_root->parent->parent);
            new_root->parent->color = BLACK;
            new_root->parent->left->color = RED;
            continue;
        }
        if (is_left(new_root)==0 && is_left(new_root->parent)){
            double_right_rotation(root, new_root->parent->parent);
            new_root->parent->color = BLACK;
            new_root->parent->right->color = RED;
            continue;
        }
        if (is_left(new_root) && is_left(new_root->parent)==0){
            double_left_rotation(root, new_root->parent->parent);
            new_root->parent->color = BLACK;
            new_root->parent->left->color = RED;
            continue;
        }
    }
    (*root)->color = BLACK;
}

int is_root(avp_root root){
    return(root->parent==NULL); 
}

int is_left(avp_root root){
    return(root->parent!=NULL && root==root->parent->left); 
}

avp_root brother(avp_root root){
    if(is_left(root))
        return root->parent->right;
    else
        return root->parent->left;
}   

avp_root uncle(avp_root root){
    return brother(root->parent);
}

enum color color(avp_root root){
    enum color c;
    if(root==NULL)
        c = BLACK;
    else
        c = root->color;
    return c;
}
void avp_remove(avp_root *root, int data)
{
  avp_root temp = *root;

	while (temp != NULL) {
		if (data == temp->data) {
      if (temp->left != NULL && temp->right != NULL) {
    		temp->data = bigger_left(temp->left);
	    	avp_remove(&(temp->left),temp->data);
        printf("%d removido!\n",data);
        break;
      }

			if (temp->left == NULL && temp->right != NULL) {
        avp_root right = temp->right;
        temp->data = right->data;
        temp->right = NULL;
        free(right);
        printf("%d removido!\n",data);
				break;
			}

			if (temp->left != NULL && temp->right == NULL) {
				avp_root left = temp->left;
        temp->data = left->data;
        temp->left = NULL;
        free(left);
        printf("%d removido!\n",data);
        break;
			}

			if (temp->left == NULL && temp->right == NULL) {				
				if (is_root(temp)) {
					*root = NULL;
          free(temp);
          printf("%d removido!\n",data);
					break;
				}

				if (temp->color == RED) {
					if (is_left(temp))
					  temp->parent->left = NULL;
          else
					  temp->parent->right = NULL;
          free(temp);
          printf("%d removido!\n",data);
					break;
				} else {
          null_root->parent = temp->parent;
          if (is_left(temp))
            temp->parent->left = null_root;
          else
            temp->parent->right = null_root;
          free(temp);
          printf("%d removido!\n",data);
          fixup_remove(root, null_root);
          break;
				}
			}
		}else{
      if(data<temp->data)
        temp = temp->left;
      else
          temp = temp->right;
    }	
	}
}

void fixup_remove(avp_root *root, avp_root dblack){

	if(is_root(dblack)) {
    remove_double_black(root, dblack);
		return;
	}

	if(color(dblack->parent) == BLACK && color(brother(dblack)) == RED && color(brother(dblack)->right) == BLACK && color(brother(dblack)->left) == BLACK) {
    if(is_left(dblack))
        left_rotation(root, dblack->parent);
    else
        right_rotation(root, dblack->parent);	
    dblack->parent->parent->color = BLACK;
    dblack->parent->color = RED;
    fixup_remove(root, dblack);
    return;
	}

  if(color(dblack->parent) == BLACK && color(brother(dblack)) == BLACK && color(brother(dblack)->right) == BLACK && color(brother(dblack)->left) == BLACK) {
    avp_root temp = dblack->parent;
    brother(dblack)->color = RED;
    temp->color = DBLACK;
    remove_double_black(root, dblack);
    fixup_remove(root, temp);
    return;
  }	

	if(color(dblack->parent) == RED && color(brother(dblack)) == BLACK && color(brother(dblack)->right) == BLACK && color(brother(dblack)->left) == BLACK) {	
    dblack->parent->color = BLACK;
    brother(dblack)->color = RED;
    remove_double_black(root, dblack);
		return;
	}

	if(color(brother(dblack)) == BLACK && color(brother(dblack)->right) == BLACK && color(brother(dblack)->left) == RED && !is_left(brother(dblack))) {	
    right_rotation(root, brother(dblack));
    brother(dblack)->color = BLACK;
    brother(dblack)->right->color = RED;
    fixup_remove(root, dblack);
		return;
	}

	if(color(brother(dblack)) == BLACK && color(brother(dblack)->right) == RED && color(brother(dblack)->left) == BLACK && is_left(brother(dblack))) {	
    left_rotation(root, brother(dblack));
    brother(dblack)->color = BLACK;
    brother(dblack)->left->color = RED;
    fixup_remove(root, dblack);
    return;
	}

	if(color(brother(dblack)) == BLACK && color(brother(dblack)->right) == RED && !is_left(brother(dblack))) {
    left_rotation(root, dblack->parent);
    enum color temp_color = dblack->parent->parent->color;
    dblack->parent->parent->color = dblack->parent->color;
    dblack->parent->color = temp_color;
    uncle(dblack)->color = BLACK;
    remove_double_black(root, dblack);
		return;
	}

	if(color(brother(dblack)) == BLACK && color(brother(dblack)->left) == RED && is_left(brother(dblack))) {
    right_rotation(root, dblack->parent);
    enum color temp_color = dblack->parent->parent->color;
    dblack->parent->parent->color = dblack->parent->color;
    dblack->parent->color = temp_color;
    uncle(dblack)->color = BLACK;
    remove_double_black(root, dblack);
    return;
	}
}

void remove_double_black(avp_root *root, avp_root node){
  if(node == null_root){
    if(is_root(node))
      *root = NULL;
    else{
      if(is_left(node))
        node->parent->left = NULL;
      else
        node->parent->right = NULL;
    }
  }else
      node->color = BLACK;
}

void left_rotation(avp_root *root, avp_root pivot)
{
    avp_root u, t1;
    u = pivot->right;
    t1 = u->left;

    int position_left_pivot = is_left(pivot);

    pivot->right = t1;
    if (t1!=NULL)
        t1->parent=pivot;

    u->left = pivot;
    u->parent=pivot->parent;
    pivot->parent = u;

    if (is_root(u))
        *root = u;
    else{
        if (position_left_pivot)
            u->parent->left = u;
        else
            u->parent->right = u;
    }
}

void right_rotation(avp_root *root, avp_root pivot)
{
    avp_root u, t1;
    u = pivot->left;
    t1 = u->right;

    int position_left_pivot = is_left(pivot);

    pivot->left = t1;
    if (t1!=NULL)
        t1->parent=pivot;

    u->right = pivot;
    u->parent=pivot->parent;
    pivot->parent = u;

    if (is_root(u))
        *root = u;
    else{
        if (position_left_pivot)
            u->parent->left = u;
        else
            u->parent->right = u;
    }
}

void double_left_rotation(avp_root *root, avp_root pivot)
{
    avp_root u = pivot->right;
    right_rotation(root, u);
    left_rotation(root, pivot);
}

void double_right_rotation(avp_root *root, avp_root pivot)
{
    avp_root u = pivot->left;
    left_rotation(root, u);
    right_rotation(root, pivot);
}

int bigger_left(avp_root root)
{
  if (root->right == NULL)
    return root->data;
  else
    return bigger_left(root->right);
}

void free_root(avp_root *root)
{
  if (*root != NULL)
  {
    free_root(&(*root)->left);
    free_root(&(*root)->right);
    free(*root);
    *root = NULL;
  }
  else
  {
    return;
  }
}

avp_root avp_search(avp_root root, int data)
{
  if (root == NULL || data == root->data)
    return root;
  if (data < root->data)
    return avp_search(root->left, data);
  else
    return avp_search(root->right, data);
}

int avp_qtd(avp_root root)
{
  if (root == NULL)
    return 0;
  int qtd_left = avp_qtd(root->left);
  int qtd_right = avp_qtd(root->right);
  return (1 + qtd_left + qtd_right);
}

int avp_height(avp_root root)
{
  if (root == NULL)
    return 0;
  return 1 + max(avp_height(root->right), avp_height(root->left));
}

int avp_balance(avp_root root)
{
  return avp_height(root->right) - avp_height(root->left);
}

int max(int a, int b)
{
  if (a > b)
    return a;
  else
    return b;
}

int avp_empty(avp_root root)
{
  return (root == NULL);
}

// void avp_pre(avp_root root)
// {
//   if (root != NULL)
//   {
//     printf("%d, fb:%d\n", root->data, root->bf);
//     avp_pre(root->left);
//     avp_pre(root->right);
//   }
// }

void avp_pre(avp_root root)
{
  if (root != NULL)
  {
    int l = 0, r = 0;
    if (root->left != NULL)
    {
      l = root->left->data;
    }
    if (root->right != NULL)
    {
      r = root->right->data;
    }

    printf("%d, color:%d, left:%d, right:%d\n", root->data, root->color, l, r);
    avp_pre(root->left);
    avp_pre(root->right);
  }
}

void avp_pos(avp_root root)
{
  if (root != NULL)
  {
    int l = 0, r = 0;
    if (root->left != NULL)
    {
      l = root->left->data;
    }
    if (root->right != NULL)
    {
      r = root->right->data;
    }

    avp_pos(root->left);
    avp_pos(root->right);
    printf("%d, color:%d, left:%d, right:%d\n", root->data, root->color, l, r);
  }
}

void avp_in(avp_root root)
{
  if (root != NULL)
  {
    int l = 0, r = 0;
    if (root->left != NULL)
    {
      l = root->left->data;
    }
    if (root->right != NULL)
    {
      r = root->right->data;
    }
    avp_in(root->left);
    printf("%d, color:%d, left:%d, right:%d\n", root->data, root->color, l, r);
    avp_in(root->right);
  }
}
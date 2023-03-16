#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void init_bst(bst_root *root){
  *root = NULL;
}

bst_root bst_insert(bst_root root, int data, int index){
  if(root == NULL){
    bst_root new = (bst_root) malloc(sizeof(bst_node));
    bst_Index* new_Index = (bst_Index*) malloc(sizeof(bst_Index*));

    new->data = new_Index;
		new->data->key = data;
		new->data->index = index;

		new->left = NULL;
		new->right = NULL;
    printf("%d inserido na BST!\n",data);
		return new;
  }else{
    if(data < root->data->key) {
      root->left = bst_insert(root->left, data, index);
    }else {
      root->right = bst_insert(root->right, data, index);
    }
    return root;
  } 
}

bst_root bst_remove(bst_root root, int data){
  if(root==NULL)
    return NULL;
  if(root->data->key==data){
    if(root->left==NULL){
      bst_root temp = root->right;
      free(root);
      printf("%d removido da BST!\n",data);
      return temp;  
    }
    if(root->right==NULL){
      bst_root temp = root->left;
      free(root);
      printf("%d removido da BST!\n",data);
      return temp;  
    }
    root->data->key=bst_bigger_left(root->left);
    root->left=bst_remove(root->left,root->data->key);
    return root;
  }
  if (data<root->data->key)
    root->left=bst_remove(root->left, data);
  else
    root->right=bst_remove(root->right, data);
  
  return root;
  
}

int bst_bigger_left(bst_root root) {
	if(root->right == NULL)
			return root->data->key;
	else
			return bst_bigger_left(root->right);
}

void bst_free_root(bst_root *root){
  if(*root != NULL){
    bst_free_root(&(*root)->left);
    bst_free_root(&(*root)->right);
    free(*root);
    *root = NULL;
  }else{
    return;
  }
}

bst_root bst_search(bst_root root, int data){
  if(root == NULL||data == root->data->key)
    return root;
  if(data < root->data->key)
    return bst_search(root->left,data);
  else
    return bst_search(root->right,data);
}

int bst_qtd(bst_root root){
  if (root == NULL)
    return 0;
  int qtd_left = bst_qtd(root->left);
  int qtd_right = bst_qtd(root->right);
  return (1+qtd_left+qtd_right);
}

int bst_height(bst_root root) {
	if(root == NULL)
		return 0;
	return 1 + bst_max(bst_height(root->right), bst_height(root->left));
}

int bst_max(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}

int bst_empty(bst_root root){
  return(root == NULL);
}

void bst_pre(bst_root root){
  if(root != NULL){
    printf("data : %d\n", root->data->key);
    bst_pre(root->left);
    bst_pre(root->right);
  }
}

void bst_pos(bst_root root){
  if(root != NULL){
    bst_pos(root->left);
    bst_pos(root->right);
    printf("%d\n", root->data->key);
  }
}

void bst_in(bst_root root){
  if(root != NULL){
    bst_in(root->left);
    printf("%d\n", root->data->key);
    bst_in(root->right);
  }
}

#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void init_avl(avl_root *root){
  *root = NULL;
}

avl_root avl_insert(avl_root root, int data){
  if(root == NULL){
    avl_root new = (avl_root) malloc(sizeof(avl_node));
		new->data = data;
		new->left = NULL;
		new->right = NULL;
		return new;
  }else{
    if(data < root->data) {
      root->left = avl_insert(root->left, data);
    }else {
      root->right = avl_insert(root->right, data);
    }
    return root;
  } 
}

avl_root avl_remove(avl_root root, int data){
  if(root==NULL)
    return NULL;
  if(root->data==data){
    if(root->left==NULL){
      avl_root temp = root->right;
      free(root);
      return temp;  
    }
    if(root->right==NULL){
      avl_root temp = root->left;
      free(root);
      return temp;  
    }
    root->data=bigger_left(root->left);
    root->left=avl_remove(root->left,root->data);
    return root;
  }
  if (data<root->data)
    root->left=avl_remove(root->left, data);
  else
    root->right=avl_remove(root->right, data);
  
  return root;
  
}

int bigger_left(avl_root root) {
	if(root->right == NULL)
			return root->data;
	else
			return bigger_left(root->right);
}

void free_root(avl_root *root){
  if(*root != NULL){
    free_root(&(*root)->left);
    free_root(&(*root)->right);
    free(*root);
    *root = NULL;
  }else{
    return;
  }
}

avl_root avl_search(avl_root root, int data){
  if(root == NULL||data == root->data)
    return root;
  if(data < root->data)
    return avl_search(root->left,data);
  else
    return avl_search(root->right,data);
}

int avl_qtd(avl_root root){
  if (root == NULL)
    return 0;
  int qtd_left = avl_qtd(root->left);
  int qtd_right = avl_qtd(root->right);
  return (1+qtd_left+qtd_right);
}

int avl_height(avl_root root) {
	if(root == NULL)
		return 0;
	return 1 + max(avl_height(root->right), avl_height(root->left));
}

int max(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}

int avl_empty(avl_root root){
  return(root == NULL);
}

void avl_pre(avl_root root){
  if(root != NULL){
    printf("%d\n", root->data);
    avl_pre(root->left);
    avl_pre(root->right);
  }
}

void avl_pos(avl_root root){
  if(root != NULL){
    avl_pos(root->left);
    avl_pos(root->right);
    printf("%d\n", root->data);
  }
}

void avl_in(avl_root root){
  if(root != NULL){
    avl_in(root->left);
    printf("%d\n", root->data);
    avl_in(root->right);
  }
}
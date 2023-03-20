#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

void init_avl(avl_root *root){
  *root = NULL;
}

avl_root avl_insert(avl_root root, char * data, int index, int *grown){
  if (root == NULL){
    avl_root new = (avl_root)malloc(sizeof(avl_node));
    avl_Index* new_Index = (avl_Index*) malloc(sizeof(avl_Index));
    new->data = new_Index;
    strcpy(new->data->key, data);
    new->data->index = index;
    new->left = NULL;
    new->right = NULL;
    new->bf = 0;
    *grown = 1;
    printf("\n%s inserido na AVL!\n",data);
    return new;
  }
  else{
    if (strcmp(data, root->data->key)<0){
      root->left = avl_insert(root->left, data, index, grown);
      if (*grown){
        switch (root->bf){
        case 0:
          root->bf = -1;
          *grown = 1;
          break;
        case 1:
          root->bf = 0;
          *grown = 0;
          break;
        case -1:
          *grown = 0;
          return rotate(root);
        }
      }
    }else{
      root->right = avl_insert(root->right, data, index, grown);
      if (*grown){
        switch (root->bf){
        case 0:
          root->bf = 1;
          *grown = 1;
          break;
        case -1:
          root->bf = 0;
          *grown = 0;
          break;
        case 1:
          *grown = 0;
          return rotate(root);
          break;
        }
      }
    }
    return root;
  }
}

avl_root avl_remove(avl_root root, char * data, int *shrink)
{
  if (root == NULL)
    return NULL;
  if (strcmp(data, root->data->key)==0)
  {
    if (root->left == NULL)
    {
      avl_root temp = root->right;
      free(root);
      *shrink = 1;
      printf("\n%s removido da AVL!\n",data);
      return temp;
    }
    if (root->right == NULL)
    {
      avl_root temp = root->left;
      free(root);
      *shrink = 1;
      printf("\n%s removido da AVL!\n",data);
      return temp;
    }
    root->data =  avl_bigger_left(root->left);
    root->left = avl_remove(root->left, root->data->key, shrink);
    *shrink = 1;

    if (*shrink)
    {
      switch (root->bf)
      {
      case 0:
        root->bf = +1;
        *shrink = 0;
        break;
      case -1:
        root->bf = 0;
        *shrink = 1;
        break;
      case 1:
        *shrink = 0;
        return rotate(root);
      }
    }

    return root;
  }
  if (strcmp(data, root->data->key)<0)
  {
    root->left = avl_remove(root->left, data, shrink);
    if (*shrink)
    {
      switch (root->bf)
      {
      case 0:
        root->bf = +1;
        *shrink = 0;
        break;
      case -1:
        root->bf = 0;
        *shrink = 1;
        break;
      case 1:
        *shrink = 0;
        return rotate(root);
      }
    }
  }
  else
  {
    root->right = avl_remove(root->right, data, shrink);
    if (*shrink)
    {
      switch (root->bf)
      {
      case 0:
        root->bf = -1;
        *shrink = 0;
        break;
      case 1:
        root->bf = 0;
        *shrink = 1;
        break;
      case -1:
        *shrink = 0;
        return rotate(root);
      }
    }
  }
  return root;
}

avl_root rotate(avl_root root)
{
  if (root->bf > 0)
  {
    switch (root->right->bf)
    {
    case 0:
      break;
    case 1:
      return avl_left_rotation(root);
      break;
    case -1:
      return avl_double_left_rotation(root);
    }
  }
  else
  {
    switch (root->left->bf)
    {
    case 0:
      return avl_right_rotation(root);
      break;
    case -1:
      return avl_right_rotation(root);
      break;
    case 1:
      return avl_double_right_rotation(root);
    }
  }
  return root;
}

avl_root avl_left_rotation(avl_root root)
{
  avl_root temp = root;

  root = root->right;
  temp->right = root->left;
  root->left = temp;

  if(root->bf==1){
    temp->bf=0;
    root->bf=0;

  }else{
    temp->bf=1;
    root->bf=-1;
  }

  return root;
}

avl_root avl_right_rotation(avl_root root)
{
  avl_root temp = root;

  root = root->left;
  temp->left = root->right;
  root->right = temp;

  if(root->bf==-1){
      temp->bf=0;
      root->bf=0;
    }else{
      temp->bf=1;
      root->bf=-1;
    }

  return root;
}

avl_root avl_double_left_rotation(avl_root root)
{
  avl_root p = root, u, v, t1, t2, t3, t4;

  u = p->right;
  v = u->left;
  t1 = p->left;
  t2 = v->left;
  t3 = v->right;
  t4 = u->right;

  p->right = v;
  v->right = u;
  u->left = t3;

  v->left = p;
  p->right = t2;

  if (v->bf == -1) {
      p->bf = 0;
      u->bf = 1;
      v->bf = 0;
  } else if (v->bf == 0) {
      p->bf = 0;
      u->bf = 0;
      v->bf = 0;
  } else if (v->bf == 1) {
      p->bf = -1;
      u->bf = 0;
      v->bf = 0;
  }

  return v;
}

avl_root avl_double_right_rotation(avl_root root)
{
  avl_root p = root, u, v, t1, t2, t3, t4;

  u = p->left;
  v = u->right;
  t1 = u->left;
  t2 = v->left;
  t3 = v->right;
  t4 = p->right;

  p->left = v;
  v->left = u;
  u->right = t2;

  v->right = p;
  p->left = t3;

  if (v->bf == -1) {
      p->bf = 1;
      u->bf = 0;
      v->bf = 0;
  } else if (v->bf == 0) {
      p->bf = 0;
      u->bf = 0;
      v->bf = 0;
  } else if (v->bf == 1) {
      p->bf = 0;
      u->bf = -1;
      v->bf = 0;
  }

  return v;
}

avl_Index * avl_bigger_left(avl_root root)
{
  if (root->right == NULL)
    return root->data;
  else
    return avl_bigger_left(root->right);
}

void avl_free_root(avl_root *root)
{
  if (*root != NULL)
  {
    avl_free_root(&(*root)->left);
    avl_free_root(&(*root)->right);
    free(*root);
    *root = NULL;
  }
  else
    return;
}

avl_root avl_search(avl_root root, char * data)
{
  if (root == NULL || strcmp(data, root->data->key)==0)
    return root;
  if (strcmp(data, root->data->key)<0)
    return avl_search(root->left, data);
  else
    return avl_search(root->right, data);
}

int avl_qtd(avl_root root)
{
  if (root == NULL)
    return 0;
  int qtd_left = avl_qtd(root->left);
  int qtd_right = avl_qtd(root->right);
  return (1 + qtd_left + qtd_right);
}

int avl_height(avl_root root)
{
  if (root == NULL)
    return 0;
  return 1 + avl_max(avl_height(root->right), avl_height(root->left));
}

int avl_balance(avl_root root)
{
  return avl_height(root->right) - avl_height(root->left);
}

int avl_max(int a, int b)
{
  if (a > b)
    return a;
  else
    return b;
}

int avl_empty(avl_root root)
{
  return (root == NULL);
}

void avl_pre(avl_root root)
{
  if (root != NULL)
  {
    char *buffer_left = (char *) malloc(256 * sizeof(char));
    char *buffer_right = (char *) malloc(256 * sizeof(char));
    strcpy(buffer_left,"null");
    strcpy(buffer_right,"null");
    if (root->left != NULL)
      strcpy(buffer_left,root->left->data->key);
    if (root->right != NULL)
      strcpy(buffer_right,root->right->data->key);

    printf("data:%s, index:%d, bf:%d, left:%s, right:%s\n", root->data->key, root->data->index, root->bf, buffer_left, buffer_right);
    avl_pre(root->left);
    avl_pre(root->right);
  }
}

void avl_pos(avl_root root)
{
  if (root != NULL)
  {
    char *buffer_left = (char *) malloc(256 * sizeof(char));
    char *buffer_right = (char *) malloc(256 * sizeof(char));
    strcpy(buffer_left,"null");
    strcpy(buffer_right,"null");
    if (root->left != NULL)
      strcpy(buffer_left,root->left->data->key);
    if (root->right != NULL)
      strcpy(buffer_left,root->right->data->key);

    avl_pre(root->left);
    avl_pre(root->right);
    printf("data:%s, index:%d, bf:%d, left:%s, right:%s\n", root->data->key, root->data->index, root->bf, buffer_left, buffer_right);


  }
}

void avl_in(avl_root root)
{
  if (root != NULL)
  {
    char *buffer_left = (char *) malloc(256 * sizeof(char));
    char *buffer_right = (char *) malloc(256 * sizeof(char));
    strcpy(buffer_left,"null");
    strcpy(buffer_right,"null");
    if (root->left != NULL)
      strcpy(buffer_left,root->left->data->key);
    if (root->right != NULL)
      strcpy(buffer_left,root->right->data->key);

    avl_pre(root->left);
    printf("data:%s, index:%d, bf:%d, left:%s, right:%s\n", root->data->key, root->data->index, root->bf, buffer_left, buffer_right);
    avl_pre(root->right);
  }
}

void avl_remove_enter(char *string) {
    string[strlen(string) -1] = '\0';
}   

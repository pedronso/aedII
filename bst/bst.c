#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

//funcoes da arvore

void init_bst(bst_root *root){
    *root = NULL;
}
/*
void free_node(bst_node *node)
{
  if(node == NULL)
  {
    return;
  }
  free_node(node->left);
  free_node(node->right);
  free(node);
  node = NULL;
}

int estaVazia_bst_root(bst_root *root)
{
  if(root == NULL) //root = endereco
  {
    return 1;
  }
  if(*root == NULL) //*root = condeudo do endereco/endereco que aponta para o primeiro no
  {
    return 1;
  }
  return 0;
}

int altura_bst_root(bst_root *root)
{
  if (root == NULL)
  {
    //a arvore nao foi declarada ou sua declaracao deu pau
    return 0;
  }

  if(*root == NULL)
  {
    //a arvore foi declarada mas ainda nao foi adicionado nenhum no
    return 0;
  }

  int alt_esq = altura_bst_root(&((*root)->esq));
  int alt_dir = altura_bst_root(&((*root)->dir));

  if(alt_esq > alt_dir)
  {
    return (alt_esq + 1);
  }else{
    return (alt_dir + 1);
  }
}

int totalNo_bst_root(bst_root *root)
{
  if (root == NULL)
  {
    return 0;
  }
  if(*root == NULL)
  {
    return 0;
  }
  int alt_esq = totalNo_bst_root(&((*root)->esq));
  int alt_dir = totalNo_bst_root(&((*root)->dir));
  return (alt_esq + alt_dir + 1);
}*/

void bst_pre(bst_root root){
  if(root != NULL){
    printf("%d\n", root->data);
    bst_pre(root->left);
    bst_pre(root->right);
  }
}

void bst_pos(bst_root root){
  if(root != NULL){
    bst_pos(root->left);
    bst_pos(root->right);
    printf("%d\n", root->data);
  }
}

void bst_in(bst_root root){
  if(root != NULL){
    bst_in(root->left);
    printf("%d\n", root->data);
    bst_in(root->right);
  }
}

bst_root bst_insert(bst_root root, int data){
  if(root == NULL)
  {
    bst_root new = (bst_root) malloc(sizeof(bst_node));
		new->data = data;
		new->left = NULL;
		new->right = NULL;
		return new;
  }
 if(data > root->data) {
		root->right = bst_insert(root->right, data);
	} else {
		root->left = bst_insert(root->left, data);
	}
	return root;
}

// struct bst_node* remove_atual(struct bst_node* atual)
// {
//   //Responsavel por tratar os 3 tipos de remocao

//   //no sem filho da esquerda(nao tem nenhum valor menor)
//   //substitui pelo primeiro filho da direita
//   struct bst_node *no1, *no2;
//   if(atual->esq == NULL)
//   {
//     no2 = atual->dir;
//     free(atual);
//     return no2;
//   }
//   //tem dois filhos
//   //procura no mais a direita da subarvore a esquerda
//   no1 = atual;
//   no2 = atual->esq;
//   while(no2->dir != NULL)
//   {
//     no1 = no2;
//     no2 = no2->dir;
//   }

//   //copia o filho mais a direita na sub arvore esquerda p o no removido
//   if(no1 != atual)
//   {
//     no1->dir = no2->esq;
//     no2->esq = atual->esq;
//   }

//   no2->dir = atual->dir;
//   free(atual);
//   return no2;
// }

// int remove_bst_root(bst_root *root, int valor)
// {
//   //Busca do nó a ser removido
//   if(root == NULL) return 0;
//   struct bst_node* ant = NULL;
//   struct bst_node* atual = *root;
//   while(atual != NULL)
//   {
//     if(valor == atual->info)
//     {
//       if(atual == *root)
//       {
//         *root = remove_atual(atual);
//       }else{
//         //remove o no que o ant vai apontar, agora e null
//         if(ant->dir == atual)
//         {
//           ant->dir = remove_atual(atual);
//         }else{
//           ant->esq = remove_atual(atual);
//         }
//       }
//       return 1;
//     }
//     ant = atual;
//     if(valor > atual->info)
//     {
//       atual = atual->dir;
//     }else{
//       atual = atual->esq;
//     }
//   }
// }

// int consulta_bst_root(bst_root *root, int valor)
// {
//   if(root == NULL || *root == NULL) return 0;
//   struct bst_node* atual = *root;

//   while(atual != NULL)
//   {
//     if(valor == atual->info)
//     {
//       return 1;
//     }
//     if(valor > atual->info)
//     {
//       atual = atual->dir;
//     }else{
//       atual = atual->esq;
//     }
//   }
//   return 0;
// }

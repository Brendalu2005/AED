#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int key;
    struct Tree *left;
    struct Tree *right;
}Tree;

void add(Tree **root, int num);
int retornaAltura(Tree *root);

// RETORNA ALTURA //

int main(){
    Tree *root = NULL;
    int arr[7] = {5, 6, 2, 4, 7, 8, 3};

    for(int i = 0; i < 7; i++){
        add(&root, arr[i]);
    }

    printf("altura: %d", retornaAltura(root));

}

void add(Tree **root, int num){
    if(*root == NULL){
        *root = (Tree*)malloc(sizeof(Tree));
        (*root)->key = num;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }else{
        if((*root)->key > num){
            add(&(*root)->left, num);

        }else if((*root)->key < num){
            add(&(*root)->right, num);
        }
    }
}

int retornaAltura(Tree *root){ 
    if(root != NULL){
        int alturaDireita = retornaAltura(root->right);
        int alturaEsquerda = retornaAltura(root->left);

        if(alturaEsquerda > alturaDireita){
            return alturaEsquerda + 1;
        }else{
            return alturaDireita + 1;
        }
    }
    return -1;
    //return 0; conta com a raíz
}

// retornaAltura(3)

// Esquerda = 0, Direita = 0 → retorna 0+1 = 1

// retornaAltura(4)

// Esquerda = 1 (do 3), Direita = 0 → alturaEsquerda > alturaDireita → retorna 1 + 1 = 2

// retornaAltura(2)

// Esquerda = 0, Direita = 2 (do 4) → alturaEsquerda < alturaDireita → retorna 2 + 1 = 3
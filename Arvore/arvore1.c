#include <stdio.h>
#include <stdlib.h>

typedef struct Arv{
    int key;
    struct Arv *left;
    struct Arv *right;
}Arv;

int main(){

}

void add(Arv **root, int num){
    if(*root == NULL){
        *root = (Arv*)malloc(sizeof(Arv));
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


void imprimirPre(Arv *root){
    if(root != NULL){
        printf("%d ", root->right);
        imprimirPre(root->left);
        imprimirPre(root->right);
    }
}

void imprimirIn(Arv *root){
    if(root != NULL){
        imprimirIn(root->left);
        printf("%d ", root->left);
        imprimirIn(root->right);
    }
}

void imprimirPos(Arv *root){
    if(root != NULL){
        imprimirPos(root->left);
        imprimirPos(root->right);
        printf("%d ", root->left);
    }
}


int busca(Arv *root, int num){
    if(root == NULL){
        return;
        
    }else if (root->key == num){
        return 1;

    }else if(root->key > num){
        return buscar(root->left, num);

    }else if(root->key < num){
        return buscar(root->right, num);

    }
}
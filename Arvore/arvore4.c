#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int key;
    struct Tree *left;
    struct Tree *right;
}Tree;

void add(Tree **root, int num);
void retornaFolhas(Tree *root);

// RETORNA FOLHAS//

int main(){
    Tree *root = NULL;
    int arr[7] = {5, 6, 2, 4, 7, 8, 3};

    for(int i = 0; i < 7; i++){
        add(&root, arr[i]);
    }

    retornaFolhas(root);

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

void retornaFolhas(Tree *root){ 
    if(root != NULL){
        if(root->right == NULL && root->left == NULL){
            printf("%d ", root->key);
            return;

        }
        retornaFolhas(root->left);
        retornaFolhas(root->right);
        // faz verificação com as raizes direita e esquerda
    }
}

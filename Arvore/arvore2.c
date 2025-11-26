#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int key;
    struct Tree *left;
    struct Tree *right;
}Tree;

void add(Tree **root, int num);
int retornaNo(Tree *root);

// RETORNA RAIZ DE MAIOR CHAVE //

int main(){
    Tree *root = NULL;
    int arr[7] = {5, 6, 2, 4, 7, 8, 3};

    for(int i = 0; i < 7; i++){
        add(&root, arr[i]);
    }

    printf("raiz maior: %d", retornaNo(root));

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

int retornaNo(Tree *root){ // maior valor é somente a direita
    if(root != NULL){
        if(root->right == NULL){
            return root->key;

        }else{
            return retornaNo(root->right);

        }
    }
    return -1;
}

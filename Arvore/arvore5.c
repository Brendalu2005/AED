#include <stdio.h>
#include <stdlib.h>

typedef struct Arv{
    int key;
    struct Arv *right;
    struct Arv *left;
}Arv;

int main(){

}

void inserir(Arv **t, int n) {
  if (*t == NULL) {
    *t = (Arv *)malloc(sizeof(Arv));
    (*t)->left = NULL;
    (*t)->right = NULL;
    (*t)->key = n;
  } else if (n < (*t)->key)
    inserir(&(*t)->left, n);
  else if (n > (*t)->key)
    inserir(&(*t)->right, n);

  balanco(t);
}


void balanco(Arv **p) {
  if(*p != NULL){
    Arv *aux;
    int fb = filhosAlt((*p)->right) - filhosAlt((*p)->left);

    if (fb <= -2) {
      aux = (*p)->left;
      fb = filhosAlt(aux->right) - filhosAlt(aux->left);

      if (fb > 0) {
        roda_left(&((*p)->left));
        roda_right(p);
        printf("\nRotação: Dupla direita");
      } else {
        roda_right(p);
        printf("\nRotação: direita Simples");
      }
    } else if (fb >= 2) {
      aux = (*p)->right;
      fb = filhosAlt(aux->right) - filhosAlt(aux->left);

      if (fb < 0) {
        roda_right(&((*p)->right));
        roda_left(p);
        printf("\nRotação: Dupla esquerda");
      } else {
        roda_left(p);
        printf("\nRotação: esquerda Simples");
      }
    }
  }
}

int doisFilhos(Arv *root){
    if(root == NULL){
        return 1;
    }else{
        if(root->left == NULL && root->right == NULL){
            return 1;
        }else{
            int esquerdo = doisFilhos(root->left);
            if (esquerdo == 0){
                return 0;
            }

            int direito = doisFilhos(root->right);
            if(direito == 0){
                return 0;
            }

            return 1;
        }
    }
}


// ou

// int doisFilhos(Arv *root){
//     if(root == NULL){
//         return 1;
//     }else{
//         if(root->left == NULL || root->left == NULL){
//             return 1;
//         }

//         if(root->left == 0 || root->right == 0){
//             return 0;
//         }

//         return doisFilhos(root->left) && doisFilhos(root->right);
//     }
// }
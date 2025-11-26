#include <stdio.h>
#include <stdlib.h>

int main(){

}

int filhosAlt(Arv *r) {
  if (r == NULL)
    return 0;
  else {
    int ae = filhosAlt(r->esq); 
    int ad = filhosAlt(r->dir);
    return 1 + (ae > ad ? ae : ad); //retorna a soma do nó atual, com o filho esquerdo, ou direito
    // se ae ou ad não tiverem filhos, o valor retorna 0, e incrementa com 1 (da altura atual, nó de nivel 1)
    // se tiver filhos, incrementa 1 + altura do filho

  }
}

void roda_dir(Arv **p) {
  Arv *aux = (*p)->esq; // passa o filho esquerdo da raiz p
  (*p)->esq = aux->dir; // filho esquerdo passa a ser o filho direito da raiz esquerda
  aux->dir = (*p); // o filho direito recebe a raiz
  *p = aux; // a raiz passa a ser o filho esquerdo
}

void roda_esq(Arv **p) {
  Arv *aux = (*p)->dir; // passa o filho direito para o auxiliar
  (*p)->dir = aux->esq; // o filho direito passa a ser o filho esquerdo
  aux->esq = (*p); // o filho esquerdo passa a ser a raiz
  *p = aux; // a raiz passa a ser o filho esquerdo
}

void balanco(Arv **p) {
  if(*p != NULL){
    Arv *aux;
    int fb = filhosAlt((*p)->dir) - filhosAlt((*p)->esq); 
    //guarda o fator de balanceamneto: fb = hd - he

    if (fb <= -2) { // se estiver desbalanceada
      aux = (*p)->esq;
      fb = filhosAlt(aux->dir) - filhosAlt(aux->esq);
      //calcula o balanceamento do filho esquerdo

      if (fb > 0) { 
        roda_esq(&((*p)->esq)); //corrige o filho esquerdo primeiro
        roda_dir(p); // corrige o nó atual
        printf("\nRotação: Dupla Direita");
      } else {
        roda_dir(p);
        printf("\nRotação: Direita Simples");
      }
    } else if (fb >= 2) { // desbalanceada
      aux = (*p)->dir;
      fb = filhosAlt(aux->dir) - filhosAlt(aux->esq);

      if (fb < 0) {
        roda_dir(&((*p)->dir));
        roda_esq(p);
        printf("\nRotação: Dupla Esquerda");
      } else {
        roda_esq(p);
        printf("\nRotação: Esquerda Simples");
      }
    }
  }
}
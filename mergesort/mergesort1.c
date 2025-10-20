#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 6

int main(){

}

void mergesort (int inicio, int fim, int v[]) {
    if (inicio < fim) { // so divide se tiver mais de um elemento
        int meio = (inicio + fim)/2; // divide a lista em dois
        mergesort (inicio, meio, v); // ordena a parte esquerda do vetor
        mergesort (meio+1, fim, v);// ordena a parte direita
        //+1 se não o indice do meio seria usado 2 vezes
        intercala (inicio, meio, fim, v); // função que faz a junção em ordem

    }
}


void intercala (int inicio, int meio, int fim, int v[]) {
    int inicio_v01 = inicio;// indice do começo da metade esquerda
    int inicio_v02 = meio+1;// indice do começo da metade direita
    int poslivre = 0; // posicao livre do vetor auxiliar
    int aux[TAMANHO];

    while (inicio_v01 <= meio && inicio_v02 <= fim) { // enquanto tiver elementos nas duas metades
        if (v[inicio_v01] <= v[inicio_v02]){ // verifica se um elemento da direita é maior que o da esquerda
            aux[poslivre++] = v[inicio_v01++];
            // adiciona o elemento na posição inicial e depois incrementa

        }else{
            aux[poslivre++] = v[inicio_v02++];

        }
    }    
 
    // quando uma das metades acabar, o primeiro while para
    //essas proximas verificações são caso ainda teha um lado com elementos para serem inseridos
    //se existirem núm. em v[inicio_v01] que não foram intercalados
    while (inicio_v01 <= meio){
        aux[poslivre++] = v[inicio_v01++];
        // usa a variavel na posição atual, e depois incrementa

    }
 
    //se existirem núm. em v[inicio_v02] que não foram intercalados
    while (inicio_v02 <= fim){
        aux[poslivre++] = v[inicio_v02++];

    }
    
    //retorna os valores do vetor aux para o vetor v
    for (inicio_v01 = inicio; inicio_v01 <= fim; inicio_v01++){
        v[inicio_v01] = aux[inicio_v01-inicio];
        // inicio_v01 - inicio, para pegar a posição original do vetor

    }
    
}
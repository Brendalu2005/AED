#include <stdio.h>
#include <stdlib.h>

int main(){

}


void quicksort(int v[], int inicio, int fim){
    if(inicio < fim){ // verifica se tem pelo menos 2 elementos
        int indice = particao(v, inicio, fim);

        quicksort(v, inicio, indice - 1); // pega metade esquerda da lista
        quicksort(v, indice + 1, fim); // pega metade direita da lista
        //pivô não deve entrar mais nas próximas chamadas, ele já está fixado no lugar certo.
    }
}


int particao(int v[], int inicio, int fim){
    int pivot, indice, i;
    pivot = inicio;
    indice = fim;

    for(i = fim; i > inicio; i--){ // começa pelo fim da lista
        if(v[i] >= v[pivot]){ // se o ultimo elemento for >= o primeiro elemento
            troca(v, i, indice); // realiza a troca (passa para a direita)
            indice--; // diminui o indice (passa para o próximo a esquerda)
            //A variável indice controla até onde já colocamos valores maiores que o pivô.
        }
    }

    troca(v, pivot, indice);
    // Depois que o for termina, o pivô é colocado em sua posição final correta (indice).
    return indice;
}


void troca(int v[], int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}
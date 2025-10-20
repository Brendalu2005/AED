#include <stdio.h>
#include <stdlib.h>
#define LEN 6

int main(){
    // ordena crescente
               //   0  1  2  3  4  5
    int arr[LEN] = {1, 4, 6, 8, 3, 9};

    for (int i = 1; i < LEN; i++){ // for para percorrer os indices
        int j = i; 
        while(arr[j] < arr[j-1] && j > 0){
            // se o elemento atual for menor que o elemento na posição anterior
            // passa o elemento para a posição anterior até j = 0 (primeira posição da lista)
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--; 
            // enquanto obedecer a condição, vai decrementar o j para verificar se
            // não tem outros elementos maiores que o elemento na posição atual (j)
        }
    }

    for (int i = 0; i < LEN; i++){
        printf("%d- ", arr[i]);
    }
    printf("Fim\n");

    //ordena decrescente
    for (int i = 1; i < LEN; i++){
        int j = i; 
        while(arr[j] > arr[j-1] && j > 0){
            // se o elemento da posição atual for maior que o da posição anterior
            // passa ele para a posição anterior até j = 0 (primeira posição da lista)
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
             // enquanto obedecer a condição, vai decrementar o j para verificar se
            // não tem outros elementos menores que o elemento na posição atual (j)

        }
    }

    for (int i = 0; i < LEN; i++){
        printf("%d- ", arr[i]);
    }
    printf("Fim\n");


}
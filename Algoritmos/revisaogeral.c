#include <stdio.h>
#include <stdlib.h>
#define LEN 6

void InsertionSort(int v[LEN]);
void BSV0(int v[LEN]);
void BSV1(int v[LEN]);
void BSV2(int v[LEN]);
void ISinvertido(int v[LEN]);
void BSV0invertido(int v[LEN]);
void BSV1invertido(int v[LEN]);
void BSV2invertido(int v[LEN]);

int main(){
    int v[LEN] = { 7, 4, 3, 8, 6, 2};

    printf("lista atual: \n");
    for(int i = 0; i < LEN; i++){
        printf("%d -> ", v[i]);

    }
    printf("FIM\n");

    printf("Ordenando com insertion sort: \n");
    InsertionSort(v);

    printf("Ordenando com Bubble sort(V0): \n");
    BSV0(v);

    printf("Ordenando com Bubble sort(V1): \n");
    BSV1(v);

    printf("Ordenando com Bubble sort(V2): \n");
    BSV2(v);

    printf("Invertido:\n");
    printf("Ordenando com insertion sort: \n");
    ISinvertido(v);

    printf("Ordenando com Bubble sort(V0): \n");
    BSV0invertido(v);

    printf("Ordenando com Bubble sort(V1): \n");
    BSV1invertido(v);

    printf("Ordenando com Bubble sort(V2): \n");
    BSV2invertido(v);

}

void InsertionSort(int v[LEN]){
    for(int i = 1; i < LEN; i++){ // percorre os índices
        int j = i;
        while(v[j] < v[j-1] && j > 0){
            int temp = v[j];
            v[j] = v[j-1];
            v[j-1] = temp;
            j--;
        }
    }

   
    for(int i = 0; i < LEN; i++){
        printf("%d -> ", v[i]);

    }
    printf("FIM\n");

}

void ISinvertido(int v[LEN]){
    for(int i = 1; i < LEN; i++){ // percorre os índices
        int j = i;
        while(v[j] > v[j-1] && j > 0){
            int temp = v[j];
            v[j] = v[j-1];
            v[j-1] = temp;
            j--;
        }
    }

   
    for(int i = 0; i < LEN; i++){
        printf("%d -> ", v[i]);

    }
    printf("FIM\n");

}

void BSV0(int v[LEN]){
    for(int i = 1; i <= LEN; i++){ 
        for(int j = 0; j < LEN-1; j++){ // percorre os índices
            // LEN - 1 impede que um elemento fora do limite do indice seja acessado
            if(v[j] > v[j+1]){
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }

   
    for(int i = 0; i < LEN; i++){
        printf("%d -> ", v[i]);

    }
    printf("FIM\n");
}

void BSV0invertido(int v[LEN]){
    for(int i = 1; i <= LEN; i++){ 
        for(int j = 0; j < LEN-1; j++){ // percorre os índices
            // LEN - 1 impede que um elemento fora do limite do indice seja acessado
            if(v[j] < v[j+1]){
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }

   
    for(int i = 0; i < LEN; i++){
        printf("%d -> ", v[i]);

    }
    printf("FIM\n");
}

void BSV1(int v[LEN]){
    for(int i = 1; i < LEN; i++){
        for(int j = LEN-1; j >= i; j--){// controla os indices
            // LEN-1 para acessar o ultimo indice (j = LEN, não j < LEN);
            if(v[j] < v[j-1]){
                int temp = v[j];
                v[j] = v[j-1];
                v[j-1] = temp;
            }

        }
    }

    for(int i = 0; i < LEN; i++){
        printf("%d -> ", v[i]);

    }
    printf("FIM\n");
}

void BSV1invertido(int v[LEN]){
    for(int i = 1; i < LEN; i++){
        for(int j = LEN-1; j >= i; j--){// controla os indices
            // LEN-1 para acessar o ultimo indice (j = LEN, não j < LEN);
            if(v[j] > v[j-1]){
                int temp = v[j];
                v[j] = v[j-1];
                v[j-1] = temp;
            }

        }
    }

    for(int i = 0; i < LEN; i++){
        printf("%d -> ", v[i]);

    }
    printf("FIM\n");
}

void BSV2(int v[LEN]){
    int trocou;
    int n = 0;
    while(n < LEN && trocou == 1){
        trocou = 0;
        for(int i = 0; i <= LEN-1; i++){
            if(v[i] < v[i+1]){
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
                trocou = 1;

            }  
        }
        n++;
    }

    for(int i = 0; i < LEN; i++){
        printf("%d -> ", v[i]);

    }
    printf("FIM\n");
}

void BSV2invertido(int v[LEN]){
    int trocou;
    int n = 0;
    while(n < LEN && trocou == 1){
        trocou = 0;
        for(int i = 0; i <= LEN-1; i++){
            if(v[i] > v[i+1]){
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
                trocou = 1;

            }  
        }
        n++;
    }

    for(int i = 0; i < LEN; i++){
        printf("%d -> ", v[i]);

    }
    printf("FIM\n");
}
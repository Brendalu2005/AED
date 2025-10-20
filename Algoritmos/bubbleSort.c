#include <stdio.h>
#define LEN 6


// versao 2
int main(){
int v[LEN] = {2, 4, 5, 8, 3, 7};
for (int i = 1; i <= LEN-1; i++){ // controla quantas passadas completas o bubble sort faz
    int swap = 0;
    for(int j = 0; j < LEN-1; j++){ // controla as comparações
        if(v[j] > v[j+1]){
            int temp = v[j+1];
            v[j+1] = v[j];
            v[j] = temp;
            swap = 1;

        }

    }

    if(swap == 0){
        break;
    }
}

for(int i = 0; i < LEN; i++){
    printf("%d ", v[i]);
}

// versao 1
int C [LEN] = {4,6,9,2,4,3};
for(int i= 1; i<=LEN-1 ; i++) {
    for(int j = LEN-1; j>=i; j--) {
        if (C[j] < C[j-1] ) {
            int aux = C[j];
            C[j] = C[j-1];            
            C[j-1] = aux;
        }
    }
}
for(int i = 0; i < LEN; i++){
    printf(" %d ", C[i]);
}

// versao 0
int b[LEN] = {3, 4, 1, 5, 7, 6};
for (int i = 1; i <= LEN; i++){ // controla quantas passadas completas o bubble sort faz
    for(int j = 0; j < LEN-1; j++){ // controla as comparações
        if(b[j] > b[j+1]){
            int temp = b[j+1];
            b[j+1] = b[j];
            b[j] = temp;
            

        }

    }

}

for(int i = 0; i < LEN; i++){
    printf("%d ", b[i]);
}
// versao 2
int n =1, troca = 1;
while(n <= LEN && troca == 1){
    troca = 0;
    for(int i=0; i<LEN-1; i++) {
        if (v[i] > v[i+1] ) {
            int aux = v[i];
            v[i] = v[i+1];
            v[i+1] = aux;
            troca = 1;
        }

    }
    n++;
}
for(int i = 0; i < LEN; i++){
    printf(" %d ", v[i]);
}
}

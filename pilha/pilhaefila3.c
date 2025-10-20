#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
    char nome[30];
    struct Pessoa *next;

}Pessoa;

void addPilha(Pessoa **head, char nome[30]){
    Pessoa *novo =(Pessoa*)malloc(sizeof(Pessoa));
    strcpy(novo->nome, nome);
    novo->next = NULL;

    novo->next = *head;
    *head = novo; 
}

void addFila(Pessoa **head, Pessoa **tail, char nome[30]){
    Pessoa *novo = (Pessoa*)malloc(sizeof(Pessoa));
    strcpy(novo->nome, nome);
    novo->next = NULL;
    if(*head == NULL){
        *head = novo;
        *tail = novo;
    }else{
        (*tail)->next = novo;
        *tail = novo;
    }
}

void juntarFilas(Pessoa **head1, Pessoa **head2, Pessoa **head3, Pessoa **tail3, Pessoa **headP1){
    Pessoa *temp = *head1;
    while(temp != NULL){
        addFila(head3, tail3, temp->nome); 
       
        temp = temp->next;
    }

    temp = *head2;
    while(temp != NULL){
        addFila(head3, tail3, temp->nome);
        temp = temp->next;
    }

    temp = *head3; 
    while(temp != NULL){
        addPilha(headP1, temp->nome);
        temp = temp->next;
    }

}



void intercalaFilas(Pessoa **head1, Pessoa **head2, Pessoa **headP2){
    Pessoa *temp1 = *head1;
    Pessoa *temp2 = *head2;

    while(temp1 != NULL || temp2 != NULL){ 
        
        if(temp1 != NULL){
            addPilha(headP2, temp1->nome);  
            temp1 = temp1->next;
        }
        if(temp2 != NULL){
            addPilha(headP2, temp2->nome);  
            temp2 = temp2->next;
        }
    }

}

void imprime(Pessoa **head){
    Pessoa *temp = *head;

    while(temp != NULL){
        printf("%s-> ", temp->nome);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    Pessoa *headP1 = NULL;
    Pessoa *headP2 = NULL;
    Pessoa *headF1 = NULL;
    Pessoa *tailF1 = NULL;
    Pessoa *headF2 = NULL;
    Pessoa *tailF2 = NULL;

    Pessoa *headtemp = NULL;
    Pessoa *tailtemp = NULL;

    char nome[50];

    for(int i = 0; i < 5; i++){
        printf("insira os elementos na fila 1:\n");
        scanf("%s", nome);
        addFila(&headF1, &tailF1, nome);
    }

    for(int i = 0; i < 5; i++){
        printf("insira os elementos na fila 2:\n");
        scanf("%s", nome);
        addFila(&headF2, &tailF2, nome);
    }

    juntarFilas(&headF1, &headF2, &headtemp, &tailtemp, &headP1);
    intercalaFilas(&headF1, &headF2, &headP2);
    printf("F1: \n");
    imprime(&headF1);
    printf("F2: \n");
    imprime(&headF2);
    printf("P1: \n");
    imprime(&headP1);
    printf("P2: \n");
    imprime(&headP2);
    
}
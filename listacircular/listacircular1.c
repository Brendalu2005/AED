#include <stdio.h>
#include <stdlib.h>
#define LEN 6

typedef struct Node{
    int valor;
    struct Node *next;
}Node;

void addinicio(Node **head, Node **tail, int valor);
void imprimir(Node **head);

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    int arr[LEN] = {1, 2, 3, 4, 5, 6};

    for(int i = 0; i < LEN; i++){
        addinicio(&head, &tail, arr[i]);
    }

    imprimir(&head);



}

void addinicio(Node **head, Node **tail, int valor){ 
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor; 

        if(*head == NULL){
            *head = novo;
            *tail = novo;
            novo->next = novo; // aponta pra ele dnv

        }else{
            novo->next = *head; // o proximo inserido sempre vai apontar pro head
            (*tail)->next = novo; // aponta pro head
            *head = novo; // muda o primeiro elemento
 
        }
    }
}

void addFinal(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;

        if(*head == NULL){
            *head = novo;
            *tail = novo;
            novo->next = novo;
        }else{
            novo->next = *head; // ja aponta pro head
            (*tail)->next = novo; // o ultimo apronta pro novo;
            *tail = novo; // o novo é o ultimo

        }
    }
}

void removerInicio(Node **head, Node **tail){
    if(*head == NULL){
        *tail = NULL;

    }
    
    if(*head == *tail){
        *head = NULL;
        *tail = NULL;
      
        
    }
    Node *temp = *head;
    *head = (*head)->next;
    (*tail)->next = *head;
    free(temp);
}


void removerFinal(Node **head, Node **tail){
    if(*head == NULL){
        *tail = NULL;

    }
    if((*head)->next == *head){ // verifica se só tem um elemento
        free(*head); // libera o unico nó
        *head = NULL;
        *tail = NULL;
        
        
    }else{
        Node *temp = *head;
        while(temp->next != *tail){ // enquanto o proximo for diferente do ultimo
            temp = temp->next; // para no penultimo
        }

        *tail = temp; // atualiza para o novo ultimo percorrido 
        free(temp->next); // libera o ultimo
        (*tail)->next = *head; // aponta pro head
        
    }
}

void imprimir(Node **head){
    if(*head != NULL){
        Node *temp = *head;
        do{
            printf("%d ->", temp->valor);
            temp = temp->next;

        }while(temp != *head);

        printf("Fim\n");
    }
}
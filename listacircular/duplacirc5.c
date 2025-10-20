#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
    struct Node *ant; 
}Node;

int main(){

}

void addInicio(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;

        if(*head == NULL){
            *head = novo;
            *tail = novo;
            novo->prox = novo;
            novo->ant = novo;
        }else{
            novo->prox = *head;
            novo->ant = *tail;
            (*head)->ant = novo;
            (*tail)->prox = novo;
            *head = novo;
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
            novo->prox = novo;
            novo->ant = novo;
        }else{
            novo->prox = *head;
            novo->ant = *tail;
            (*head)->ant = novo;
            (*tail)->prox = novo;
            *tail = novo;
        }
    }
}

void removerInicio(Node **head, Node **tail){
    if(*head != NULL){
        if(*head == *tail){ // em duplamente circular NAO EXISTE NULL PARA O FIM!!!!!!!!!!!
            // SÓ EXISTE NULL EM CIRCULAR SIMPLES E DUPLAMENTE ENCADEADA
            free(*head);
            *head = NULL;
            *tail = NULL;

        }else{
            Node *temp = *head;
            *head = (*head)->prox;
            (*head)->ant = *tail;
            (*tail)->prox = *head;
            free(temp);
        }
    }
}

void removerFinal(Node **head, Node **tail){
    if(*head != NULL){
        if(*head == *tail){ // em duplamente circular NAO EXISTE NULL PARA O FIM!!!!!!!!!!!
            // SÓ EXISTE NULL EM CIRCULAR SIMPLES E DUPLAMENTE ENCADEADA
            free(*head);
            *head = NULL;
            *tail = NULL;

        }else{
            Node *temp = *tail;
            *tail = (*tail)->ant;
            (*head)->ant = *tail;
            (*tail)->prox = *head;
            free(temp);
        }
    }
}



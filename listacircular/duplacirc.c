#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
    struct Node *prev;

}Node;



void addFinal(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo!= NULL){
        novo->valor = valor;
        novo->prev = NULL;

        if(*head == NULL){
            *head = novo;
            *tail = novo;
            novo->next = novo;
            novo->prev = novo;
        }else{
            novo->next = *head;
            novo->prev = *tail;
           (*tail)->next = novo;
           (*head)->prev = novo;
           *tail = novo;

        }
    }
}

void addInicio(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo!= NULL){
        novo->valor = valor;
        novo->prev = NULL;

        if(*head == NULL){
            *head = novo;
            *tail = novo;
            novo->next = novo;
            novo->prev = novo;
        }else{
            novo->next = *head;
            novo->prev = *tail;
            (*tail)->next = novo;
            (*head)->prev = novo;
            *head = novo;

        }
    }
    
}


void imprimirNormal(Node **head){
    if(*head != NULL){
        Node *temp = *head;

        if(*head == NULL){
            printf("lista vazia\n");
            
        }
        do{
            printf("%d ->", temp->valor);
            temp = temp->next;

        }while(temp != *head);
        printf("NULL\n");

    }
}

void imprimirInverso(Node **head, Node **tail){
    if(*head != NULL){
        Node *temp = *tail;

        if(*head == NULL){
            printf("lista vazia\n");
            
        }
        do{
            printf("%d -> ", temp->valor);
            temp = temp->prev;

        }while( temp != *tail);

        printf("NULL\n");

    }
}

void removerInicio(Node **head, Node **tail){
    if(*head != NULL){
        if(*head == *tail){
            free(*head);
            *head = NULL;
            *tail = NULL;

        }else{
            Node *temp = *head;
            *head = (*head)->next;
            (*head)->prev = *tail;
            (*tail)->next = *head;
            free(temp);

        }

    }
}

void removerFinal(Node **head, Node **tail){
    if(*head != NULL){
        if(*head == *tail){
            free(*head);
            *head = NULL;
            *tail = NULL;

        }else{
            Node *temp = *tail;
            *tail = (*tail)->prev;
            (*head)->prev = *tail;
            (*tail)->next = *head;
            free(temp);

        }

    }
}


int main(){

}



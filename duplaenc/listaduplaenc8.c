#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
    struct Node *ant;
}Node;

int main(){
 // treinar basico ( add e remover )
}

void addFinal(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->prox = NULL;

        if(*head == NULL){
            *head = novo;
            novo->ant = NULL;

        }else{
            Node *temp = *head;

            while(temp != NULL){
                temp = temp->prox;
            }

            temp->prox = novo;
            novo->ant = temp;

        }
    }
}


void addInicio(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->prox = *head;

        if(*head == NULL){
            *head = novo;
            novo->ant = NULL;
        }else{
            novo->prox = *head;
            (*head)->ant = novo;
            *head = novo;
        }
    }
}


void removeFinal(Node **head){
    if(*head != NULL){
        Node *temp = *head;

        if(temp->prox == NULL){ // caso só tenha um elemento
            free(temp); // DAR FREE NO TEMP
            *head = NULL;
            
        }else{

            while(temp->prox != NULL){
                temp = temp->prox;
            }

            Node *remover = temp;
            temp->ant->prox = NULL;
            free(remover);
        }
    }
}


void removerInicio(Node **head){
    if(*head != NULL){
        Node *temp = *head;
        if(temp->prox == NULL){ // sempre verificar se só há UM elemento
            *head = NULL;
            free(temp);

        }else{
        *head = (*head)->prox;
        (*head)->ant = NULL;
        free(temp);

        }
    }
}
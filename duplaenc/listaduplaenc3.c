 #include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 
    int valor; 
    struct Node *prox; 
    struct Node *ant; 
} Node;

void inserir(Node **head, int valor);
void imprimir(Node **head);
void imprimirInverso(Node **head);
void remover(Node **head);

int main(){

}

void inserir(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->prox = *head;
        novo->ant = NULL;

        if(*head != NULL){
            (*head)->ant = novo;

        }

        novo->prox = (*head)->prox;
        *head = novo;
    }
}

void imprimir(Node **head){
    Node *temp = *head;
    while(temp != NULL){
        printf("%d ->", temp->valor);
        temp = temp->prox;
    }
    printf("FIM\n");
}

void imprimirInverso(Node **head){
    Node *temp = *head;
    if(temp != NULL){
        while(temp->prox != NULL){
            printf("%d", temp->valor);
            temp = temp->ant;
        }
    }
    printf("FIM\n");
}

void remover(Node **head){
    Node *temp = *head;
    if(*head != NULL){
        *head = temp->prox;
        free(temp);
        if(*head != NULL){
            (*head)->ant = NULL;
        }
    }
}

void removerFinal(Node **head){
    Node *temp = *head;
    if(*head != NULL){
        if(temp->prox == NULL){
            free(temp);
            *head = NULL;
            
        }
        while(temp->prox != NULL){
            temp = temp->prox;
        }


        temp->ant->prox = NULL;
        free(temp);
    }
}
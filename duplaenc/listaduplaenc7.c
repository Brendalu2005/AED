#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
    struct Node *ant;
}Node;

void inverterIntervalo(Node **head, int inicio, int fim);
void addInicio(Node **head, int valor);
void addFinal(Node **head, int valor);
int main(){

}

void addFinal(Node **head, int valor){
    Node *novo =(Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->prox = NULL;

        if(*head == NULL){
            *head = novo;
            novo->ant = NULL;
        }else{
            Node *temp = *head;
            while(temp->prox != NULL){
                temp = temp->prox;
            }

            temp->prox = novo;
            novo->ant = temp;
        }

    }
}

void addInicio(Node **head, int valor){
    Node *novo =(Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->prox = NULL;

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

void inverterIntervalo(Node **head, int inicio, int fim){
    if(*head != NULL && (*head)->prox != NULL){
        Node *temp = *head;
        int achouInicio = 0;
        int achouFinal = 0;
        Node *i = NULL, *f = NULL;

        while(temp != NULL){
            if(temp->valor == inicio){
                i = temp;
                achouInicio = 1;
                break;
            }
            temp = temp->prox;
        }

        if(achouInicio){
            while(temp != NULL){
                if(temp->valor == fim){
                    f = temp;
                    achouFinal = 1;
                    break;
                    
                }
                temp = temp->prox;
            }

        }

    //     if(achouInicio && achouFinal){
    //         if(i->prox == f){ // verifica se há elementos entre o inicio e o fim
    //             printf("Nao ha elementos o suficiente para troca")
    //         }else{
                

    //         }
    //     }

    // }

}
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;
    struct Node *prev;

}Node;

void addInicio(Node **head, Node **tail, int valor){
    Node *novo =(Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->next = *head; // o proximo nó aponta para o head
        
        if(*head == NULL){
            *head = novo;
            *tail = novo;
            novo->prev = NULL; // o anterior aponta para nulo


        }else{
            (*head)->prev = novo;
            *head = novo;

        }
    }
}

// void inserir(Node **head, int valor){
//     Node *novo = (Node*)malloc(sizeof(Node));
//     if(novo != NULL){
//         novo->valor = valor;
//         novo->next = *head;
//         novo->prev = NULL;

//         if(*head != NULL){
//             (*head)->prev = novo; 
    // se não for nulo, o anterior do head é o novo 

//         }

//         *head = novo; //se for nulo, o head é o novo
//     }
// }
// outro modo de add no inicio

void imprimirContrario(Node **head){
    Node *temp = *head;

    if(*head == NULL){
        printf("lista vazia\n");

    }else{
        while(temp->next != NULL){
            temp = temp->next;
        }

        while(temp != NULL){
            printf("%d ->", temp->valor);
            temp = temp->prev;
        }
     printf("\n");

    }
}

void removerInicio(Node **head){
    if(*head != NULL){
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        if(*head != NULL){
            (*head)->prev =  NULL;
        }

    }
    


}

int main(){

}
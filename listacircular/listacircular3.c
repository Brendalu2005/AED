#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;

}Node;

void addFinal(Node **head, Node **tail, int valor);
void mediaLista(Node *head);
void imprimir(Node *head);

int main(){
    Node *head = NULL;
    Node *tail = NULL;
    int arr[5] = {1, 2, 3, 4, 5};

    for(int i = 0; i < 5; i++){
        addFinal(&head, &tail, arr[i]);
    }

    imprimir(head);
    mediaLista(head);

}


// void addInicio(Node **head, Node **tail, int valor){
//     Node *novo = (Node*)malloc(sizeof(Node));
//     if(novo != NULL){
//         novo->valor = valor;
        

//         if(*head == NULL){
//             *head = novo;
//             *tail = novo;
//             novo->prox = novo;
//         }else{
//             novo->prox = *head;
//             (*tail)->prox = novo;
//             *head = novo;

//         }
//     }
// }
void imprimir(Node *head){
    if(head != NULL){
        Node *temp = head;
        do{
            printf("%d -> ", temp->valor);
            temp = temp->prox;

        }while(temp != head);
        printf("FIM\n");
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
        }else{
            novo->prox = *head;
            (*tail)->prox = novo;
            *tail = novo;
        }

    }
}

void mediaLista(Node *head){
    if(head == NULL){
        printf("lista vazia :(");

    }else{
        Node *temp = head;
        int cont = 0, soma = 0;

        do{
            soma += temp->valor;
            cont++;
            temp = temp->prox;

        }while(temp != head);

        int resultado = soma / cont;
        printf("%d\n", resultado);
    }
}
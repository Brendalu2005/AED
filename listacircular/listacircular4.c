#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;

}Node;

void addFinal(Node **head, Node **tail, int valor);
void contarPares(Node *head);
void imprimir(Node *head);

int main(){
    Node *head = NULL;
    Node *tail = NULL;
    int arr[8] = {8, 3, 5, 7, 9, 2, 10, 11};

    for(int i = 0; i < 8; i++){
        addFinal(&head, &tail, arr[i]);
    }

    imprimir(head);
    contarPares(head);

}

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

void contarPares(Node *head){
    if(head == NULL){
        printf("lista vazia :(\n");
    }else{
        Node *temp = head;
        int cont = 0;
        do{
            if(temp->valor % 2 == 0){
                printf("%d -> ", temp->valor);
                cont++;
            }
            temp = temp->prox;
        }while(temp != head);
        printf("FIM\n");
        printf("numeros pares: %d", cont);
    }
}

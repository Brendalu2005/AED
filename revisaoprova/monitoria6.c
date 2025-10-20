#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
    struct Node *ant;

}Node; 

void addFinal(Node **head, Node **tail, int valor);
void sequencia(Node *head, Node *tail);

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    int arr[6]={1, 3, 5, 7, 9, 11};

    for(int i = 0; i < 6; i++){
        addFinal(&head, &tail, arr[i]);
    }

    sequencia(head, tail);

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
            (*tail)->prox = novo;
            (*head)->ant = novo;
            *tail = novo;

        }
    }
}

void sequencia(Node *head, Node *tail){
    if(head != NULL){
    //Node *temp1 = head;
    //     int i = 1; // ja contando com o tail;

    //    while(temp1 != tail){ // para de contar qnd chega no tail
    //         temp1 = temp1->prox;
    //         i++;

    //     }
    

        // if(i < 4){
        //     printf("tamanho da lista eh insuficiente :( ");

        if(head == NULL || head == tail || head->prox == tail || head->prox->prox == tail){
            printf("tamanho da lista eh insuficiente :( ");

        }else{
            Node *temp2 = head;
            do{
                if(temp2->ant->valor % 2 != 0 && temp2->ant->ant->valor % 2 != 0 ){
                    printf("%d \n", temp2->valor);

                }
                temp2 = temp2->prox;
            
            }while(temp2 != head);

        }
    }
}
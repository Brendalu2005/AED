#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
}Node;

void somaConsecutivos(Node *head);
void addFinal(Node **head, Node **tail, int valor);
void imprimir(Node *head);

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(int i = 0; i < 9; i++){
        addFinal(&head, &tail, arr[i]);
    }

    imprimir(head);

    somaConsecutivos(head);

    

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
        novo->prox = NULL;

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


void somaConsecutivos(Node *head){
    if(head != NULL){
        Node *temp = head;
        int cont = 0;
        do{
            temp = temp->prox;
            cont++;


        }while(temp != head);

        if(cont < 2){
            printf("tamanho insuficiente\n");

        }else{
            if(cont % 2 == 0){
                Node *temp2 = head;
                int resultado;
                do{
                    resultado = temp2->valor + temp2->prox->valor;
                    printf("%d -> ", resultado);
                    temp2 = temp2->prox->prox;
                    
                }while(temp2 != head && temp2->prox != head);
                printf("FIM\n");

            }else{
                Node *temp3 = head;
                int resultado;
                do{
                    resultado = temp3->valor + temp3->prox->valor;
                    printf("%d -> ", resultado);
                    temp3 = temp3->prox->prox;
                    
                }while(temp3 != head && temp3->prox != head);
                

                if(temp3->prox == head){
                    resultado = temp3->valor + temp3->valor;
                    printf("%d -> ", resultado);
                }
                printf("FIM\n");
            }
        } 
    }
}
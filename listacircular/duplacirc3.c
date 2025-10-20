#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
    struct Node *ant;

} Node;

void imprimir(Node **head);
void addInicio(Node **head, Node **tail, int valor);
void removePosEsp(Node **head, Node **tail, int op);



int main(){
    Node *head = NULL;
    Node *tail = NULL;

    int op;
    int arr[5];
    
    
    for (int i = 1; i < 5+1; i++){
        printf("insira um numero: \n");
        scanf("%d", &arr[i]);
        addInicio(&head, &tail, arr[i]);

    }

    imprimir(&head);
    printf("Insira uma posição para deletar um valor específico: \n");
    scanf("%d", &op);
    removePosEsp(&head, &tail, op);
    imprimir(&head);



}

void imprimir(Node **head){
    if(*head != NULL){
        Node *temp = *head;
        do{
            printf("%d -> ", temp->valor);
            temp = temp->prox;

        }while(temp != *head);
        printf("NULL \n");
    }
}


void addInicio(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->ant = NULL;

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
            *head = novo; 
            // para add inicio, *head = novo, para add final, *tail = novo
        }
    }
}


void removePosEsp(Node **head, Node **tail, int op){
    if(*head != NULL){
        if(*head == *tail){ // se só há um elemento
            *head = NULL;
            *tail = NULL;

        }else{
            if(op == 1){
                Node *aux1 = *head; // guarda o antigo valor de head
                *head = (*head)->prox;
                (*head)->ant = *tail;
                (*tail)->prox = *head;
                free(aux1);

            }else{
                Node *temp = *head;
                for(int i = 1; i < op-1 && temp->prox != *head; i++){
                    temp = temp->prox;
                }
                Node *aux2 = temp->prox;// recebe o valor percorrido do for
                if( aux2 == *head){ // se o temp->prox aponta para o head
                    aux2 = *tail;
                    *tail = (*tail)->ant;
                    (*head)->ant = *tail;
                    (*tail)->prox = *head;
                    free(aux2);
                    
                }else{
                    temp->prox = aux2->prox;
                    aux2->prox->ant = temp;
                    free(aux2);

                }
            }
        }
    }
}
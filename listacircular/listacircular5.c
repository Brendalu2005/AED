#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;

}Node;

void addFinal(Node **head, Node **tail, int valor);
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

void removerInicio(Node **head, Node **tail){
    if(*head == NULL){
        *tail = NULL;
    }else{
        if(*head == *tail){
            *head = NULL;
            *tail = NULL;
        }else{
            Node *remover = *head;
            *head = (*head)->prox;
            (*tail)->prox = *head;
            free(remover);
        }
    }
}

void removerFinal(Node **head, Node **tail){
    if(*head == NULL){
        *tail = NULL;
    }else{
        if(*head == *tail){
            *head = NULL;
            *tail = NULL;
        }else{
            Node *temp = *head;
            while(temp->prox != *tail){
                temp = temp->prox;
            }

            Node *remover = temp->prox; // pega o ultimo (temp->prox)
            // ou Node *remover = *tail; // pega o ultimo direto
            *tail = temp; // o anterior ao ultimo, vira o ultimo (temp->prox)
            (*tail)->prox = *head;
            free(remover);


        }
    }
}


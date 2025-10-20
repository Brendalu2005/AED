#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
    struct Node *ant;
}Node;

void imprimir(Node *head);
void addFinalcomTail(Node **head, Node **tail, int valor);
void excluirIntervalo(Node **head, Node **tail, int delimitador01, int delimitador02);

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    int del1, del2;

    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    for(int i = 0; i < 8; i++){
        addFinalcomTail(&head, &tail, arr[i]);
    }

    imprimir(head);

    printf("insira dois delimitadores dentro do array: \n");
    scanf("%d %d", &del1, &del2);

    excluirIntervalo(&head, &tail, del1, del2);

    imprimir(head);


}

void imprimir(Node *head){
    if(head != NULL){
        Node *temp = head;

        while(temp != NULL){
            printf("%d -> ", temp->valor);
            temp = temp->prox;
        }

        printf("NULL\n");
    }
}

void addFinalcomTail(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->prox = NULL;

        if(*head == NULL){
            *head = novo;
            *tail = novo;
            novo->ant = NULL;

        }else{
            novo->ant = *tail;
            (*tail)->prox = novo;
            *tail = novo;
        }
    }
}

void excluirIntervalo(Node **head, Node **tail, int delimitador01, int delimitador02){
    if(*head == NULL || (*head)->prox == NULL || (*head)->prox->prox == NULL){
        printf("Lista com elementos insuficientes\n");

    }else{
        Node *temp = *head, *d01 = NULL, *d02 = NULL;

        // encontra primeiro d01
        while(temp != NULL){
            if(temp->valor == delimitador01){
                d01 = temp;
                break;

            }
            temp = temp->prox;
        }

        
        Node *temp2 = d01->prox; //depois de achar d01, a partir do próximo de d01, passa a procurar d02
        while(temp2 != NULL){
            if(temp2->valor == delimitador02){
                d02 = temp2;
                break;
            }
            temp2 = temp2->prox;
            
        }

        if(d01->prox == d02){ 
            // se o proximo de d01 aponta para d01, significa que não há mais de 1 elemento entre eles
            printf("Nao ha elementos o suficiente para a remocao\n");

        }else{

            Node *aux = d01->prox;
            while(aux != d02){ // vai percorrer iniciando em d01, e para quando chega em d02
                Node *remover = aux; // pega o elemento antigo
                aux = aux->prox; // passa para o próximo
                free(remover); // remove o antigo
            }

            d01->prox = d02;
            d02->ant = d01; // realoca os nós para d01->d02

            if(d02->prox == NULL){
                *tail = d02;
            }
        }
    }
}

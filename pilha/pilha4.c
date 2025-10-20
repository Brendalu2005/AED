#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node *next;
}Node;

void removepilha(Node **head);
void addpilha(Node **head, int num);
void imprime(Node **head);
void trocaprimeiro(Node **head1, Node **head2);
void trocaultimo(Node **head1, Node **head2);

int main(){
    Node *head1 = NULL;
    Node *head2 = NULL;

    int n, numero;

    printf("Insira o tamanho da pilha: \n");
    scanf("%d", &n);

    printf("Primeira pilha: \n");
    for(int i = 0; i < n; i++){
        printf("insira o elemento na pilha: \n");
        scanf("%d", &numero);

        addpilha(&head1, numero);
    }

    printf("Segunda pilha: \n");
    for(int i = 0; i < n; i++){
        printf("insira o elemento na pilha: \n");
        scanf("%d", &numero);

        addpilha(&head2, numero);
    }

    printf("Primeira pilha: \n");
    imprime(&head1);
    printf("Segunda pilha: \n");
    imprime(&head2);
    trocaprimeiro(&head1, &head2);
    printf("Primeiro elemento trocado \n");
    imprime(&head1);
    imprime(&head2);

    trocaultimo(&head1, &head2);
    printf("ultimo elemento trocado \n");
    imprime(&head1);
    imprime(&head2);
}

void addpilha(Node **head, int num){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->num = num;
    novo->next = NULL;

    novo->next = *head;
    *head = novo;
}

void imprime(Node **head){
    Node *temp = *head;

    while(temp != NULL){
        printf("%d -> ", temp->num);
        temp = temp->next;
    }
    printf("Fim\n");
}

// pega o primeiro elemento da pilha (ultimo inserido)
void trocaprimeiro(Node **head1, Node **head2){
    if(*head1 == NULL || *head2 == NULL){
        printf("Não eh possivel realizar a troca\n");

    }else{
        
        int aux = (*head2)->num;
        (*head2)->num = (*head1)->num;
        (*head1)->num = aux;

    }
}

//pega o ultimo elemento da pilha (primeiro inserido)
void trocaultimo(Node **head1, Node **head2){
    if(*head1 == NULL || *head2 == NULL){
        printf("Não eh possivel realizar a troca\n");

    }else{
        Node *temp1 = *head1;
        Node *temp2 = *head2;
        while(temp1->next != NULL && temp2->next != NULL){
            temp1 = temp1->next;
            temp2 = temp2->next;
            
        }

        int aux = temp2->num;
        temp2->num = temp1->num;
        temp1->num = aux;

    }
}

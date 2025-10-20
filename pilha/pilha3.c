#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node *next;
}Node;

void removepilha(Node **head);
void addpilha(Node **head, int num);
void imprime(Node **head);

int main(){
    Node *head = NULL;

    int n, numero;

    printf("Insira o tamanho da pilha: \n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("insira o elemento na pilha: \n");
        scanf("%d", &numero);

        addpilha(&head, numero);
    }
    
    imprime(&head);
    removepilha(&head);
    imprime(&head);
}

void addpilha(Node **head, int num){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->num = num;
    novo->next = NULL;

    novo->next = *head;
    *head = novo;
}

void removepilha(Node **head){
    Node *temp = *head;

    *head = (*head)->next;
    free(temp);

}

void imprime(Node **head){
    Node *temp = *head;

    while(temp != NULL){
        printf("%d -> ", temp->num);
        temp = temp->next;
    }
    printf("Fim\n");
}
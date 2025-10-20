#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int num;
    struct Node *next;

}Node;

void addfila(Node **head, Node **tail, int num){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->num = num;
        novo->next = NULL;

        if(*head == NULL){
            *head = novo;
            *tail = novo;
        }else{
            (*tail)->next = novo;
            *tail = novo;
        }
    }
}

void limpafila(Node **head, Node **tail){
    Node *temp = *head;
    if(*head != NULL){
        *head = (*head)->next;
        free(temp);
    }

    if(*head == NULL){
        *tail = NULL;
    }
}

void imprime(Node **head){
    Node *temp = *head;
    while(temp != NULL){
        printf("%d- ", temp->num);
        temp = temp->next;
    }

    printf("FIM \n");
}

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    int n, num;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        printf("insira um numero: \n");
        scanf("%d", &num);
        addfila(&head, &tail, num);
        
    }

    imprime(&head);

}
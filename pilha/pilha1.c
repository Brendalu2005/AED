#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node *next;

}Node;

void add(Node **head, int num){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->num = num;
    novo->next = NULL;

    novo->next = *head; // o novo aponta pro head
    *head = novo; // o head vai ser o novo número inserido
}

void limpa(Node **head){
    if(*head == NULL){
        printf("vazio\n");
    }
   
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    // para remover de um em um, não insere no loop while

}

void imprimir (Node **head){
    Node *temp = *head;

    if (temp != NULL) {
        printf("head: %d\n", temp->num);
    } 

    while(temp != NULL){
        printf("%d-> ", temp->num);
        temp = temp->next;


    }
    printf("NULL\n");

    
}


int main(){
    Node *head = NULL;
    int num;
    for(int i = 0; i < 4; i++){
        scanf("%d", &num);
        add(&head, num);
       
    }

    imprimir(&head);
    printf("limpando: \n");
    limpa(&head);
    imprimir(&head);


}
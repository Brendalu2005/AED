#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int numero;
    struct Node *next;
}Node;

int tam = 6;

void addlista(Node **head, int numero){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->numero = numero;
    novo->next = NULL;

    if(*head == NULL){
        novo->next = *head;
        *head = novo;
    }else{
        Node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        novo->next = temp->next;
        temp->next = novo;
    }
}

void addordenado(Node **head, Node **tail, int numero){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->numero = numero;
    novo->next = NULL;
    
    if(*head == NULL){
        *head = novo;
        *tail = novo;
    }
   
    if(novo->numero < (*head)->numero){ //verifica se o novo numeor inserido é maior que o head
        novo->next = *head;
        *head = novo; 

    }else if(novo->numero > (*tail)->numero){ // verifica se o novo numero inserido é maior q o ultimo número
        (*tail)->next = novo;
        *tail = novo;
        

    }else{ // se não for nenhum dos casos
        Node *temp = *head;
        while(temp->next != NULL && temp->next->numero < novo->numero){ 
            // enquanto temp->next não aponta para null, e nó do proximo valor aponta para um numero menor q o novo numero inserido
            temp = temp->next;// percorre a lista

        }

        novo->next = temp->next;
        temp->next = novo;
    }

}

void imprime(Node **head){
    Node *temp = *head;
    while(temp != NULL){
        printf("%d -> ", temp->numero);
        temp = temp->next;
    }
    printf("FIM \n");
}



// void addordenado(Node **head, int numero){
//     Node *novo = (Node*)malloc(sizeof(Node));
//     novo->numero = numero;
//     novo->next = NULL;

//     if(*head == NULL || novo->numero < (*head)->numero){
//         novo->next = *head;
//         *head = novo;
//     }else{
//         Node *temp = *head;
//         while(temp != NULL && temp->next->numero < temp->numero){
//             //verifica se o numero do proximo nó é menor que o numero atual
//             temp = temp->next;
//         }

//         novo->next = temp->next;
//         temp->next = novo;

//     } // SEM TAIL
// }


int main(){
    Node *head1 = NULL;
    Node *tail = NULL;
    Node *head2 = NULL;

    int n, numero;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("insira um numero na lista: \n");
        scanf("%d", &numero);
        addlista(&head1, numero);
        addordenado(&head2, &tail, numero);
    }
    printf("lista normal: \n");
    imprime(&head1);
    printf("lista ordenada: \n");
    imprime(&head2);

}
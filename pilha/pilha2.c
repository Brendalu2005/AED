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

    novo->next = *head; 
    *head = novo; 
}

void limpa(Node **head){
    if(*head == NULL){
        printf("pilha vazia\n");
    }
   
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
   
}

void imprimirPilha (Node **head){
    Node *temp = *head;
    while(temp != NULL){
        printf("%d-> ", temp->num);
        temp = temp->next;


    }
    printf("NULL\n");
}

void imprimirTopo (Node **head){
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


void imprimirBase (Node **head){
    Node *temp = *head;

    while (temp != NULL){
        if (temp->next == NULL) {
        printf("Primeiro elemento: %d\n", temp->num);
        }
        temp = temp->next;
    
    }

}

void imprimirPar (Node **head){
    Node *temp = *head;
    int cont = 0;

    while(temp != NULL){
        if(cont % 2 == 0){
            printf("%d-> ", temp->num);

        }
        cont++;
        temp = temp->next;

    }
    printf("NULL\n");

}


int main(){
    Node *head = NULL;
    int num, num2, N, op;
    printf("Insira a quantidade de elementos: \n");
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        printf("Insira numero: \n");
        scanf("%d", &num);
        add(&head, num);
       
    }

    while(op != 6){
        printf("1 - Inserir novos elementos\n");
        printf("2 - Imprimir a base da pilha\n");
        printf("3 - Imprimir o topo da pilha\n");
        printf("4 - Remover um no da pilha\n");
        printf("5 - Imprimir todos os nos na posicao par\n");
        printf("6 - sair\n");

        printf("escolha uma opcao: \n");
        scanf("%d", &op);

        switch (op){
        case 1:
            printf("Insira numero: \n");
            scanf("%d", &num2);
            add(&head, num2);
            break;

        case 2:
            imprimirBase(&head);
            break;
        
        case 3:
            imprimirTopo(&head);
            break;
        
        case 4:
            limpa(&head);
            imprimirPilha(&head);
            break;

        case 5:
            imprimirPar(&head);
            break;
        
        case 6: 
            break;

        default:
            printf("Insira uma opção válida\n");
            break;
        }

    }
   
}
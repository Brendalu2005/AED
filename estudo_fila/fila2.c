#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char nome[30];
    struct Node *next;

}Node;

void enqueue(Node **head, Node **tail, char nome[30]){
    Node *novo =(Node*)malloc(sizeof(Node));
    strcpy(novo->nome, nome);
    novo->next = NULL;

    if(*head == NULL){
        *head = novo;
        *tail = novo;

    }else{
        (*tail)->next = novo;// o nó do próximo tail aponta para o novo elemento inserido
        *tail = novo; // o novo elemento é o ultimo.

    }

}


int dequeue(Node **head, Node **tail){
    Node *temp = *head;
    printf("Realizando atendiento do paciente: %s\n", temp->nome);
    *head = (*head)->next;
    free(temp);
    return 1;

    if(*head == NULL){
        *tail = NULL;
        return 0;
    }

}

void imprimir(Node **head){
    Node *temp = *head;
    while(temp != NULL){
        printf("%s-> ", temp->nome);
        temp = temp->next;
    }
    printf("NULL\n");
}

void posicao(Node **head, char nome[30]){
    int pos = 0;
    int encontrou = 0;
    Node *temp = *head;

    while(temp != NULL){
        if(strcmp(temp->nome, nome) == 0){
            printf("paciente: %s, posicao %d\n", temp->nome, pos);
            encontrou = 1;
            break;
        }

        temp = temp->next;
        pos++;
    }
    if(!encontrou){
        printf("paciente %s, nao encontrado\n", nome);

    }


}

int main(){
    Node *head = NULL;
    Node *tail = NULL;
    int op = 0, cont = 0;
    char nome[30];
    char checarNome[30];

    
    while(op != 5){
        printf("Clinica Medica\n");
        printf("=============\n");
        printf("(1) Incluir paciente\n");
        printf("(2) Realizar atendimento do paciente (remocao do paciente)\n");
        printf("(3) Consultar a posicao atual do paciente pelo nome\n");
        printf("(4) Exibir a quantidade de pacientes ja atendidos\n");
        printf("(5) Sair\n");

        printf("Escolha uma opcao: \n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("insira o nome do paciente: \n");
            scanf("%s", nome);
            enqueue(&head, &tail, nome);
            printf("Paciente inserido!\n");
            break;
        
        case 2:
            if (dequeue(&head, &tail)){
                imprimir(&head);
                cont++;
            }else{
               printf("Fila vazia, nenhum paciente para atender.\n");
            }
            break;
        
        case 3:
            printf("Insira o nome do paciente: \n");
            scanf("%s", checarNome);
            printf("Verificando...\n");
            posicao(&head, checarNome);
            break;
        
        case 4:
            if (cont == 0){
                printf("Nenhum paciente atendido\n");
            }else{
                printf("Pacientes atendidos: %d \n", cont);
            }
            break;
        
        case 5:
            printf("finalizando...\n");
            break;
        
        default:
            printf("insira uma opção válida\n");
            break;
        }

    }
}
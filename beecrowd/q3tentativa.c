#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista{
    char compras[100];
    struct Lista *next;
} Lista;

void addLista(Lista **head, char compras[100]);
void ordenarLista(Lista **head);
void imprimirLista(Lista *head);
void removerLista(Lista **head);

int main(){
    int N;
    scanf("%d", &N);
    getchar();

    for(int i = 0; i < N; i++){
        Lista *head = NULL;
        char linha[25001]; 

        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = '\0';

        char *palavra = strtok(linha, " ");
        while(palavra != NULL){
            addLista(&head, palavra);
            palavra = strtok(NULL, " ");
        }

        ordenarLista(&head);
        imprimirLista(head);
        removerLista(&head);
    }

    
}

void addLista(Lista **head, char compras[100]){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    if(novo != NULL){
        strcpy(novo->compras, compras);
        novo->next = NULL;

        if(*head == NULL){
            *head = novo;
        } else {
            Lista *temp = *head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = novo;
        }
    }
}

void ordenarLista(Lista **head){
    if(*head == NULL) return;

    int trocou = 1;

    while(trocou){
        trocou = 0;
        Lista *atual = *head;
        Lista *prev = NULL;

        while(atual != NULL && atual->next != NULL){
            if(strcmp(atual->compras, atual->next->compras) > 0){
                Lista *nextNode = atual->next;
                atual->next = nextNode->next;
                nextNode->next = atual;

                if(prev == NULL){
                    *head = nextNode;
                } else {
                    prev->next = nextNode;
                }

                prev = nextNode;
                trocou = 1;
            } else {
                prev = atual;
                atual = atual->next;
            }
        }
    }

    
    Lista *atual = *head;
    while(atual != NULL && atual->next != NULL){
        if(strcmp(atual->compras, atual->next->compras) == 0){
            Lista *duplicada = atual->next;
            atual->next = duplicada->next;
            free(duplicada);
        } else {
            atual = atual->next;
        }
    }
}


void imprimirLista(Lista *head){
    Lista *temp = head;
    while(temp != NULL){
        printf("%s", temp->compras);
        if(temp->next != NULL){
            printf(" ");
        } 
        temp = temp->next;
    }
    printf("\n");
}

void removerLista(Lista **head){
    while(*head != NULL){
        Lista *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

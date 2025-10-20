#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char num;
    struct Node *next;
} Node;

void addPilha(Node **head, char num);
void apaga(Node **head);

int main() {
    int quantidade;

    while (1) {
        scanf("%d", &quantidade);
        if (quantidade == 0){
            break;
        }

        Node *entrada = NULL, *saida = NULL, *pilha = NULL;
        int impossivel = 0;

        
        for (int i = 0; i < quantidade; i++) {
            char c;
            scanf(" %c", &c);
            addPilha(&entrada, c);
        }

        for (int i = 0; i < quantidade; i++) {
            char c;
            scanf(" %c", &c);
            addPilha(&saida, c);
        }

       
        Node *temp = NULL;
        while (entrada != NULL) {
            char c = entrada->num;
            apaga(&entrada);
            addPilha(&temp, c);
        }
        entrada = temp;

        temp = NULL;
        while (saida != NULL) {
            char c = saida->num;
            apaga(&saida);
            addPilha(&temp, c);
        }
        saida = temp;

        
        while (saida != NULL) {
            if (pilha != NULL && pilha->num == saida->num) {
                apaga(&pilha);
                apaga(&saida);
                printf("R");
            } else if (entrada != NULL) {
                char c = entrada->num;
                apaga(&entrada);
                addPilha(&pilha, c);
                printf("I");
            } else {
                impossivel = 1;
                break;
            }
        }

            if (impossivel){
                printf(" Impossible");
            }
        printf("\n");
    }

  
}


void addPilha(Node **head, char num) {
    Node *novo = (Node*)malloc(sizeof(Node));
    if (novo != NULL) {
        novo->num = num;
        novo->next = NULL;

        novo->next = *head;
        *head = novo;
    }
}

void apaga(Node **head) {
    Node *temp = *head;
    if (*head != NULL) {
        *head = temp->next;
        free(temp);
    }
}

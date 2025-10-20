#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char nome[50];
    int valor;
    struct Node* next;
    struct Node* prev;
} Node;

Node* criar_no(char nome[], int valor);
void adicionar_no(Node** head, Node** tail, char nome[], int valor);
void remover_no(Node** head, Node** tail, Node* atual);
Node* mover_no(Node* atual, int passos, int sentido);

int main() {
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        Node* head = NULL;
        Node* tail = NULL;
        char nome[50];
        int valor;

        for (int i = 0; i < n; i++) {
            scanf("%s %d", nome, &valor);
            adicionar_no(&head, &tail, nome, valor);
        }

        if (head == NULL) {
            printf("Vencedor(a): \n");
        } else {
            Node* atual = head;
            int valorAtual = atual->valor;

            while (head != tail) {
                int sentido;
                if (valorAtual % 2 != 0) {
                    sentido = 1;  
                } else {
                    sentido = -1; 
                }

                atual = mover_no(atual, valorAtual, sentido);
                valorAtual = atual->valor;

                Node* proximo;
                if (valorAtual % 2 != 0) {
                    proximo = atual->prev;
                } else {
                    proximo = atual->next;
                }

                remover_no(&head, &tail, atual);
                atual = proximo;
            }

            printf("Vencedor(a): %s\n", head->nome);
            free(head);
        }
    }

    
}

Node* criar_no(char nome[], int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo != NULL) {
        strcpy(novo->nome, nome);
        novo->valor = valor;
        novo->next = novo;
        novo->prev = novo;
    }
    return novo;
}

void adicionar_no(Node** head, Node** tail, char nome[], int valor) {
    Node* novo = criar_no(nome, valor);
    if (novo == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = novo;
        *tail = novo;
    } else {
        novo->prev = *tail;
        novo->next = *head;
        (*tail)->next = novo;
        (*head)->prev = novo;
        *tail = novo;
    }
}

void remover_no(Node** head, Node** tail, Node* atual) {
    if (*head == NULL || atual == NULL) {
        return;
    }

    if (atual->next == atual) {
        free(atual);
        *head = NULL;
        *tail = NULL;
        
    }

    if (atual == *head) {
        *head = atual->next;
    }

    if (atual == *tail) {
        *tail = atual->prev;
    }

    atual->prev->next = atual->next;
    atual->next->prev = atual->prev;
    free(atual);
}

Node* mover_no(Node* atual, int passos, int sentido) {
    for (int i = 0; i < passos; i++) {
        if (sentido == 1) {
            atual = atual->next;
        } else {
            atual = atual->prev;
        }
    }
    return atual;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *next;
    struct Node *prev;
} Node;

void addFinal(Node **head, Node **tail, int valor);
void remover(Node **head, Node **tail, Node *alvo);
Node* avancaHorario(Node *p, int k);
Node* avancaAntiHorario(Node *p, int m);
void processar(int N, int k, int m);

int main() {
    int N, k, m;
    while (scanf("%d %d %d", &N, &k, &m) == 3) {
        if (N == 0 && k == 0 && m == 0) {
            break;
        } else {
            processar(N, k, m);
        }
    }
    
}

void addFinal(Node **head, Node **tail, int valor) {
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo != NULL){
        novo->valor = valor;
        if (*head == NULL) {
            *head = novo;
            *tail = novo;
            novo->next = novo;
            novo->prev = novo;
        } else {
            novo->next = *head;
            novo->prev = *tail;
            (*tail)->next = novo;
            (*head)->prev = novo;
            *tail = novo;
        }
    } 
}

void remover(Node **head, Node **tail, Node *alvo) {
    if (!alvo || !*head) {
        return;
    }
    if (alvo == *head && alvo == *tail) {
        *head = NULL;
        *tail = NULL;
    } else {
        Node *anterior = alvo->prev;
        Node *proximo = alvo->next;
        anterior->next = proximo;
        proximo->prev = anterior;
        if (alvo == *head){
            *head = proximo;
        } 
        if (alvo == *tail){
            *tail = anterior;
        } 
    }
    free(alvo);
}

Node* avancaHorario(Node *p, int k) {
    int i;
    for (i = 1; i < k; i++) {
        p = p->next;
    }
    return p;
}

Node* avancaAntiHorario(Node *p, int m) {
    int i;
    for (i = 1; i < m; i++) {
        p = p->prev;
    }
    return p;
}

void processar(int N, int k, int m) {
    Node *head = NULL;
    Node *tail = NULL;
    
    for (int i = 1; i <= N; i++) {
        addFinal(&head, &tail, i);
    }

    Node *sentidoHorario = head;
    Node *sentidoAntiHorario = tail;
    int primeiro = 1;

    while (head != NULL) {

        for (int i = 1; i < k; i++) {
            sentidoHorario = sentidoHorario->next;
        }

        for (int i = 1; i < m; i++) {
            sentidoAntiHorario = sentidoAntiHorario->prev;
        }

        if (!primeiro) {
            printf(",");
        } else {
            primeiro = 0;
        }

        if (sentidoHorario == sentidoAntiHorario) {
            printf("%3d", sentidoHorario->valor);
            Node *prox = sentidoHorario->next;
            Node *ant = sentidoAntiHorario->prev;
            remover(&head, &tail, sentidoHorario);
            if (head != NULL) {
                sentidoHorario = prox;
                sentidoAntiHorario = ant;
            }
        } else {
            printf("%3d%3d", sentidoHorario->valor, sentidoAntiHorario->valor);
            Node *dirNext = sentidoHorario->next;
            Node *dirPrev = sentidoHorario->prev;
            Node *esqNext = sentidoAntiHorario->next;
            Node *esqPrev = sentidoAntiHorario->prev;

            Node *tempDir = sentidoHorario;
            Node *tempEsq = sentidoAntiHorario;

            remover(&head, &tail, tempDir);
            remover(&head, &tail, tempEsq);

            if (head != NULL) {
                if (dirNext == tempEsq) {
                    sentidoHorario = esqNext;
                } else {
                    sentidoHorario = dirNext;
                }
                if (esqPrev == tempDir) {
                    sentidoAntiHorario = dirPrev;
                } else {
                    sentidoAntiHorario = esqPrev;
                }
            }
        }
    }
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *next;
} Node;

void addFinal(Node **inicio, Node **fim, int valor);
void remover(Node **inicio, Node **fim, Node *alvo, Node **prev);
Node* avancaHorario(Node *p, int k);
Node* avancaAntiHorario(Node *p, int m, Node **prev, Node *inicio);

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

void processar(int N, int k, int m) {
    Node *inicio = NULL;
    Node *fim = NULL;

    for (int i = 1; i <= N; i++) {
        addFinal(&inicio, &fim, i);
    }

    Node *sentidoHorario = inicio;
    Node *sentidoAntiHorario = fim;
    Node *prevAnti = fim; 
    int primeiro = 1;

    while (inicio != NULL) {
        sentidoHorario = avancaHorario(sentidoHorario, k);
        sentidoAntiHorario = avancaAntiHorario(sentidoAntiHorario, m, &prevAnti, inicio);

        if (!primeiro) {
            printf(",");
        } else {
            primeiro = 0;
        }

        if (sentidoHorario == sentidoAntiHorario) {
            printf("%3d", sentidoHorario->valor);
            Node *proxHorario = sentidoHorario->next;

            remover(&inicio, &fim, sentidoHorario, &prevAnti);

            sentidoHorario = proxHorario;
            sentidoAntiHorario = prevAnti;

        } else {
            printf("%3d%3d", sentidoHorario->valor, sentidoAntiHorario->valor);

            Node *proxHorario = sentidoHorario->next;
            Node *proxAnti = sentidoAntiHorario->next;

            Node *tempHorario = sentidoHorario;
            Node *tempAnti = sentidoAntiHorario;

            remover(&inicio, &fim, tempHorario, &prevAnti);

            if (tempAnti != tempHorario) {
                remover(&inicio, &fim, tempAnti, &prevAnti);
            }

            sentidoHorario = proxHorario;
            sentidoAntiHorario = proxAnti;
        }
    }

    printf("\n");
}

void addFinal(Node **inicio, Node **fim, int valor) {
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo != NULL) {
        novo->valor = valor;
        if (*inicio == NULL) {
            *inicio = novo;
            *fim = novo;
            novo->next = novo;
        } else {
            novo->next = *inicio;
            (*fim)->next = novo;
            *fim = novo;
        }
    }
}

void remover(Node **inicio, Node **fim, Node *alvo, Node **prev) {
    if (*inicio == NULL || alvo == NULL) {
        return;
    }

    Node *temp = *inicio;
    Node *anterior = *fim;

    while (temp != alvo) {
        anterior = temp;
        temp = temp->next;
    }

    if (temp == *inicio && temp == *fim) {
        *inicio = NULL;
        *fim = NULL;
        *prev = NULL;
    } else {
        if (temp == *inicio) {
            *inicio = temp->next;
        }
        if (temp == *fim) {
            *fim = anterior;
        }
        anterior->next = temp->next;
        *prev = anterior;
    }

    free(temp);
}

Node* avancaHorario(Node *p, int k) {
    int i;
    for (i = 1; i < k; i++) {
        p = p->next;
    }
    return p;
}

Node* avancaAntiHorario(Node *p, int m, Node **prev, Node *inicio) {
    int i;
    for (i = 1; i < m; i++) {
        Node *tmp = inicio;
        while (tmp->next != p) {
            tmp = tmp->next;
        }
        *prev = tmp;
        p = tmp;
    }
    return p;
}

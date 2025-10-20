#include <stdio.h>
#include <stdlib.h>

typedef struct Paciente {
    int h;
    int m;
    int c;
    struct Paciente *ant;
    struct Paciente *prox;
} Paciente;

int main() {
    int N;
    while(scanf("%d", &N) == 1 && N > 0) {
        Paciente *fila = NULL;
        Paciente *tail = NULL;
        int H, M, C;

        for(int i = 0; i < N; i++) {
            scanf("%d %d %d", &H, &M, &C);
            void inserirFinal(Paciente **head, Paciente **tail, int H, int M, int C);
            inserirFinal(&fila, &tail, H, M, C);
        }

        int tempo_atual = 0;
        int criticos = 0;
        Paciente *p = fila;

        while(p != NULL) {
            int chegada = (p->h - 7) * 60 + p->m;
            if(chegada > tempo_atual) {
                tempo_atual = chegada;
            }

            if(tempo_atual % 30 != 0) {
                tempo_atual = (tempo_atual / 30 + 1) * 30;
            }

            if(tempo_atual - chegada > p->c) {
                criticos++;
            }

            void removerInicio(Paciente **head);
            removerInicio(&fila);
            tempo_atual += 30;
            p = fila;
        }

        printf("%d\n", criticos);
    }
}

void inserirFinal(Paciente **head, Paciente **tail, int H, int M, int C) {
    Paciente *novo = (Paciente*) malloc(sizeof(Paciente));
    if(novo != NULL) {
        novo->h = H;
        novo->m = M;
        novo->c = C;
        novo->prox = NULL;
        if(*head == NULL) {
            novo->ant = NULL;
            *head = *tail = novo;
        } else {
            novo->ant = *tail;
            (*tail)->prox = novo;
            *tail = novo;
        }
    }
}

void removerInicio(Paciente **head) {
    if(*head == NULL) return;
    Paciente *aux = *head;
    if(aux->prox == NULL) {
        *head = NULL;
        free(aux);
        return;
    }
    *head = aux->prox;
    aux->prox->ant = NULL;
    free(aux);
}

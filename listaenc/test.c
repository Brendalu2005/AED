#include <stdio.h>

typedef struct node
{
    int n;
    struct node *next;
} node;

void inserirInicio (node **head, int n) {
    node *novo = (node *) malloc (sizeof(node));

    if (novo != NULL) {
        novo ->n = n;
        novo ->next = *head;
        *head = novo;
    }
}

void inserirFinal (node **head, int n) {
    node *novo = (node *) malloc (sizeof(node));

    novo ->n = n;
    novo ->next = NULL;

    if (*head == NULL) {
        *head = novo;
    }

    node *aux = *head;

    while(aux ->next != NULL) {
        aux = aux ->next;
    }

    aux ->next = novo;
}

void deletarComeco (node **head) {
    if (*head != NULL) {
        node *aux = *head;
        *head = (*head) ->next;
        free(aux);
    }
}

void deletarFinal (node **head) {
    if ((*head) == NULL) {
        *head = NULL;
    }

    node *aux = *head;

    while (aux ->next ->next != NULL) {
        aux = aux ->next;
    }

    free(aux ->next);

    aux ->next = NULL;
}
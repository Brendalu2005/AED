#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int numero;
    struct Node *prox;

}Node;

void enqueue(Node **head, Node **tail, int numero){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->numero = numero;
    novo->prox = NULL;

    if(*head == NULL){
        *head = novo;
        *tail = novo;
        // tail aponta para o ultimo nó atual da fila
        // se head for vazio (sem elementos na lista, head e tail apontam para o novo elemnto)

    }else{
        (*tail)->prox = novo; // aponta o ultimo nó atual para o novo ultimo
        *tail = novo; // aponta para o novo ultimo da fila
        // as próximas ligações são a partir desse número
        // diferente de lista encadeada que precisa percorrer toda a lista para achar o 
        // ultimo elemento
        
    }
}

void dequeue(Node **head, Node **tail){
    Node *temp = *head;
    if((*head) != NULL){
        *head = (*head)->prox;
        free(temp);
        // limpa o primeiro elemento até chegar em NULL
    }
    if(*head == NULL){
        *tail = NULL;
    }
}
// para remover somente 1 elemento, bata remover o while()

int dequeuInt(Node **head, Node **tail){
    Node *temp;
    int n = 0;
    if((*head) == NULL){
        printf("Fila vazia\n");
        return 0;
    }

    if((*head) != NULL){
        n = (*head)->numero;
        temp = *head;
        *head = (*head)->prox;
        free(temp);
        // limpa o primeiro elemento até chegar em NULL
    }
    if(*head == NULL){
        *tail = NULL;
        // agora que a lista está vazia, tail deve apontar para NULL para não acessar memória inválida
    }
        
    return n;
}

void printar(Node **head){
    Node *temp = *head;
    while(temp != NULL){
        printf("%d-> ", temp->numero);
        temp = temp->prox;
    }

    printf("NULL\n");
}

int tamanho(Node **head){
    int cont = 0;
    Node *temp = *head;

    while(temp != NULL){
        cont++;
        temp = temp->prox;
        
    }

    return cont;

}

int main(){
    Node *head = NULL;
    Node *tail = NULL;
    int num;

    while(num != 0){
        printf("Insira um numero na lista: \n");
        scanf("%d", &num);
        if(num != 0){
            enqueue(&head, &tail, num);
        }
        
    }

    printar(&head);
    int tam = tamanho(&head);
    printf("Tamanho da fila: %d\n", tam);
    int limpado = dequeuInt(&head, &tail);
    printf("fila limpa: %d\n", limpado);
    dequeue(&head, &tail);
    

    
}
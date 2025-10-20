#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int num;
    struct Node *next;

}Node;

void addfila(Node **head, Node **tail, int num){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->num = num;
        novo->next = NULL;

        if(*head == NULL){
            *head = novo;
            *tail = novo;
        }else{
            (*tail)->next = novo;
            *tail = novo;
        }
    }
    
}

void remover(Node **head, Node **tail, int valor) {
    Node *atual = *head;
    Node *anterior = NULL;

    while (atual != NULL) { // enquanto a fila não for NULL
        // percorre a fila
        if (atual->num == valor) { // se o valor atual for igual ao valor
            if (anterior == NULL) {// verifica se é o primeiro valor
                // se o valor anterior for nulo,
                // head apontará para o nó do proximo elemento atual
                *head = atual->next;
                //ex: 10 - 20 - 30 - fim
                // anterior ja começa sendo null, então entrará no if
                //atual = 10, atual->next = 20;
                // *head será 20

                if (*head == NULL) {
                    *tail = NULL; // realoca o tail caso o head seja nulo

                }
            }else { // se não for
                anterior->next = atual->next; // o nó do anterior irá apontar para o proximo nó do numero atual
                //ex 10 - 20 - 30 - fim;
                //anterior = 10, atual = 20;
                //anterior->next = 20, (se recebe atual->next, será 30):
                //anterior->next = 30;
                // e a fila passa a ser 10 - 30 - fim;
                if (atual == *tail) { // se o numero atual for o tail
                    *tail = anterior; // passa o tail para o numero anterior (para não remover o tail)
                }
            }

            Node *aux = atual->next; 
            // salva o nó para o próximo elemento (se atual = 10, atual->next = 20)
            free(atual);// libera o atual
            atual = aux; // recebe o próximo valor

        }else{
            anterior = atual; 
            // quando a comparação é falsa, anterior recebe o valor atual (passa para o próximo elemento)
            // anterior agora recebe o valor de atual, e a fila passa para o próximo
            // para realizar as comparações
            atual = atual->next;
        }
    }
}

void imprime(Node **head){
    Node *temp = *head;
    while(temp != NULL){
        printf("%d- ", temp->num);
        temp = temp->next;
    }

    printf("FIM \n");
}

void verifica(Node **head1, Node **head2, Node **tail2) {
    Node *temp1 = *head1;

    while (temp1 != NULL) { // enquanto temp1 não for NULL
        //percorre toda a fila
        remover(head2, tail2, temp1->num); // remover recebe valor = que é um elemento da fila1
        // realiza a comparação com cada elemento de temp2
        temp1 = temp1->next;
    }
}



int main(){
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *tail1 = NULL;
    Node *tail2 = NULL;

    int n, num;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        printf("insira um numero: \n");
        scanf("%d", &num);
        addfila(&head1, &tail1, num);
        
    }

    printf("fila 1: \n");
    imprime(&head1);

    for (int i = 0; i < n; i++){
        printf("insira um numero: \n");
        scanf("%d", &num);
        addfila(&head2, &tail2, num);
        
    }

    printf("fila 2: \n");
    imprime(&head2);

    verifica(&head1, &head2, &tail2);
    imprime(&head2);

}
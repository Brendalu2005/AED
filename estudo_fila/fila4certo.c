#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node *next;

}Node;

void addfila(Node **head, Node **tail, int num);
void excluirIguais(Node *head1, Node *tail1, Node **head2, Node **tail2);
void imprime(Node **head);

int main(){
    Node *head1 = NULL;
    Node *tail1 = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;

     int n, num;
    scanf("%d", &n);

    printf("Lista 1: \n");
    for (int i = 0; i < n; i++){
        printf("insira um numero: \n");
        scanf("%d", &num);
        addfila(&head1, &tail1, num);
        
    }

    printf("Lista 2: \n");
    for (int i = 0; i < n; i++){
        printf("insira um numero: \n");
        scanf("%d", &num);
        addfila(&head2, &tail2, num);
        
    }

    printf("FILA 1: \n");
    imprime(&head1);

    printf("FILA 2: \n");
    imprime(&head2);

    excluirIguais(head1, tail1, &head2, &tail2);

    printf("FILA 2 atualizada: \n");
    imprime(&head2);






}

void addfila(Node **head, Node **tail, int num){
    Node *novo = (Node*)malloc(sizeof(Node));
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
// usando a função de natacha
void excluirIguais(Node *head1, Node *tail1, Node **head2, Node **tail2){
    Node *temp1 = head1; 
    
    while(temp1 != NULL){ // percorre toda a fila1
        Node *temp2 = *head2; 
        Node *anterior = NULL; // anterior começa com NULL
        while(temp2 != NULL){ // percorre toda a fila2
            if(temp2->num == temp1->num){ // compara o elemento da fila1 com cada elemento da fila2
                if(anterior == NULL){ // verifica se o primeiro elemnto for igual
                    // se o primeiro for igual, anterior será igual a NULL
                    // anterior só recebe valor quando um elemento não entra na condição
                    *head2 = temp2->next;
                    // se for, head2 agora aponta para o próximo elemento da fila;

                    if(*head2 == NULL){ // se head2 = NULL (só um elemento na fila)
                        *tail2 = NULL;// como o elemento é removido, realoca o tail2
                    }
                }else{
                    anterior->next = temp2->next; 
                    // o anterior passa a apontar para o nó do proximo elemento
                    // apaga o nó que liga para o elemento a ser removido

                    if(temp2 == *tail2){ // se o numero igual for o tail;
                        *tail2 = anterior;
                    }

                }

                Node *aux = temp2->next; // guarda o nó do elemento atual
                // ex = temp2.num = 20, temp2.next = 30
                //guarda 30;
                free(temp2); // limpa 20
                temp2 = aux;// agora temp2 passa para a próxima posição;
                //percorre a lista

            }else{ // se não for igual
                anterior = temp2;// anterior agora recebe o valor antigo de temp2
                temp2 = temp2->next; // e temp2 passa para o proximo elemento da lista
                // e a verificação é feita novamente
            }
        }
        temp1 = temp1->next; // continua percorrendo a fila, até acabar
    }
}

void imprime(Node **head){
    Node *temp = *head;
    while(temp != NULL){
        printf("%d ->", temp->num);
        temp = temp->next;
    }
    printf("FIM \n");
}
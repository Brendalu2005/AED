#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node *next;

}Node;

void addlista(Node **head, int num);
void imprimelista(Node **head);
void excluiriguais(Node **head1, Node **head2, Node **tail2);

int main(){
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;

    int n, num;

    scanf("%d", &n);

    printf("primeira lista: \n");
    for(int i = 0; i < n; i++){
        printf("insira um valor: \n");
        scanf("%d", &num);

        addlista(&head1, num);

    }

    printf("segunda lista: \n");
    for(int i = 0; i < n; i++){
        printf("insira um valor: \n");
        scanf("%d", &num);

        addlista(&head2, num);

    }

    printf("L1: \n");
    imprimelista(&head1);
    printf("L2: \n");
    imprimelista(&head2);

    excluiriguais(&head1, &head2, &tail2);
    printf("Nova L2: \n");
    imprimelista(&head2);



}

void addlista(Node **head, int num){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->num = num;
    novo->next = NULL;

    if(*head == NULL){
        novo->next = *head;
        *head = novo;
    }else{
        Node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;

        }

        novo->next = temp->next;
        temp->next = novo;
    }
}

void imprimelista(Node **head){
    Node *temp = *head;
    while(temp != NULL){
        printf("%d ->", temp->num);
        temp = temp->next;
    }

    printf("FIM\n");
}

void excluiriguais(Node **head1, Node **head2, Node **tail2){
    Node *temp1 = *head1;
    
    while(temp1 != NULL){
        Node *temp2 = *head2;
        Node *anterior = NULL;
        while(temp2 != NULL){
            if(temp1->num == temp2->num){
                if(anterior == NULL){ // se o primeiro elemento for igual;
                    *head2 = temp2->next; // o head passa a ser o próximo elemento
                     if(*head2 == NULL){
                        *tail2 = NULL;
                    }
                }else{
                    anterior->next = temp2->next; 
                }
                //se o anterior não é nulo, passa a apontar para o próximo valor de temp2
                // apaga o nó do elemento removido
                if(temp2->next == *tail2){ // verifica se foi o ultimo
                    // se o item igual for o tail 
                    // o tail passa a ser o valor anterior
                    *tail2 = anterior;
                }
                

                Node *aux = temp2->next; // pega o proximo valor
                free(temp2); // limpa temp2 atual
                temp2 = aux; // temp2 passa para o próximo valor

            }else{ // se não for igual
                anterior = temp2; // passa o antigo valor de temp2
                temp2 = temp2->next; // continua percorrendo
            }

        }

        temp1 = temp1->next;
    }
}
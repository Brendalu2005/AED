#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node *next;
}Node;

void addFila(Node **head, Node **tail, int num);
void imprimeFila(Node **head);
void doubleFila(int delimitador, Node **head, Node **tail, Node **novoHead1, Node **novoTail1, Node **novoHead2, Node **novoTail2);


int main(){
Node *head = NULL;
Node *tail = NULL;
Node *novoHead1 = NULL;
Node *novoTail1 = NULL;
Node *novoHead2 = NULL;
Node *novoTail2 = NULL;

int n, num, delimitador;
scanf("%d", &n);

for(int i = 0; i < n; i++){
    printf("insira um elemento na lista: \n");
    scanf("%d", &num);

    addFila(&head, &tail, num);
}

printf("FILA: \n");
imprimeFila(&head);

printf("Insira um valor para ser o delimitador das novas filas: \n");
scanf("%d", &delimitador);
doubleFila(delimitador, &head, &tail, &novoHead1, &novoTail1, &novoHead2, &novoTail2);

printf("FILA 1: \n");
imprimeFila(&novoHead1);
printf("FILA 2: \n");
imprimeFila(&novoHead2);



}

void addFila(Node **head, Node **tail, int num){
    Node *novo =(Node*)malloc(sizeof(Node));
    novo->num = num;
    novo->next = NULL;

    if(*head == NULL){
        *head = novo;
        *tail = novo;
    }else{
        (*tail)->next = novo; // tail aponta para o novo nó
        *tail = novo; // o novo elemento é o tail
    }
}

void imprimeFila(Node **head){
    Node *temp = *head;
    while(temp != NULL){
        printf("%d ->", temp->num);
        temp = temp->next;
    }

    printf("FIM\n");
}

void doubleFila(int delimitador, Node **head, Node **tail, Node **novoHead1, Node **novoTail1, Node **novoHead2, Node **novoTail2){
    Node *temp = *head;
    int achou = 0;
    int cont = 0;

    if(*head == NULL){
        *tail = NULL;
    }
    
    while(temp != NULL){
        if(temp->num == delimitador){// marca o inicio da segunda fila
            achou = 1; // verifica se existe um delimitador
            
        }
        temp = temp->next;
        cont++;

    }

    if(achou){ // garante que achou mesmo o delimitador e não preenche novoHead1 duas vezes
        Node *temp2 = *head;
        int limite = 0;
        while(temp2 != NULL){
            if(temp2->num == delimitador){ // encontra o delimitador
                limite = 1;
            }

            if(limite){
                addFila(novoHead2, novoTail2, temp2->num);
                // insere os elementos da segunda fila depois de encontrar o delimitador

            }else{
                addFila(novoHead1, novoTail1, temp2->num);
                // enquanto não achar o delimitador, vai adicionar na primeira fila

            } 
            temp2 = temp2->next;
        }

    }else{
        if(cont % 2 == 0){ // se a quantidade de elementos são pares
           Node *aux2 = *head;
           int i = 0;
            while (aux2 != NULL){ //divide as filas igualmente
                if(i < cont/2){ 
                    addFila(novoHead1, novoTail1, aux2->num);

                }else{
                    addFila(novoHead2, novoTail2, aux2->num);

                }

                aux2 = aux2->next;
                i++;
            }
           
        }else{ //se for impar
            Node *aux3 = *head;
            int j = 0;
            while(aux3 != NULL){
                if(j < (cont/2)+1){// cont/2 + 1 para pegar um elemento a mais
                    addFila(novoHead1, novoTail1, aux3->num);

                }else{
                    addFila(novoHead2, novoTail2, aux3->num); // a fila1 fica com um par extra
                }

                aux3 = aux3->next;
                j++;
            }
        }
    }
}
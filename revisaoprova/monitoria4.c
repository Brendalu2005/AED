#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
}Node;

void addFinal(Node **head, Node **tail, int valor);
void multiplicacao(Node *head, Node *tail);

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    for(int i = 0; i < 8; i++){
        addFinal(&head, &tail, arr[i]);
    }

    multiplicacao(head, tail);

}

void addFinal(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;

        if(*head == NULL){
            *head = novo;
            *tail = novo;
            novo->prox = novo;
        }else{
            novo->prox = *head;
            (*tail)->prox = novo;
            *tail = novo;
        }
    }
}

void multiplicacao(Node *head, Node *tail){
    if(head != NULL){
        Node *temp2 = head;
       
        while(temp2 != tail){
            //temp2 != tail para permitir que pegue o valor atual e o proximo
            // se chegar em tail, não consegue pegar o proximo valor (repitido)
            int resultado = temp2->valor * temp2->prox->valor;
            printf("%d - ", resultado);
            temp2 = temp2->prox->prox; // passa de dois em dois 
            //evita duplicação de multiplicações

            if(temp2 == head){
                break;
            } 
            // em caso da lista ser par, evita que se mantenha em loop
            // caso temp->prox->prox acesse head -. chegou ao fim, quebra a lista

        }

        
        if(temp2 == tail){ // caso seja par, temp = head, então não acessa o loop
            // se temp == tail -> chegou no ultimo elemento que sobrou
            int resultado = tail->valor * tail->valor;
            printf("%d - ", resultado);
            
        }
        printf("FIM\n");
    }
}
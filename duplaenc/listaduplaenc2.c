#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 
    int valor; 
    struct Node *prox; 
    struct Node *ant; 
} Node;

void inserir(Node **head, int valor);
void imprimir(Node **head);
void imprimirInverso(Node **head);
void remover(Node **head);

int main(){

}

void inserirFinalsemTail(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->prox = NULL; //novo será o último → prox == NULL
    

        if(*head == NULL){
            // lista vazia: novo é o único nó (head)
            *head = novo;
            novo->ant = NULL;

        }else{
            Node *temp = *head;
            while(temp->prox != NULL){ // percorre até o ultimo
                temp = temp->prox;

            }
            
            novo->ant = temp; //define o ant do novo nó como o antigo último.
            temp->prox = novo; //liga o ultimo no para o novo
            


        }
    }
}

void inserirFinalcomTail(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->prox = NULL; // aponta para nulo
        

        if(*head == NULL){ // se a lista está vazia
            *head= novo;
            *tail = novo;
            novo->ant = NULL;
            // tail e head receberao o mesmo elemento

        }else{ // se não
           (*tail)->prox = novo; // o utimo elemento aponta para o novo
           novo->ant = *tail; // aponta para o ultimo
           *tail = novo; // o novo elemento passa a ser o ultimo
        }

        
    }
}

void addInicio(Node **head, Node **tail, int valor){
    Node *novo =(Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->prox = *head; // o proximo nó aponta para o head
        novo->ant = NULL; // o anterior aponta para nulo

        if(*head == NULL){
            *head = novo;
            *tail = novo;

        }else{
            (*head)->ant = novo;
            *head = novo;

        }
    }
}

void removerFinal(Node **head){
    if(*head != NULL){
        Node *temp = *head;

        if(temp->prox == NULL){ // verifica se só possui um elemento na lista
            free(temp);
            *head = NULL;

        }else{
            while(temp->prox != NULL){
                temp = temp->prox;

            }
            temp->ant->prox = NULL; // ajusta o ponteiro
            free(temp);
           
        }   
    }
}

void removerFinalcomTail(Node **head, Node **tail){
    Node *temp = *tail; // pega o ultimo 

    if(*head == *tail){ // se só tiver um elemento
        free(temp);
        *head = NULL;
        *tail = NULL;

    }else{
        *tail = temp->ant; // penultimo vira o ultimo
        (*tail)->prox = NULL; // o ultimo aponta para NULL
        free(temp); // libera
           
    }   
}






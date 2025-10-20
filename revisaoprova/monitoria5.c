#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
    struct Node *ant;
}Node;

void addInicio(Node **head, Node **tail, int valor);
void addFinal(Node **head, Node **tail, int valor);
void addPosEsp(Node **head, Node **tail, int valor, int op);
void removeInicio(Node **head, Node **tail);
void removeFinal(Node **head, Node **tail);
void removePosEsp(Node **h0ead, Node **tail, int op);
void imprimir(Node *head);


int main(){
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *tail1 = NULL;
    Node *tail2 = NULL;

    int op, op2, num, v[6] = {1, 2, 3, 4, 5, 6};

    for(int i = 0; i < 6; i++){
        addInicio(&head1, &tail1, v[i]);
        addFinal(&head2, &tail2, v[i]);
    }

    imprimir(head1);
    imprimir(head2);


    printf("Insira uma posicao especifica para add: \n");
    scanf("%d", &op);
    printf("insira um numero: \n");
    scanf("%d", &num);

    addPosEsp(&head2, &tail2, num, op);
    imprimir(head2);
    
    printf("REMOVE: \n");
    removeInicio(&head1, &tail1);
    imprimir(head1);
    removeFinal(&head2, &tail2);
    imprimir(head2);

    printf("insira posicao para remover numa pos especifica: \n");
    scanf("%d", &op2);
    removePosEsp(&head2, &tail2, op2);

    imprimir(head2);


}

void imprimir(Node *head){
    if(head != NULL){
        Node *temp = head;
        do{
            printf("%d -> ", temp->valor);
            temp = temp->prox;

        }while(temp != head);
        printf("FIM\n");
    }
}

void addInicio(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        
        if(*head == NULL){
            *head = novo;
            *tail = novo;
            novo->prox = novo;
            novo->ant = novo;
        }else{

            novo->prox = *head;
            novo->ant = *tail;
            (*tail)->prox = novo;
            (*head)->ant = novo;
            *head = novo;
        }
    }
}


void addFinal(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        
        if(*head == NULL){
            *head = novo;
            *tail = novo;
            novo->prox = novo;
            novo->ant = novo;
        }else{

            novo->prox = *head;
            novo->ant = *tail;
            (*tail)->prox = novo;
            (*head)->ant = novo;
            *tail = novo;
        }
    }
}

void addPosEsp(Node **head, Node **tail, int valor, int op){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;

        if(*head == NULL){
            *head = novo;
            *tail = novo;
            novo->prox = novo;
            novo->ant = novo;

        }else{
            if(op == 0){
                novo->prox = *head;
                novo->ant = *tail;
                (*head)->ant = novo;
                (*tail)->prox = novo;
                *head = novo;

            }else{
                Node *temp = *head;
                int i = 0;
                while(temp->prox != *head && i < op-1){
                    temp = temp->prox;
                    i++;
                }

                novo->prox = temp->prox;
                novo->ant = temp;
                temp->prox->ant = novo;
                temp->prox = novo;

                if(temp == *tail){ 
                    // não precisa realocar novamente, pois ja chega na ultima opção com o while
                    *tail = novo;

                }
            }
        }
    }
}


void removeInicio(Node **head, Node **tail){
    if(*head == NULL){
        *tail = NULL;

    }else{
        if(*head == *tail){
            *head = NULL;
            *tail = NULL;
            

        }else{
            Node *remover = *head;
            *head = (*head)->prox;
            (*head)->ant = *tail;
            (*tail)->prox = *head;
            free(remover);
        }
    }
}

void removeFinal(Node **head, Node **tail){
    if(*head == NULL){
        *tail = NULL;

    }else{
        if(*head == *tail){
            *head = NULL;
            *tail = NULL;

        }else{
            Node *remover = *tail;
            *tail = (*tail)->ant;
            (*head)->ant = *tail;
            (*tail)->prox = *head;
            free(remover);

        }
    }
}

void removePosEsp(Node **head, Node **tail, int op){
    if(*head == NULL){
        *tail = NULL;
    }else{
        if(*head == *tail){
            *head = NULL;
            *tail = NULL;

        }else{
            if(op == 0){
                Node *aux = *head;
                *head = (*head)->prox;
                (*head)->ant = *tail;
                (*tail)->prox = *head;
                free(aux);

            }else{
                Node *aux2 = *head;
                int i = 0;
                while(aux2->prox != *head && i < op-1){
                    aux2 = aux2->prox;
                    i++;

                } // para um nó antes

                Node *remover = aux2->prox; //guarda o proximo nó (que deve ser apagado)
                aux2->prox = remover->prox; // ajusta o nó do numero anterior para o prox do prox
                remover->prox->ant = aux2; // o proximo, agora aponta para o anterior (qu epegou no while)

                if(aux2 == *tail){
                    *tail = aux2; // se o nó removido era o tail, atualiza

                }
                free(remover);
            }
        }
    }
}

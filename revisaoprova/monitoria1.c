#include <stdio.h>
#include <stdlib.h>

// lista duplamente encadeada
// sem tail

typedef struct Node{
    int valor;
    struct Node *prox;
    struct Node *ant;
}Node;

void addInicio(Node **head, int valor);
void addFinal(Node **head, int valor);
void addPosEspecifica (Node **head, int valor, int op);
void removeInicio (Node **head);
void removeNoFinal (Node **head);
void removePosEspecifica (Node **head, int op);
void imprimir (Node *head);
void imprimirInverso (Node *head);

int main(){
    Node *head1 = NULL;
    Node *head2 = NULL;

    int op, op2, num, v[6] = {1, 2, 3, 4, 5, 6};

    for(int i = 0; i < 6; i++){
        addInicio(&head1, v[i]);
        addFinal(&head2, v[i]);
    }

    imprimir(head1);
    imprimir(head2);

    printf("INVERSO: \n");
    imprimirInverso(head2);

    printf("Insira uma posicao especifica para add: \n");
    scanf("%d", &op);
    printf("insira um numero: \n");
    scanf("%d", &num);

    addPosEspecifica(&head2, num, op);
    imprimir(head2);
    
    printf("REMOVE: \n");
    removeInicio(&head1);
    imprimir(head1);
    removeNoFinal(&head2);
    imprimir(head2);

    printf("insira posicao para remover numa pos especifica: \n");
    scanf("%d", &op2);
    removePosEspecifica(&head2, op2);

    imprimir(head2);


}


void addInicio(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->prox = *head; // aponta pro inicio
        //para não perder a lista original

        if(*head == NULL){
            *head = novo;
            novo->ant = NULL; // não faz ligação com o head diretamente

        }else{

            (*head)->ant = novo; // aponta pro novo, porque o novo inserido sempre será o head
            // o novo anterior aponta pro novo elemento
            *head = novo;
            // o novo elemento é o head

        }
    }
}

void addFinal(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->prox = NULL;

        if(*head == NULL){
            *head = novo;
            novo->ant = NULL;
        }else{
            Node *temp = *head;
            while(temp->prox != NULL){
                temp = temp->prox; 
            }
            // temp é o ultimo elemento

            novo->ant = temp; // o novo anterior aponta para o antigo ultimo elemento da lista
            temp->prox = novo; // o antigo ultimo agora aponta para o novo elemento (que vira o ultimo)

        }
    }
}

void addPosEspecifica (Node **head, int valor, int op){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->prox = NULL;

        if(*head == NULL){
            *head = novo;
            novo->ant = NULL;

        }else{

            if(op == 0){
                novo->prox = *head; // ligar o novo elemento com o head antigo
                (*head)->ant = novo; // o anterior ao head antigo é o novo
                *head = novo; // novo é o head

            }else{
                Node *temp = *head;
                for( int i = 0; i < op-1 && temp->prox != NULL; i++){
                    // op-1, para antes da posição que queremos inserir
                    temp = temp->prox; 
                }

                novo->prox = temp->prox; // liga o novo elemento com o proximo elemento na lista
                novo->ant = temp; // o anterior do novo elemento aponta para o elemento atual de temp

                if(temp->prox != NULL){
                    temp->prox->ant = novo;
                    // "anterior do nó seguinte"
                    //liga o nó que vinha depois de temp → para trás para o novo adicionado.
                    //O nó que vinha depois de temp agora deve apontar para trás para o novo.
                }

                temp->prox = novo;
                // o nó anterior ao novo, aponta para o novo

            }
        }
    }
}


void removeInicio (Node **head){
    if(*head != NULL){
        Node *temp = *head;
        *head = (*head)->prox;
        free(temp);

        // passa o head para o proximo elemento, 
        //mas o ant do novo head ainda aponta para o head antigo

        if(*head != NULL){
            (*head)->ant = NULL; // zera o ant do novo primeiro valor
        }
    }
}


void removeNoFinal (Node **head){
    if(*head != NULL){
        Node *temp = *head;

        if(temp->prox == NULL){ // só há um elemento na lista
            free(temp);
            *head = NULL;

        }else{
            while(temp->prox != NULL){
                temp = temp->prox; // para no ultimo elemento
            }

            // quando limpar o ultimo elemento, precisa realocar o nó do anterior
            // senão, o anterior (penultimo), vai seguir apontando para o ultimo nó deletado

            temp->ant->prox = NULL; 
            // "o próximo do nó anterior"
            // realoca para o proximo do anterior apontar para null
            // e não para o ultimo valor
            free(temp); 
        }

    }
}


void removePosEspecifica (Node **head, int op){
    if(*head != NULL){
        Node *temp = *head;

        if(op == 0){
            *head = (*head)->prox;
            free(temp);

            if(*head != NULL){
                (*head)->ant = NULL;

            }

            // igual para remover no inicio
        }else{

            for(int i = 0; i < op && temp != NULL; i++){
                temp = temp->prox; // percorre até o ultimo elemento
                // Se usa op-1, remove temp->prox.
            }

            if(temp != NULL){ // se chegou em op, mas temp != NULL
                if(temp->ant != NULL){
                    temp->ant->prox = temp->prox; // realoca o proximo do anterios

                }

                if(temp->prox != NULL){
                    temp->prox->ant = temp->ant; // realoca o anterior do proximo

                }

                //realiza a realocação para evitar que acessem os nós do elemento apagado

                free(temp);
            }
        }
    }
}

void imprimir (Node *head){
    if (head != NULL){
        Node *temp = head;

        while(temp != NULL){
            printf("%d -> ", temp->valor);
            temp = temp->prox;
        }

        printf("NULL\n");
    }
}

void imprimirInverso (Node *head){
    if (head != NULL){
        Node *temp = head;

        while( temp->prox != NULL){ // evita acessar NULL
            temp = temp->prox;
        }

        while(temp != NULL){ // percorre até o ultimo elemento
            printf("%d -> ", temp->valor);
            temp = temp->ant;

        }
        printf("NULL\n");
    }
}
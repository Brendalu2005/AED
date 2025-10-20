#include <stdio.h>
#include <stdlib.h>
#define LEN 5

typedef struct Node{ 
    int valor; 
    struct Node *prox; 
    struct Node *ant; 
} Node;
void inserirOrdenado(Node **head, int valor);
void alternado(Node **head1, Node **head2, Node **headFinal);
void quantidadeElementos(Node **head, int valor);
void imprimir(Node **head);
void inserirFinal(Node **head, int valor);

int main(){
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head3 = NULL;
    Node *headFinal = NULL;
    int op;

    int arr1[LEN] = {2, 3, 4, 5, 1};
    int arr2[LEN] = { 30, 40, 50, 10, 20};
    int arr3[LEN] = {60, 80, 90, 70, 100};

    for (int i = 0; i < LEN; i++){
        inserirOrdenado(&head1, arr1[i]);
        inserirFinal(&head2, arr2[i]);
        inserirFinal(&head3, arr3[i]);
    }

    alternado(&head2, &head3, &headFinal);

    printf("insira um numero do arr2 para encontrar: \n");
    scanf("%d", &op);
    quantidadeElementos(&head2, op);

    imprimir(&head1);
    imprimir(&headFinal);
}


void inserirOrdenado(Node **head, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->prox = NULL;
        
        if(*head == NULL){
            *head = novo;
            novo->ant = NULL;

        }else{
            Node *temp = *head;

            
            if(valor < temp->valor){ // insere no inicio
                // se valor for menor que os elementos da lista
                novo->prox = temp;
                temp->ant = novo;
                *head = novo;
               
            }

            while(temp->prox != NULL && temp->prox->valor < valor){ 
                // enquanto o valor do proximo nó for menor que o valor
                temp = temp->prox;
            }

            // agora temp é o nó "antes" do novo
            novo->prox = temp->prox;
            novo->ant = temp; // insere no fim normal
            if(temp->prox != NULL){ // se não é nulo, não estamos inserindo no final
                //faz o anterior apontar de volta para novo
                temp->prox->ant = novo; // ajusta ponteiro do próximo
            }
            temp->prox = novo; //aponta o antigo proximon para novo

        }
    }
}

// void inseririnicio(Node **head, int valor){
//     Node *novo = (Node*)malloc(sizeof(Node));
//     if(novo != NULL){
//         novo->valor = valor;
//         novo->prox = *head;

//         if(*head != NULL){
//             (*head)->ant = novo;
//             novo->ant = NULL;

//         }
//         *head = novo;
//     }
// }



void alternado(Node **head1, Node **head2, Node **headFinal){
    Node *temp1 = *head1;
    Node *temp2 = *head2;
    while(temp1 != NULL || temp2 != NULL){

        if(temp1 != NULL){
            inserirFinal(headFinal, temp1->valor);
            temp1 = temp1->prox;
        }

        if(temp2 != NULL){
            inserirFinal(headFinal, temp2->valor);
            temp2 = temp2->prox;
        }
    }
}

void quantidadeElementos(Node **head, int valor){
    Node *temp1 = *head;
    int achou = 0;
    int dps = 0;
    int ant = 0;
    
    while(temp1 != NULL){
        if(temp1->valor == valor){
            achou = 1;

        }
        if(achou){
            dps++;

        }
        temp1 = temp1->prox;
        
    }

    if(achou){
        Node *temp2 = *head;
        
        while(temp2 != NULL && temp2->valor != valor){
            temp2 = temp2->prox;
            
        }

        Node *temp3 = temp2->ant; 
        // começa do elemento anterior ao elemento em q temp2 parou
        while(temp3 != NULL){
            temp3 = temp3->ant;
            ant++;

        }
    }

    // Node *aux = *head;
    // while(aux != NULL && aux->valor != valor){
    //     aux = aux->prox;
    // }

    // if(aux != NULL){
    //     Node *auxAntes = aux;
    //     while(auxAntes->ant != NULL){
    //         contAntes++;
    //         auxAntes = auxAntes->ant;
    //     }

    //     while(aux->prox != NULL){
    //         contDepois++;
    //         aux = aux->prox;
    //     }
    // }

    printf("Anterior: %d\n", ant);
    printf("Posterior: %d\n", dps - 1); //menos o proprio nó

}

void inserirFinal(Node **head, int valor){
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
            while(temp->prox != NULL){ // percorre até o penultimo
                temp = temp->prox;

            }
            
            novo->ant = temp; //define o ant do novo nó como o antigo último.
            temp->prox = novo; //liga o ultimo no para o novo
            


        }
    }
}

void imprimir(Node **head){
    if(*head != NULL){
        Node *temp = *head;
        while(temp != NULL){
            printf("%d ->", temp->valor);
            temp = temp->prox;

        }
        printf("FIM\n");
    }
}
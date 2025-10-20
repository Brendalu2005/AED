#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int valor;
    struct Node *prox;
    struct Node *ant;
}Node;

void inserirAposValor(Node **head, int valorReferencia, int novoValor);
void addFinal(Node **head, int valor);
void imprimir(Node *head);

int main(){
    Node *head = NULL;
    
    int valoref, valoradd, arr[6] = {1, 2, 3, 4, 5, 6};

    for(int i = 0; i < 6; i++){
        addFinal(&head, arr[i]);
    }

    imprimir(head);

    printf("insira um valor de ref: \n");
    scanf("%d", &valoref);

    printf("insira o valor que quer adicionar: \n");
    scanf("%d", &valoradd);

    inserirAposValor(&head, valoref, valoradd);

    imprimir(head);

    

}

void imprimir(Node *head){
    if(head != NULL){
        Node *temp = head;
        while(temp != NULL){
            printf("%d -> ", temp->valor);
            temp = temp->prox;
        }
        printf("FIM\n");
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
                temp = temp->prox; // para no ultimo
            }

            temp->prox = novo; // o ultimo aponta para novo ao invés de NULL
            novo->ant = temp; // o novo anterior agora é o antigo ultimo
            
        }
    }
}

void inserirAposValor(Node **head, int valorReferencia, int novoValor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = novoValor;
        
        if(*head == NULL){
            printf("Lista vazia\n");

        }else{
            Node *temp = *head;
            int achou = 0;

            while(temp != NULL){ 
                //se a verificação for com temp->prox, nunca vai realizar a verificação, pois o loop para
                if(temp->valor == valorReferencia){
                    achou = 1;
                    break;

                }
                temp = temp->prox;
            }

            if(achou){
                novo->prox = temp->prox;
                novo->ant = temp;

                if(temp->prox != NULL){
                    temp->prox->ant = novo; // realoca o anterior do proximo nó para ligar ao novo
                    //se não realocar, o anterior vai apontar para outro numero, sem ser o novo
                }
                temp->prox = novo;

            }else{
                printf("valor referencia nao existe na lista\n");
            }
        }
       
    }
}


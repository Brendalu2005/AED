#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *prox;
    struct Node *ant;

}Node;

void removerDuplicados(Node **head);
void addFinal(Node **head, int valor);
void imprimir(Node *head);
int main(){
    Node *head = NULL;

    int arr[6] = {1, 2, 2, 3, 4, 3};

    for(int i = 0; i < 6; i++){
        addFinal(&head, arr[i]);
    }

    imprimir(head);
    removerDuplicados(&head);
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
                temp = temp->prox;
            }

            temp->prox = novo; // so precisa ligar o anterior prox ao  novo
            novo->ant = temp;// so precisa ligar o novo ant ao anterior (temp)
        }
    }
}

void removerDuplicados(Node **head){
    if(*head != NULL){
        Node *temp = *head;

        while(temp->prox != NULL){
            temp = temp->prox;
        }


        Node *inicio = *head;
        int removeu = 0;

        while(inicio != NULL){
            Node *fim = temp;
            while(fim != NULL && fim != inicio){
                if(inicio->valor == fim->valor){
                    Node *remover = fim; 
                    fim = fim->ant; // passa para o proximo antes de remover
                    //precisa religar os nós do valor que será removido
                    if(remover->ant != NULL){ // verificar se é diferente de nulo para alocar
                        remover->ant->prox = remover->prox;
                        // o proximo do anterior, agora aponta para o prox de remover
                       
                    }
                    if(remover->prox != NULL){ 
                        remover->prox->ant = remover->ant;
                        // o anterior do proximo agora aponta para o ant de remover
                    }

                    if(*head == remover){
                        *head = remover->prox;
                    }
                    free(remover);
                    removeu = 1;


                }else{
                    fim = fim->ant;
                }
            }    
           inicio = inicio->prox;   
        }

        if(!removeu){
            printf("nehuma remocao foi necessaria\n");
        }
    }
}

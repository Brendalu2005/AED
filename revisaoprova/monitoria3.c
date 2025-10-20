#include <stdio.h>
#include <stdlib.h>

// lista circular simples

typedef struct Node{
    int valor;
    struct Node *prox;

}Node;

void addInicio(Node **head, Node **tail, int valor);
void addFinal (Node **head, Node **tail, int valor);
void addPosEsp(Node **head, Node **tail, int valor, int op);
void removerInicio (Node **head, Node **tail);
void removerFinal(Node **head, Node **tail);
void removerPosEsp(Node **head, Node **tail, int op);
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
    removerInicio(&head1, &tail1);
    imprimir(head1);
    removerFinal(&head2, &tail2);
    imprimir(head2);

    printf("insira posicao para remover numa pos especifica: \n");
    scanf("%d", &op2);
    removerPosEsp(&head2, &tail2, op2);

    imprimir(head2);

}

void imprimir(Node *head){
    if(head != NULL){
        Node *temp = head;

        do{
            printf("%d -> ", temp->valor);
            temp = temp->prox;

        }while(temp != head);

        printf("NULL\n");
    }
}

void addInicio(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    // liga somente o tail no head
    if(novo != NULL){
        novo->valor = valor;
        
        if(*head == NULL){
            *head = novo;
            *tail = novo;
            novo->prox = novo;

        }else{
            novo->prox = *head; // proximo inserido aponta pro head antigo
            (*tail)->prox = novo; // o antigo ultimo agora aponta para o novo ultimo (head)
            *head = novo; // o novo agora é o head

        }

    }
}

void addFinal (Node **head, Node **tail, int valor){
    Node *novo =(Node*)malloc(sizeof(Node));
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

void addPosEsp(Node **head, Node **tail, int valor, int op){
    Node *novo =(Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        
        if(*head == NULL){
            *head = novo;
            *tail = novo;
            novo->prox = novo;

        }else{
            if(op == 0){
                novo->prox = *head;
                *head = novo;
                (*tail)->prox = *head;

            }else{
                Node *temp = *head;
                for (int i = 0; i < op-1 && temp->prox != *head; i++){
                    temp = temp->prox; // para um elemento antes
                }

                novo->prox = temp->prox; // o novo agora aponta para o proximo elemento
                temp->prox = novo; // o proximo no do elemento que parou (no for) aponta para o novo

                if(temp->prox == *tail){
                    temp->prox = novo;
                    novo->prox = *head;
                    *tail = novo;
                }
                
            }
        }
    }
}


void removerInicio (Node **head, Node **tail){
    if(*head == NULL){
        *tail = NULL;
        
    }else{
        Node *temp = *head;
       if(*head == *tail){ // so tem 1 elemento
        *head = NULL;
        *tail = NULL;
       }

       *head = (*head)->prox;
       (*tail)->prox = *head;
       free(temp);
       
    }
}


void removerFinal(Node **head, Node **tail){
    if(*head == NULL){
        *tail = NULL;

    }else{
        Node *temp = *head;
        if(*head == *tail){
            *head = NULL;
            *tail = NULL;

        }

        while(temp->prox != *tail){ // para um antes do tail (entao libera temp->prox)
            temp = temp->prox;

        }

        *tail = temp;
        free(temp->prox);
        (*tail)->prox = *head; //atualiza o novo tail

    }
}

void removerPosEsp(Node **head, Node **tail, int op){
    if(*head != NULL){
        if(*head == *tail){
            *head = NULL;
            *tail = NULL;
            
        }else{

            if(op == 0){
                Node *remover = *head;
                *head = (*head)->prox;
                (*tail)->prox = *head;
                free(remover);
            }

            Node *temp = *head;
            for(int i = 0; i < op-1 && temp->prox != *head; i++){
                temp = temp->prox;
            }

            Node *remover = temp->prox;

            if(remover == *tail){
                *tail = temp; // passa o tail para o elemento anterior 
                
            }

            temp->prox = remover->prox; //conecta as ligações após remover
            // já está ligando o tail no head
            //(*tail)->prox = *head; 
            free(remover);
        }
    }
}




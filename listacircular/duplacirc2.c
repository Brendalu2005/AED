#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int valor;
    struct Node *prox;
    struct Node *ant;

} Node;
void addFinal(Node **head, Node **tail, int valor);
void imprimir(Node **head);
void addPosicaoEsp(Node **head, Node **tail, int valor, int op);

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    int op, num;
    int arr[5];
    
    
    for (int i = 1; i < 5+1; i++){
        printf("insira um numero: \n");
        scanf("%d", &arr[i]);
        addFinal(&head, &tail, arr[i]);

    }

    imprimir(&head);

    printf("Insira uma posição para inserir um valor específico: \n");
    scanf("%d", &op);

    printf("insira um numero: \n");
    scanf("%d", &num);

    addPosicaoEsp(&head, &tail, num, op);

    imprimir(&head);




}
void imprimir(Node **head){
    if(*head != NULL){
        Node *temp = *head;
        do{
            printf("%d -> ", temp->valor);
            temp = temp->prox;

        }while(temp != *head);
        printf("NULL \n");
    }
}

void addFinal(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->valor = valor;
        novo->ant = NULL;

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

void addPosicaoEsp(Node **head, Node **tail, int valor, int op){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo!= NULL){
        novo->valor = valor;
        novo->ant = NULL;

        if(*head == NULL){
            *head = novo;
            *tail = novo;
            novo->prox = novo;
            novo->ant = novo;
        }else{

            if(op == 1){
                novo->prox = *head; // aponta para o antigo primeiro
                novo->ant = *tail; // aponta para o ultimo
                (*head)->ant = novo; // o anterior do antigo head aponta para o novo
                (*tail)->prox = novo; // o proximo do tail agora é o novo 
                *head = novo; // head agora é o novo
            }

            Node *temp = *head;
            for(int i = 1; i < op-1 && temp->prox != *head; i++){ 
                // op - 1 para pegar o nó anterior
                // para no penultimo caso chegue ao final
                temp = temp->prox;
                
            }
            // se op for maior que a quantidade de itens, o for continua percorrendo até chegar no ultimo elemento
            // assim, garante que o elemento seja adicionado no final caso tente acessar um indice inexistente
            if(temp == *tail){ // se inseriu no fim
                novo->prox = *head;
                novo->ant = *tail;
                (*tail)->prox = novo;
                (*head)->ant = novo;
                *tail = novo;

            }else{
            novo->prox = temp->prox; // liga temp e novo
            novo->ant = temp; // o anterior ao novo vai ser o temp em q parou
            temp->prox->ant = novo; // pega a posição atual e passa o novo
            temp->prox = novo; // temp prox de onde parou, agora aponta para o novo

            
            } 
        }
    }
}
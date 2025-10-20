#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int num;
    struct Node *next;

}Node; 

void addfila(Node **head, Node **tail, int num);
void divisao(Node **head, Node **tail);
void imprimir(Node **head);

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    int tam, num;
    printf("de o taamnho da fila: \n");
    scanf("%d", &tam);

    for (int i = 0; i < tam; i++){
        printf("insira um numero: \n");
        scanf("%d", &num);
        addfila(&head, &tail, num);
        
    }

    divisao(&head, &tail);

}

void addfila(Node **head, Node **tail, int num){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->num = num;
    novo->next = NULL;

    if(*head == NULL){
        *head = novo;
        *tail = novo;

    }else{
        (*tail)->next = novo;
        *tail = novo;
    }
}

void imprimir(Node **head){
    Node *temp = *head;
    while(temp != NULL){
        printf("%d ->", temp->num);
        temp = temp->next;
    }
    printf("FIM \n"); 
}

void divisao(Node **head, Node **tail){
    Node *temp = *head;
    int cont = 0;
    int resultado;

    // primeiro verifica se a lista é vazia
    if(*head == NULL || (*head)->next == NULL){ // verifica se a lista é vazia ou tem 1 elemento
        printf("Tamanho da fila é insuficiente :( \n");
        *tail = NULL;
    }
    
    while(temp != NULL){ // percorre toda a lista
        if(temp->next != NULL && cont % 2 == 0){ 
            // enquanto o proximo nó for diferente de NULL (fim da fila)
            // e enquanto cont por par
            if(temp->next->num != 0){
                // se o numero do proximo nó for diferente de zero
                resultado = temp->num / temp->next->num; 
                printf(" %d / %d = %d\n", temp->num, temp->next->num, resultado);

            }else{ // se for igual a zero, não permite
                printf("divisão por zero não permitida! \n");
            }
        }

        temp = temp->next; // continua percorrendo a lista
        cont++; // incrementa o contador
        // conta quantos elementos tem
        // como sempre incrementa no final, vai parar o loop quando der um valor negativo

    }
    // se for impar, o loop para
    if(cont % 2 != 0 && *tail != NULL){ 
        //se o cont for diferente de zero, e o tail não for nulo
        resultado = (*tail)->num/10; // pega o ultimo valor e divide po 10
        printf("%d / 10 = %d\n", (*tail)->num, resultado);

    }
}

    

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char nome[50];
    int num;
    struct Node *next;

}Node;

int cont = 0;

void addfim(Node **head, char nome[50], int num){
    Node *novo = (Node*)malloc(sizeof(Node));
    strcpy(novo->nome, nome);
    novo->num = num;
    novo->next = NULL;

    if(*head == NULL){
        novo->next = *head;
        *head = novo;
        
        
    }else{
        Node *temp = *head;
        while(temp->next != NULL){ // enquanto o proximo nó não apontar para null
            temp = temp->next;
        }
        novo->next = temp->next; // quando apontar para null, vai receber o novo nó
        temp->next = novo;

    }
   
}

void addinicio(Node **head, char nome[50], int num){
    Node *novo = (Node*)malloc(sizeof(Node));
    strcpy(novo->nome, nome);
    novo->num = num;
    novo->next = NULL;
    
    novo->next = *head;
    *head = novo;
}

void addmeio(Node **head, char nome[50], int num){
    Node *novo = (Node*)malloc(sizeof(Node));
    strcpy(novo->nome, nome);
    novo->num = num;
    novo->next = NULL;

    if(*head == NULL){ // impede que o for acesse indices negativos
        novo->next = *head;
        *head = novo;
        cont++; // evitar q o for percorra a lista com cont = 0
    }else{
        Node *temp = *head;
        
        for (int i = 0; i < cont/2 - 1; i++){  // inicio, condição, incremento
            // se cont < 0, o for para de percorrer, pos vai contra a condição
            // cont/2 - 1, pq é no indice anterior ao do meio que vamos inserir o novo nó
            // apontando para o indice no meio
            temp = temp->next;
        }
        
        novo->next = temp->next; 
        temp->next = novo;
        cont++;
    }

}

void addespecifico(Node **head, char nome[50], int num, int pos){
    Node *novo = (Node*)malloc(sizeof(Node));
    strcpy(novo->nome, nome);
    novo->num = num;
    novo->next = NULL;

    if(*head == NULL || pos == 0){
        novo->next = *head;
        *head = novo;
    }else{
        Node *temp = *head;
        int cont = 0;
        while(cont != (pos-1)){// precisamos do nó anterior para remover o atual
            temp = temp->next;
            cont++;
        }

        novo->next = temp->next; // liga o novo nó com o proximo
        temp->next = novo;// o nó anterior agora aponta para o novo
    }

}

void removeespecifico(Node **head, int pos){
    Node *temp = *head;
    int cont = 0;
    if(pos == 0){
        *head = (*head)->next;
        free(temp);
        
    }else{
        while(cont != (pos-1) && cont > 1){
            temp = temp->next;
            cont++;
        }

        Node *aux = temp->next; 
        // cria variavel q guarda o nó do numero anterior
        // que aponta para o que queremos remover
        temp->next = aux->next;
        // o nó do numero anterior agora recebe o nó do numéro posterior ao apagado
        free(aux);

    }


}
void removemeio(Node **head){
    Node *temp = *head;
    
    if(cont == 1){
        free(temp);
        *head = NULL;
        cont--;
    }else{
        for(int i = 0; i < cont/2 - 1; i++){
            temp = temp->next;// vai apontar para o nó anterior ao do meio
        }
        
        Node *meio = temp->next; // meio aponta para o nó anterior
        // meio vai apontar para o proximo valor, como temp->next é um nó que aponta para o elemnto do meio
        // meio vai receber o elemento do meio
        temp->next = meio->next; // o nó anterior agora aponta para o proximo nó do meio
        free(meio); // libera o nó do meio
        cont--; //decrementa o contador, poque a lista diminuiu
    }

    
}
void removeinicio(Node **head){
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
   

}

void removefim(Node **head){
    Node *temp = *head;
    if((*head)->next == NULL){ // verifica se o head->next aponta para null
        // logo, verifica se só há 1 elemento
        free(temp);
        *head = NULL;
    }else{
        while(temp->next->next != NULL){
            //vai até o penultimo nó para permitir "pular" o ultimo nó
            // verifica se o nó do penultimo elemenro aponra para o ultimo
            temp = temp->next; // passa para o ultimo elemento
        }

        free(temp->next);
        temp->next = NULL;
    }
    
}

void imprimir(Node **head){
    Node *temp = *head;
    while(temp != NULL){
        printf("%s : %d -> ", temp->nome, temp->num);
        temp = temp->next;
    }
    printf("fim \n");
}

int main(){
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *head3 = NULL;
    

    int N, num;
    char nome[50];

    printf("insira o tamanho da lista: \n");
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        printf("insira o %d nome na lista: \n", i);
        scanf("%s", nome);

        printf("insira o %d numero na lista: \n", i);
        scanf("%d", &num);
        
        addinicio(&head1, nome, num);
        addmeio(&head2, nome, num);
        addfim(&head3, nome, num);
    }
    int pos;
    int pos2;
    printf("adicione numa posicao especifica: \n");
    scanf("%d", &pos);

    printf("insira novo nome na lista: \n");
    scanf("%s", nome);

    printf("insira onovo numero na lista: \n");
    scanf("%d", &num);

    addespecifico(&head1, nome, num, pos);
    imprimir(&head1);

    printf("insira uma posicao especifica para remover: \n");
    scanf("%d", &pos2);

    removeespecifico(&head1, pos2);


    printf("lista inicio: \n");
    imprimir(&head1);
    printf("lista inserir no meio: \n");
    imprimir(&head2);
    printf("lista inserir no final: \n");
    imprimir(&head3);

    printf("removendo no inicio: \n");
    removeinicio(&head1);
    imprimir(&head1);
    printf("removendo no meio: \n");
    removemeio(&head2);
    imprimir(&head2);
    printf("removendo no final: \n");
    removefim(&head3);
    imprimir(&head3);
}
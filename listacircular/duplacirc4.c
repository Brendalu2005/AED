#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char letra;
    struct Node *prox;
    struct Node *ant;
}Node;

void insereFinal(Node **head, Node **tail, char letra);
int Palindromo(Node **head, Node **tail);
void imprimeNormal(Node **head);
void imprimeInverso(Node **head, Node **tail);

int main(){
    Node *head = NULL;
    Node *tail = NULL;

    char letra = '\0';
    
    
    while(letra != 'z'){
        printf("insira uma letra: \n");
        scanf(" %c", &letra);
        if(letra != 'z'){
            insereFinal(&head, &tail, letra);
        }
    }

    imprimeNormal(&head);
    imprimeInverso(&head, &tail);
    int ehpalindromo = Palindromo(&head, &tail);

    if(ehpalindromo){
        printf("eh palindromo\n");
    }else{
        printf("nao eh palindromo\n");
    }
    


}

void imprimeNormal(Node **head){
    if(*head != NULL){
        Node *temp = *head;
        do{
            printf("%c -> ", temp->letra);
            temp = temp->prox;

        }while(temp != *head);

        printf("NULL\n");
    }
}

void imprimeInverso(Node **head, Node **tail){
    if(*head != NULL){
        Node *temp = *tail;
        do{
            printf("%c -> ", temp->letra);
            temp = temp->ant;

        }while(temp != *tail);
        
        printf("NULL\n");
    }
}

void insereFinal(Node **head, Node **tail, char letra){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        novo->letra = letra;
        novo->ant = NULL;

        if(*head == NULL){
            *head = novo;
            *tail = novo;
            novo->prox = novo;
            novo->ant = novo;
        }else{
            novo->prox = *head;
            novo->ant = *tail;
            (*tail)->prox = novo; // proximo do antigo ultimo
            (*head)->ant = novo;
            *tail = novo;

        }
    }
}

int Palindromo(Node **head, Node **tail){
    if(*head != NULL){
        Node *fraseNormal = *head;
        Node *fraseinversa = *tail;
        int contTotal = 0;
        int contPalindromo = 0;
        

        do{
            if(fraseNormal->letra == fraseinversa->letra){
                contPalindromo++;
            }
            fraseNormal = fraseNormal->prox;
            fraseinversa = fraseinversa->ant;
            contTotal++;

        }while(fraseNormal != fraseinversa  && fraseNormal->prox != fraseinversa); 
        //fraseNormal != fraseinversa -> vão avançando até se encontrarem no mesmo nó
        //Você precisa parar quando eles se encontram ou se cruzam.

        if(contTotal == contPalindromo && contPalindromo > 3){
            return 1;

        }else{
            return 0;

        }
    }

    return 0;
    
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char aviao[50];
    struct Node* next;
}Node;

void addfila(Node **head, Node **tail, char aviao[50]);
void organizarFila(Node **headO, Node **headS, Node **headN, Node **headL, Node **headFinal, Node **tailFinal);
void imprime (Node **head);

int main(){
    Node *headO = NULL, *tailO = NULL; 
    Node *headN = NULL, *tailN = NULL; 
    Node *headS = NULL, *tailS = NULL; 
    Node *headL = NULL, *tailL = NULL;
    Node *headFinal = NULL, *tailFinal = NULL;
    char aviaonum[50];
    int P = 0;

    while(1){
        scanf("%s", aviaonum);
        if(strcmp(aviaonum, "0") == 0){
            break;
        }

        if(aviaonum[0] == '-'){
            if(strcmp(aviaonum, "-1") == 0){
                P = -1;
            }
            else if(strcmp(aviaonum, "-2") == 0){
                P = -2;
            }
            else if(strcmp(aviaonum, "-3") == 0){
                P = -3;
            }
            else if(strcmp(aviaonum, "-4") == 0){
                P = -4;
            }
        }
        else{
            switch(P){
                case -1:
                    addfila(&headO, &tailO, aviaonum);
                    break;
                case -2:
                    addfila(&headS, &tailS, aviaonum);
                    break;
                case -3:
                    addfila(&headN, &tailN, aviaonum);
                    break;
                case -4:
                    addfila(&headL, &tailL, aviaonum);
                    break;
                default:
                    break;
            }
        }
    }

    organizarFila(&headO, &headS, &headN, &headL, &headFinal, &tailFinal);
    imprime(&headFinal);
}

void addfila(Node **head, Node **tail, char aviao[50]){
    Node *novo = (Node*)malloc(sizeof(Node));
    if(novo != NULL){
        strcpy(novo->aviao, aviao);
        novo->next = NULL;

        if(*head == NULL){
            *head = novo;
            *tail = novo;
        }else{
            (*tail)->next = novo;
            *tail = novo;
        }
    }
}

void organizarFila(Node **headO, Node **headS, Node **headN, Node **headL, Node **headFinal, Node **tailFinal){
    Node *tempO = *headO;
    Node *tempN = *headN;
    Node *tempS = *headS;
    Node *tempL = *headL;

   
    while(tempO != NULL || tempN != NULL || tempS != NULL || tempL != NULL){
        if(tempO != NULL){
            addfila(headFinal, tailFinal, tempO->aviao);
            tempO = tempO->next;
        }
        if(tempN != NULL){
            addfila(headFinal, tailFinal, tempN->aviao);
            tempN = tempN->next;
        }
        if(tempS != NULL){
            addfila(headFinal, tailFinal, tempS->aviao);
            tempS = tempS->next;
        }
        if(tempL != NULL){
            addfila(headFinal, tailFinal, tempL->aviao);
            tempL = tempL->next;
        }
    }
}

void imprime (Node **head){
    Node *temp = *head;
    while(temp != NULL){
        printf("%s", temp->aviao);
        temp = temp->next;
        if (temp != NULL){
            printf(" ");
        }  
    }

    printf("\n");
}

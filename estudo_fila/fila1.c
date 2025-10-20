#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node *next;

}Node;

void enqueue(Node **head, Node **tail, int valor){
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->valor = valor;
    novo->next = NULL;

    if(*head == NULL){
        *head = novo;
        *tail = novo;

    }else{
       (*tail)->next = novo;
        *tail = novo;

    }
}

void dequeue(Node **head, Node **tail){
    Node *temp = *head;
    if (*head != NULL){
        *head = (*head)->next;
        free(temp);

    }
    if(*head == NULL){
        *tail = NULL;

    }
}

void imprimir(Node **head){
    Node *temp = *head;
    while(temp != NULL){
        printf("%d-> ", temp->valor);
        temp = temp->next;
    }

    printf("NULL\n");
}

void interseccao(Node **head1, Node **tail1, Node **head2, Node **tail2, int k){
    Node *almoco; // inicio da fila que será "consumida"
    Node *trabalho; // inicio da fila 
    Node *tailtrabalho; // guarda o ultimo nó da fila que se mantém
    int pos = 0; //começa a partir da primeira posição (0)

    if(k == 1){
        almoco = *head1;
        trabalho = *head2;
        tailtrabalho = *tail2;
    }
    if(k == 2){
        almoco = *head2;
        trabalho = *head1;
        tailtrabalho = *tail1;
    }

    Node *temptrabalho = trabalho; //aponta para o head da fila que mantém
    Node *tempalmoco = almoco; //aponta para o head da fila que separa
   
    while(temptrabalho != NULL && tempalmoco != NULL){ 
        // quando uma fila acabar, acaba a intercalação 
        if(pos >= 1){

            Node *temp = tempalmoco; //nó atual da fila do almoço q será inserida
            // mesmo tempalmoco avançando, temp ainda guarda o nó anterior
            tempalmoco = tempalmoco->next;
            // avança a fila para o próximo nó

            temp->next = temptrabalho->next;
            //temp->next aponta para o próximo nó, então se temp aponta para o nó antigo,
            // temp->next aponta para o nó atual  
            //liga o nó do almoço para “depois” do atual do trabalho
            // inserindo a fila do almoço na fila do trabalho
            temptrabalho->next = temp;  // temp aponta para o nó atual da fila almoço
            //temptrabalho não aponta mais para o nó original, agora aponta para o nó inicial de temp(tempalmoco)
            // a fila avança com o decorrer do loop, então, o nó de almoço é inserido logo depois
            

            temptrabalho = temp->next;// avança a fila do trabalho
            // pula o nó inserido e vai para o próximo nó original de trabalho
  
        }

        pos++; //incrementa a posição

    }

    if(tempalmoco != NULL){
        // se a fila do trabalho acabar, mas ainda existirem pessoas na fila do almoço
        tailtrabalho->next = tempalmoco; // conecta o nó atual do loop para o fim da fila trabalho
        // tail->next aponta para o proximo elemento da lista, que agora será da fila almoço
    }
   
      // atualiza o tail da fila de trabalho
    Node *temp2 = trabalho; // inicio da fila trabalho
    while(temp2->next != NULL){ //Percorre a lista até encontrar o último nó
        temp2 = temp2->next;
    }
    tailtrabalho = temp2;
    //Atualiza tailtrabalho para apontar para esse nó → ou seja, recalcula o tail da fila trabalho.
    // para o ultimo elemento de verdade

    // esvazia a fila do almoço
    if(k == 1){
        *head1 = NULL;
        *tail1 = NULL;
    } else {
        *head2 = NULL;
        *tail2 = NULL;
        //se não esvaziar, eles ainda vão apontar para os nós que agora fazem parte da fila trabalho.
      
    }
  
}


int main(){
    Node *head1 = NULL;
    Node *tail1 = NULL;
    // para criar duas listas diferentes, da pra usar as mesmas funções, com heads diferentes
    // heads diferentes apontam para filas diferentes
    Node *head2 = NULL;
    Node *tail2 = NULL;
    int n, m, k, num;

    printf("Insira a quantidade de pessoas na fila 1: \n");
    scanf("%d", &n);
    printf("Insira a quantidade de pessoas na fila 2: \n");
    scanf("%d", &m);

    for(int i = 0; i < n; i++){
        printf("insira o numero %d da fila 1: \n", i);
        scanf("%d", &num);
        enqueue(&head1, &tail1, num);
    }
    for(int i = 0; i < m; i++){
        printf("insira o numero %d da fila 2: \n", i);
        scanf("%d", &num);
        enqueue(&head2, &tail2, num);
    }
    printf("fila 1: \n");
    imprimir(&head1);
    printf("fila 2: \n");
    imprimir(&head2);


    printf("O funcionario que saiu para almocar, ficou responsavel pela fila: \n");
    scanf("%d", &k);

    if(k == 1){
        interseccao(&head1, &tail1, &head2, &tail2, k);
        imprimir(&head2);
        dequeue(&head2, &tail2);

    }
    if(k == 2){
        interseccao(&head1, &tail1, &head2, &tail2, k);
        imprimir(&head1);
        dequeue(&head1, &tail1);

    }

   


}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char id[10];
    char destino[30];
    char emp[10];
    char modelo[20];
    int qtd;
    struct node*next;
}Node;

typedef struct queue{
     Node*front;
     Node*rear;
}Queue;

Node* inicia(Queue *q){
    q->front=NULL;
    q->rear=NULL;
    return q;
}
Node* cria_no(){
    Node* no;
    char id[10];
    char destino[30];
    char emp[10];
    char modelo[20];
    int qtd;
    fflush(stdin);
    printf("Digite a ID do voo:\n");
    fgets(id,10,stdin);
    fflush(stdin);
    printf("Digite o Destino do voo:\n");
    fgets(destino,30,stdin);
    fflush(stdin);
    printf("Digite a companhia do voo:\n");
    fgets(emp,10,stdin);
    fflush(stdin);
    printf("Digite o modelo do aviao:\n");
    fgets(modelo,20,stdin);
    fflush(stdin);
    printf("Digite a quantidade de passageiros do voo:\n");
    scanf("%d", &qtd);
    no = (Node*)malloc(sizeof(Node));
    strcpy(no->id,id);
    strcpy(no->destino,destino);
    strcpy(no->emp,emp);
    strcpy(no->modelo,modelo);
    no->qtd=qtd;
    no->next=NULL;
    return no;
}


void insert( Queue *q, Node *n){
    if(q->front==NULL){
        q->front=n;
        q->rear=n;

    }
    else
    {
        q->rear->next=n;
        q->rear=n;
    }

}

void remove_no(Queue *q){
    Node *rem;
    if(q->front==NULL)
        printf("Underflow\n");
    else
    {
        rem=q->front;
        q->front=q->front->next;
        printf("Voo sendo autorizado: %s\n", rem->id);
        free(rem);
        if(q->front==NULL)
            q->rear=NULL;

    }

}
void mostra( Queue *q){
    Node *ptr;
    ptr = q->front;
    if(ptr==NULL)
        printf("A FILA ESTA VAZIA!\n");
    else
    {
        printf("\n");
        while(ptr!=NULL){
            printf("Id: %s \n", ptr->id);
            ptr = ptr ->next;
        }
    }
};


Node* peek( Queue *q){
    if(q->front==NULL){
        printf("A FILA ESTA VAZIA!\n");
        return -1;
    }
    else
        return q->front;
}

void size( Queue *q){
    Node *ptr;
    ptr=q->front;
    int cont=0;
    if(ptr==NULL)
        printf("A fila esta vazia\n");
    else
    {
        while(ptr!=NULL){
        cont++;
        ptr=ptr->next;
        }
    printf("O tamanho da fila eh: %d avioes em espera", cont);
    }

}

int main()
{
    Queue *q;//
    q=(Queue*)malloc(sizeof(Queue));
    if(q==NULL)
        return 0;
    q=(Queue*)inicia(q);
    Node *v;
    int opt;

    do{
    //inicio menu
    printf("\n\n**MENU**\n");
    printf("1. O tamanho da fila:\n");
    printf("2. Autorizar decolagem:\n");
    printf("3. Adicionar voo a fila:\n");
    printf("4. Exibindo voos:\n");
    printf("5. Exibir caracteristicas do 1 voo:\n");
    printf("6. Sair:\n");
    printf("ENTRE COM A OPCAO DESEJADA: ");
    scanf("%d", &opt);
            switch(opt){
            case 1:
            size(q);
            break;
            case 2:
            remove_no(q);
            break;
            case 3:
            insert(q,cria_no());
            break;
            case 4:
            mostra(q);
            break;
            case 5:
            v=peek(q);
            printf("ID: %s\n", v->id);
            printf("Destino: %s \n", v->destino);
            printf("Companhia Aerea: %s \n", v->emp);
            printf("Modelo: %s \n", v->modelo);
            printf("Quantidade de passageiros: %d \n", v->qtd);
            break;
        }
    }while(opt>0 && opt!=6);
        system ("pause");
    return 0;
}


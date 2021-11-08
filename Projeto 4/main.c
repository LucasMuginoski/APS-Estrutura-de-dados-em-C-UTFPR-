#include <stdio.h>
#include <stdlib.h>

struct lista{
    char nome[40];
    struct lista *prev;
    struct lista *next;
};
typedef struct lista Lista;

Lista* inicializa(){
    return NULL;
}

Lista* insere(Lista *l,char n){
    Lista* novo=(Lista*)malloc(sizeof(Lista));
    printf("Digite o nome da pessoa:\n");
    fflush(stdin);
    scanf("%s",novo->nome);
    novo->next=l;
    novo->prev=NULL;
    if(l!=NULL)
        l->prev=novo;
    return novo;
}

Lista* navega(Lista* l,char ch){
    if(ch=='<'){
        if(l->prev==NULL)
            printf("\nInicio da lista!\n\n");
        else{
            l=l->prev;
            printf("\n%s\n",l->nome);
        }
        return l;
    }
        if(ch=='>'){
            if(l->next==NULL)
                printf("\nFim de lista!\n");
            else{
                l=l->next;
                printf("\n%s\n", l->nome);
            }
            return l;
        }
}

int main()
{
    Lista *dado;
    char ch;
    dado=inicializa();
    do{
        printf("\n*******MENU*******\n");
        printf("Digite i para inserir um nome\n");
        printf("Digite < para exibir o nome anterior\n");
        printf("Digite > para exibir o nome seguinte\n");
        printf("Digite q para sair\n");
        fflush(stdin);
        scanf("%c", &ch);
        switch(ch){
            case 'i':
            dado=insere(dado,ch);
            break;
            case '<':
            dado=navega(dado,ch);
            break;
            case '>':
            dado=navega(dado,ch);
            break;
       }
    }while(ch!='q');
    system("pause");
    return 0;
}


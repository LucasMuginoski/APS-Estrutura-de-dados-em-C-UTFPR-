#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int info;
    struct elemento *prox;
};
typedef struct elemento lista;

void inserir(lista **li, int n)
{
    lista *atual, *novo, *ant;
    novo = (lista *) malloc(sizeof(lista));

    atual = *li;
    ant = NULL;

    printf("Digite um valor: ");
    scanf("%d", &n);

    novo->info = n;

    if(atual == NULL){
        novo->prox = NULL;
        *li = novo;
    } else{
        while(atual != NULL && atual->info < n){
            ant = atual;
            atual = atual->prox;
        }

        novo->prox = atual;

        if(ant == NULL){
            *li = novo;
        } else{
            ant->prox = novo;
        }
    }
}

void exibir(lista *li)
{
    while(li != NULL)
    {
        printf("Valor: %d\n", li->info);
        li = li->prox;
    }
}

int main(){
    lista*inicio=NULL;
    int num;
    char opcao;
    do{
        inserir(&inicio,&num);
        printf("Deseja inserir outro elemento? (S/N)\n");
        fflush(stdin);
        scanf("%c",&opcao);
    }while(opcao=='s' || opcao=='S');
    exibir(inicio);
    return 0;
}

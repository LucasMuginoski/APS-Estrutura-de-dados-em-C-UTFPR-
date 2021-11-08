#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int info;
    struct arvore *esq;
    struct arvore *dir;
}Arvore;

Arvore* cria_arv_vazia(){
    return NULL;
}

Arvore* inserir(Arvore *a, int valor){
    if(a == NULL){
        a = (Arvore*)malloc(sizeof(Arvore));
        a->info = valor;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if(valor < a->info){
        a->esq = inserir(a->esq,valor);
    }
    else{
        a->dir = inserir(a->dir, valor);
    }
    return a;
}

void pre_ordem(Arvore *arv){
    if(arv != NULL){
        printf("%d, ", arv->info);
        pre_ordem(arv->esq);
        pre_ordem(arv->dir);
    }
}

void em_ordem(Arvore *arv){
    if(arv != NULL){
        em_ordem(arv->esq);
        printf("%d, ", arv->info);
        em_ordem(arv->dir);
    }
}

int maior_no(Arvore* arv){
    int maior;
    Arvore* ptr;
    ptr = arv;
    if(ptr->dir == NULL)
        return ptr->info;
    while(ptr->dir != NULL){
        ptr = ptr->dir;
        maior = ptr->info;
    }
    return maior;
}

int menor_no(Arvore* arv){
    int menor;
    Arvore* p;
    p=arv;
    if(p->esq == NULL)
        return p->info;
    while(p->esq != NULL){
            p = p->esq;
            menor = p->info;
    }
    return menor;
}
int qntd_nos(Arvore *arv){
    if(arv == NULL)
        return 0;
    else
        return 1 + qntd_nos(arv->esq) + qntd_nos(arv->dir);
}

int main(){
    int op, num;
    Arvore* a = cria_arv_vazia();
    do{
        system("cls");
        printf("**Menu de escolha**\n");
        printf("1. Digite para inserir um numero:\n");
        printf("2. Digite para imprimir a arvore em ordem\n");
        printf("3. Digite para imprimir maior elemento\n");
        printf("4. Digite para imprimir menor elemento\n");
        printf("5. Digite para imprimir a quantidade\n");
        printf("6. Sair\n");
        scanf("%d", &op);
        switch(op){
            case 1: //inserir elemento
            printf("Digite um valor para inserir: \n");
            scanf("%d", &num);
            a = inserir(a, num);
            system("cls");
            break;
            case 2:
            em_ordem(a);
            printf("\n");
            system("pause");
            break;
            case 3:
            printf("O maior elemento: %d \n", maior_no(a));
            printf("\n");
            system("pause");
            break;
            case 4:
            printf("O menor elemento: %d \n", menor_no(a));
            printf("\n");
            system("pause");
            break;
            case 5:
            printf("A quantidade de elementos: %d\n", qntd_nos(a));
            printf("\n");
            system("pause");
            break;
            }
    }while(op<0 || op!=6);
    system("pause");
    return 0;
}


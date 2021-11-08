#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct pilha {
  int info;
  struct pilha *prox;
};

typedef struct pilha Pilha;
Pilha *topo;

int empty(){
  if (topo == NULL)
    return 1;
  else
    return 0;
}

void push (int n){
  Pilha *novo = (Pilha *) malloc(sizeof(Pilha));
  novo->info = n;
  novo->prox = topo;
  topo = novo;
}
int pop(){
  int n;
  Pilha *aux;
  n = topo->info;
  aux = topo;
  topo = topo->prox;
  free(aux);
  return n;
}

int top(){
  return topo->info;
}

int main(void){

    int i;
    int check;
    char exp[50];
    printf("Digite uma expressao:\n");
    scanf("%s",exp);

    for(i=0;exp[i]!='\0';i++){

        if(exp[i]=='('){ //Aqui faltava chaves para a estrutura do if, pois dentro dele há mais de uma instrução

            push(exp[i]);

            if(exp[i]==')'){
                if(empty(exp)){
                    check = 1;
                    printf("Erro");
                    exit(0);
                }
                else
                    pop(exp[i]);
            }
        }
        if(empty(exp))
            printf("okay");
        else
            printf("**Erro!!**\n");
    }
    return 0;
}

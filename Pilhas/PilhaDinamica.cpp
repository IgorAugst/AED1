#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

typedef struct ESTRUTURA
{
    int chave;
    ESTRUTURA* prox;
}NO;

typedef struct
{
    NO* topo;
}PILHA;

void inicializar(PILHA* p){
    p->topo = NULL;
}

int tamanho(PILHA* p){
    NO* pos = p->topo;
    int i=0;
    
    while(pos!=NULL){
        i++;
        pos=pos->prox;
    }

    return i;
}

void push(PILHA* p, int chave){
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->chave = chave;
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(PILHA* p){
    if(p->topo == NULL) return -1;
    int ch = p->topo->chave;
    p->topo = p->topo->prox;
    free(p->topo);
    return ch;
}

int main(){
    PILHA p;
    inicializar(&p);
    
    for(int i=0; i<10; i++){
        push(&p, i);
    }

    int j=0;
    do{
        int j = pop(&p);
        printf("%d ", j);
    }while(j!=-1);
}
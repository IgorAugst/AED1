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
    NO* aux;
    aux = p->topo;
    int ch = aux->chave;
    p->topo = aux->prox;
    free(aux);
    return ch;
}

NO* copiaInvertida(NO* p){
    PILHA aux1;
    inicializar(&aux1);
    while(p != NULL){
        push(&aux1,p->chave);
        p=p->prox;
    }

    PILHA aux2;
    inicializar(&aux2);
    int j=0;
    while((j=pop(&aux1)) != -1){
        push(&aux2,j);
    }

    return(aux2.topo);
}

int main(){
    PILHA p1;
    inicializar(&p1);

    for(int i = 0; i<10; i++){
        push(&p1, i);
    }

    PILHA p2;
    inicializar(&p2);

    p2.topo = copiaInvertida(p1.topo);

    int j=0;
    while((j=pop(&p2)) != -1){
        printf("%d ", j);
    }
}
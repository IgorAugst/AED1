#include<stdlib.h>
#include<stdio.h>

#define MAX 50

typedef struct{
    REGISTRO A[MAX];
    int nroElementos;
}LISTA;

typedef struct{
    int Id;
}REGISTRO;

void inicializarLista(LISTA *l){
    l->nroElementos=0;
}

int tamanho(LISTA *l){
    return l->nroElementos;
}

void exibirElementos(LISTA *l){
    for(int i=0; i<l->nroElementos; i++){
        printf("%d", l->A[i].Id);
    }
}

int buscaSequencial(LISTA *l, int Id){
    for(int i=0; i<l->nroElementos; i++){
        if(l->A[i].id == Id) return i;
    }
    return -1;
}

int main(){

}


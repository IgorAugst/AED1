#include<stdlib.h>
#include<stdio.h>

#pragma region Lista
#define MAX 50

typedef struct{
    int Id;
}REGISTRO;

typedef struct{
    REGISTRO A[MAX];
    int nroElementos;
}LISTA;

void inicializarLista(LISTA *l){
    l->nroElementos=0;
}

int tamanho(LISTA *l){
    return l->nroElementos;
}

void exibirElementos(LISTA *l){
    for(int i=0; i<l->nroElementos; i++){
        printf("%d\n", l->A[i].Id);
    }
}

int buscaSequencial(LISTA *l, int Id){
    for(int i=0; i<l->nroElementos; i++){
        if(l->A[i].Id == Id) return i;
    }
    return -1;
}

bool inserirElemento(LISTA *l, int pos, REGISTRO r){
    if(pos>=0 && pos<=l->nroElementos && l->nroElementos!=MAX){
        for(int i=l->nroElementos; i>pos; i--){
            l->A[i]=l->A[i-1];
        }

        l->A[pos]=r;
        l->nroElementos++;
        return true;
    }else{
        return false;
    }
}

bool excluirElemento(LISTA *l, int Id){
    int pos = buscaSequencial(l,Id);

    if(pos==-1) return false;

    for(int i = pos; i<l->nroElementos-1; i++){
        l->A[i] = l->A[i+1];
    }

    l->nroElementos--;
    return true;
}

void reiniciarLista(LISTA *l){
    l->nroElementos=0;
}
#pragma endregion

int ocorrencias(LISTA* l, int x){
    int count=0;
    for(int i = 0; i<l->nroElementos; i++){
        if(l->A[i].Id == x) count++;
    }
    return count;
}

int main(){
    LISTA l;
    inicializarLista(&l);

    for(int i=0; i<10; i++){
        REGISTRO a;
        a.Id=i;
        inserirElemento(&l,i,a);
    }

    exibirElementos(&l);
}
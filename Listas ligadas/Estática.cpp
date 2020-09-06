#include<stdlib.h>
#include<stdio.h>

#define MAX 50

typedef struct
{
    int Id;
    int proximo;
}REGISTRO;


typedef struct
{
    REGISTRO A[MAX];
    int inicio;
    int dispo;
}LISTA;

void inicializar(LISTA *l){
    l->inicio = -1;
    l->dispo = 0;

    for(int i=0; i<MAX-1; i++){
        l->A[i].proximo = i+1;
    }

    l->A[MAX-1].proximo=-1;
}

void exibirLista(LISTA *l){
    int pos=l->inicio;

    while(pos != -1){
        printf("%d", l->A[pos].Id);
        pos=l->A[pos].proximo;
    }
}

int buscaSequencial(LISTA *l, int chave, int* ant){
    *ant= -1;
    int pos=l->inicio;

    while(pos != -1){
        if(l->A[pos].Id >= chave) break;
        *ant=pos;
        pos=l->A[pos].proximo;
    }

    if(pos == -1) return -1;
    if(l->A[pos].Id == chave) return pos;
    else return -1;
}

int main(){

}
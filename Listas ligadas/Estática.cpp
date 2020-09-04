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

int main(){

}
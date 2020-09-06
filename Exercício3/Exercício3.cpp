#include<stdlib.h>
#include<stdio.h>

#pragma region implementação
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
        printf("%d\n", l->A[pos].Id);
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

int obterNoDisp(LISTA *l){
    int result = l->dispo;
    if(result > -1){
        l->dispo=l->A[result].proximo;
    }
    return result;
}

void devolverNoDisp(LISTA *l, int pos){
    l->A[pos].proximo = l->dispo;
    l->dispo = pos;
}

bool excluirElemento(LISTA *l, int chave){
    int ant;
    int pos = buscaSequencial(l, chave, &ant);

    if(pos<0) return false;
    if(ant == -1) l->inicio = l->A[pos].proximo;
    else l->A[ant].proximo = l->A[pos].proximo;
    devolverNoDisp(l, pos);
    return true;
}

bool inserirElementoOrd(LISTA *l, int chave){
    int ant;
    int pos = buscaSequencial(l, chave, &ant);

    if(l->dispo < 0 || pos != -1) return false; //retorna falso caso não tenha espaço disponível ou caso o elemento já exista
    pos = obterNoDisp(l);
    l->A[pos].Id = chave;

    if(l->inicio < 0){ //se o inicio for menor do que 0 significa que é o primeiro elemento
        l->inicio = pos;
        l->A[pos].proximo = -1;
    }else{
        if(ant < 0){ //primeiro elemento
            l->A[pos].proximo = l->inicio;
            l->inicio = pos;
        }else{ //entre elementos
            l->A[pos].proximo = l->A[ant].proximo;
            l->A[ant].proximo = pos;
        }
    }

    return true;
}
#pragma endregion

void trocar(LISTA* l){
    int ultAnt=-1;
    int ultPos=l->inicio;
    while(ultPos!=-1){
        ultAnt=ultPos;
        ultPos=l->A[ultPos].proximo;      
    }

    int aux = l->A[l->inicio].Id;
    l->A[l->inicio].Id = l->A[ultAnt].Id;
    l->A[ultAnt].Id = aux;
}

void sobrescrever(LISTA* l, int i){
    int pos=0;
    int prox = l->inicio;
    while(pos != i && prox != -1){
        prox=l->A[prox].proximo;
        pos++;
    }

    l->A[l->A[prox].proximo].Id = l->A[prox].Id; 
}

int main(){
    LISTA l;
    inicializar(&l);
    for(int i=0; i<10; i++){
        inserirElementoOrd(&l, i);
    }

    exibirLista(&l);
    sobrescrever(&l,3);
    printf("----------\n");
    exibirLista(&l);
}
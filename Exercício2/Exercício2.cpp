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

bool identicas(LISTA* l1, LISTA *l2){
    if(l1->nroElementos != l2->nroElementos){
        return false;
    }

    for (int i=0; i<l1->nroElementos; i++){
        if(l1->A[i].Id != l2->A[i].Id){
            return false;
        }
    }

    return true;
}

int buscaSentinela(LISTA *l, int chave){
    l->A[l->nroElementos].Id=chave;
    int i=0;
    
    while(l->A[i].Id != chave) i++;
    if(l->nroElementos == i) return -1;
    else return i;

}

bool inserirOrdem(LISTA *l, REGISTRO r){
    if(l->nroElementos >= MAX) return false;
    int pos = l->nroElementos;

    while(pos > 0 && l->A[pos-1].Id > r.Id){
        l->A[pos] = l->A[pos-1];
        pos--;
    }

    l->A[pos] = r;
    l->nroElementos++;
}

int buscaBinaria(LISTA *l, int chave){
    int esq, meio, dir;
    esq=0;
    dir=l->nroElementos-1;

    while(esq<=dir){
        meio=(esq+dir)/2;

        if(l->A[meio].Id == chave) return meio;
        if(l->A[meio].Id < chave) esq=meio+1;
        else dir=meio-1;
    }
    return -1;

}

int main(){
    LISTA l;
    inicializarLista(&l);

    LISTA m;
    inicializarLista(&m);

    for(int i=0; i<10; i++){
        REGISTRO a;
        a.Id=i;
        inserirElemento(&l,i,a);
    }

    for(int i=0; i<10; i++){
        REGISTRO a;
        a.Id=i;
        inserirElemento(&m,i,a);
    }

    REGISTRO a;
    a.Id=85;
    inserirElemento(&l,2,a);

    REGISTRO b;
    b.Id=5;
    inserirElemento(&m,2,b);

    printf(identicas(&l,&m)?"true":"false");
}
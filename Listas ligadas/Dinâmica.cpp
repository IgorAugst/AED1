#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

typedef struct elemento{
    int chave;
    struct elemento* prox;
}no;

typedef struct{
    no* inicio;
}lista;

void inicializar(lista *l){
    l->inicio = NULL;
}

void exibirLista(lista *l){
    no* pos = l->inicio;

    while(pos != NULL){
        printf("%d ", pos->chave);
        pos = pos->prox;
    }
}

no* primElemento(lista *l){
    return l->inicio;
}

no* UltElemento(lista *l){
    no* pos = l->inicio;
    if(pos != NULL)
        while(pos->prox) pos = pos->prox;
    return pos;
}

no* nElemento(lista *l, int n){
    no* pos = l->inicio;
    int i=0;

    if(pos)
        while(pos && i<n){
            pos = pos->prox;
            i++;
        }
    return pos;
}

int tamanhoLista(lista *l){
    no* pos = l->inicio;
    int i=0;
    if(pos){
        while(pos){
            pos = pos->prox;
            i++;
        }
    }
    return i;
}

no* buscaSeqOrd(lista l, int chave, no* *ant){
    no* pos = l.inicio;
    *ant = NULL;
    if(pos){
        while(pos){
            if(pos->chave >= chave) break;
            *ant = pos;
            pos = pos->prox;
        }
    }

    if(pos){
        if(pos->chave == chave){
            return pos;
        }
    }

    return NULL;
}

bool inserirEleOrd(lista* l, int chave){
    no* novo;
    no* ant;

    novo = buscaSeqOrd(*l, chave, &ant);
    if(novo) return false; // se novo não for nulo significa que existe um valor na lista;

    novo = (no*)malloc(sizeof(no));
    novo->chave = chave;

    if(!l->inicio){ // se for nulo, ou seja, lista vazia
        l->inicio = novo;
        novo->prox = NULL;
    }else{
        if(!ant){
            novo->prox = l->inicio;
            l->inicio = novo;
        }else{
            novo->prox = ant->prox;
            ant->prox = novo;
        }
    }

    return true;
}

void anexar(lista *l, int chave){
    no* novo;
    no* ant = UltElemento(l);

    novo = (no*)malloc(sizeof(no));
    novo->chave = chave;
    novo->prox = NULL;
    if(!ant) l->inicio = novo;
    else ant->prox = novo;
}

bool excluirEle(lista *l, int chave){
    no* pos;
    no* ant;

    pos=buscaSeqOrd(*l, chave, &ant);

    if(!pos) return false;

    if(!ant){
        l->inicio = pos->prox;
    }else{
        ant->prox = pos->prox;
    }

    free(pos);
    return true;
}

void destruir(lista *l){
    no* atual;
    no* prox;
    atual = l->inicio;

    while(atual){
        prox=atual->prox;
        free(atual);
        atual=prox;
    }

    l->inicio = NULL;
}

int main(){
    lista a;
    inicializar(&a);

    for(int i = 0; i<10; i++){
        inserirEleOrd(&a, i);
    }

    exibirLista(&a);
    printf("\n-------\n");
    printf("tamanho: %d", tamanhoLista(&a));
    printf("\n-------\n");
    anexar(&a, 4);
    inserirEleOrd(&a, -98);
    excluirEle(&a, 6);
    exibirLista(&a);
}
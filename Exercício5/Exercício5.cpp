#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

#pragma region implementação
typedef struct elemento{
    int chave;
    struct elemento* prox;
}NO;

typedef struct{
    NO* inicio;
}LISTA;

void inicializar(LISTA *l){
    l->inicio = NULL;
}

void exibirLista(LISTA *l){
    NO* pos = l->inicio;

    while(pos != NULL){
        printf("%d ", pos->chave);
        pos = pos->prox;
    }
}

NO* primElemento(LISTA *l){
    return l->inicio;
}

NO* UltElemento(LISTA *l){
    NO* pos = l->inicio;
    if(pos != NULL)
        while(pos->prox) pos = pos->prox;
    return pos;
}

NO* nElemento(LISTA *l, int n){
    NO* pos = l->inicio;
    int i=0;

    if(pos)
        while(pos && i<n){
            pos = pos->prox;
            i++;
        }
    return pos;
}

int tamanhoLista(LISTA *l){
    NO* pos = l->inicio;
    int i=0;
    if(pos){
        while(pos){
            pos = pos->prox;
            i++;
        }
    }
    return i;
}

NO* buscaSeqOrd(LISTA l, int chave, NO* *ant){
    NO* pos = l.inicio;
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

bool inserirEleOrd(LISTA* l, int chave){
    NO* novo;
    NO* ant;

    novo = buscaSeqOrd(*l, chave, &ant);
    if(novo) return false; // se novo não for nulo significa que existe um valor na lista;

    novo = (NO*)malloc(sizeof(NO));
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

void anexar(LISTA *l, int chave){
    NO* novo;
    NO* ant = UltElemento(l);

    novo = (NO*)malloc(sizeof(NO));
    novo->chave = chave;
    novo->prox = NULL;
    if(!ant) l->inicio = novo;
    else ant->prox = novo;
}

bool excluirEle(LISTA *l, int chave){
    NO* pos;
    NO* ant;

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

void destruir(LISTA *l){
    NO* atual;
    NO* prox;
    atual = l->inicio;

    while(atual){
        prox=atual->prox;
        free(atual);
        atual=prox;
    }

    l->inicio = NULL;
}
#pragma endregion

void ExcluirOcorrencias(LISTA* l, int x){
    NO* ant = NULL;
    NO* pos = l->inicio;

    while(pos != NULL){
        if(pos->chave == x){
            if(ant == NULL){
                l->inicio = pos->prox;
                pos = l->inicio;
            }else{
                ant->prox = pos->prox;
                pos = ant;
            }
        }else{
            ant = pos;
            pos = pos->prox;          
        }
    }
}

NO* copia(NO* p){
    NO* copiado = (NO*)malloc(sizeof(NO));
    NO* pos = p->prox;
    NO* ant = NULL;
    copiado->prox = NULL;

    if(p != NULL){
        copiado->chave = p->chave;
        ant = copiado;
    }

    while(pos != NULL){
        NO* aux = (NO*)malloc(sizeof(NO));
        aux->chave = pos->chave;
        aux->prox = NULL;
        ant->prox = aux;

        ant=aux;
        pos=pos->prox;
    }

    return copiado;
}

int main(){
    LISTA a;
    inicializar(&a);
    LISTA b;

    for(int i=0; i<3; i++){
        anexar(&a, 2);
    }

    anexar(&a, 5);

    for(int i=0; i<3; i++){
        anexar(&a, 2);
    }

    

    b.inicio = copia(a.inicio);
    anexar(&a,45);
    exibirLista(&a);
    printf("\n-----------------\n");
    exibirLista(&b);
}

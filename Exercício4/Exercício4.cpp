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

int ocorrencias(LISTA* l, int x){
    int count = 0;
    NO* pos = l->inicio;
    while(pos){
        if(pos->chave == x) count++;
        pos = pos->prox;
    }

    return count;
}

bool identicas(LISTA* l1, LISTA *l2){
    NO* pos1 = l1->inicio;
    NO* pos2 = l2->inicio;

    while(pos1 && pos2){
        if(pos1->chave != pos2->chave) return false;
        pos1 = pos1->prox;
        pos2 = pos2->prox;
    }

    if(pos1 != pos2)return false;
    else return true;
}

int main(){
    LISTA a;
    inicializar(&a);
    LISTA b;
    inicializar(&b);

    for(int i = 0; i<10; i++){
        inserirEleOrd(&a, i);
    }

    for(int i = 0; i<10; i++){
        inserirEleOrd(&b, i);
    }

    anexar(&a,75);
    anexar(&b,75);

    printf(identicas(&a,&b)?("true"):("false"));

}
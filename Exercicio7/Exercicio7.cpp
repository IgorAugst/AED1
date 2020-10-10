#include <stdlib.h>
#include <stdio.h>

typedef struct ESTRUTURA
{
    int chave;
    struct ESTRUTURA *prox;
    struct ESTRUTURA *ant;
} NO;

typedef struct
{
    NO *cabeca;
} LISTA;

void inicializar(LISTA *l)
{
    l->cabeca = (NO *)malloc(sizeof(NO));
    l->cabeca->ant = l->cabeca;
    l->cabeca->prox = l->cabeca;
}

void anexar(LISTA *l, int chave){
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->chave=chave;
    novo->prox = l->cabeca;
    novo->ant = l->cabeca->ant;
    l->cabeca->ant = novo;
    novo->ant->prox = novo;
}

NO* retorna(LISTA* l){
    NO* pos = l->cabeca;

    for(int i = 0; i<5; i++){
        pos = pos->prox;
    }

    return pos;
}

NO* exibirInvertida(LISTA* l){
    NO* pos = l->cabeca->ant;
    while(pos != l->cabeca){
        printf("%d ", pos->chave);
        pos=pos->ant;
    } 
    return l->cabeca;
}

void inserirAntes(LISTA* l, int ch, NO* atual){
    NO* pos = l->cabeca;

    while(pos != atual){
        pos = pos->prox;
    }

    NO* novo = (NO*)malloc(sizeof(NO));
    novo->chave = ch;

    novo->prox = pos;
    novo->ant = pos->ant;
    pos->ant = novo;
    novo->ant->prox = novo; 
}

int main()
{
    LISTA l;
    inicializar(&l);

    for(int i=0; i<10; i++){
        anexar(&l, i);
    }

    exibirInvertida(&l);

    printf("\n------------\n");

    NO* aux = retorna(&l);
    inserirAntes(&l, 125, aux);
    exibirInvertida(&l);
}
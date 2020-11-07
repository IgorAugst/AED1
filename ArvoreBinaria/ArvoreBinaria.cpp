#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <iostream>

using namespace std;

typedef struct estrutura
{
    int chave;
    estrutura *dir;
    estrutura *esq;
} NO;

void inicializar(NO **raiz)
{
    (*raiz) = NULL;
}

NO* inserirNo(NO **raiz, NO *pai, int ch, int pos)
{
    NO *novo;
    if (pai)
    {
        if ((pos == 1 && pai->esq != NULL) || (pos == 2 && pai->dir != NULL))
            return NULL;
    }

    novo = (NO *)malloc(sizeof(NO));
    novo->chave = ch;
    novo->esq = NULL;
    novo->dir = NULL;

    if (!pai)
        *raiz = novo;
    else
    {
        if (pos == 1)
            pai->esq = novo;
        else
            pai->dir = novo;
    }

    return novo;
}

void print2DUtil(NO *raiz, int space)  
{  
    int COUNT = 10;
    // Base case  
    if (raiz == NULL)  
        return;  
  
    // Increase distance between levels  
    space += COUNT;  
  
    // Process right child first  
    print2DUtil(raiz->dir, space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<raiz->chave<<"\n";  
  
    // Process left child  
    print2DUtil(raiz->esq, space);  
}  

void preOrdem(NO* r){
    if(r){
        printf("%d ", r->chave);
        preOrdem(r->esq);
        preOrdem(r->dir);
    }
}

void emOrdem(NO* r){
    if(r){
        emOrdem(r->esq);
        printf("%d ", r->chave);
        emOrdem(r->dir);
    }
}

void posOrdem(NO* r){
    if(r){
        posOrdem(r->esq);
        posOrdem(r->dir);
        printf("%d ", r->chave);
    }
}

int main()
{
    NO* raiz;
    inicializar(&raiz);

    inserirNo(&raiz, raiz, 3, 1);
    inserirNo(&raiz, raiz, 1, 2);
    inserirNo(&raiz, raiz, 2, 1);
    print2DUtil(raiz, 0);
    printf("\n");
    posOrdem(raiz);
}
//Igor Augusto Dos Santos

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>


// ######### ESCREVA O NROUSP AQUI
char* nroUSP() {
    return("11796851");
}


// ######### ESCREVA SEU NOME AQUI
char* nome() {
    return("Igor Augusto dos Santos");
}

// elemento da lista
typedef struct estr {
        int valor;
        struct estr* prox;
} NO;


// funcao principal
NO* uniao(NO* p1, NO* p2);


void adicionar(NO* *n, int valor){
	if(*n == NULL){
		*n = (NO*)malloc(sizeof(NO));
		(*n)->prox = NULL;
		(*n)->valor=valor;
	}else{
		NO* aux = (NO*)malloc(sizeof(NO));
		aux->prox=NULL;
		aux->valor=valor;
	}
}

//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
NO* uniao(NO* p1, NO* p2) {

	NO* resp;
	resp = NULL;

	if(p1==NULL && p2==NULL) return resp;

	NO* pos1 = p1;
	NO* pos2 = p2;

	while(pos1 != NULL && pos2 != NULL){
		
	}

	return resp;
}



//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {

	NO* p1 = NULL;
	NO* p2 = NULL;

	// aqui vc pode incluir codigo para inserir elementos
	// de teste nas listas p1 e p2

	// o EP sera testado com chamadas deste tipo
	NO* teste = NULL;
	teste = uniao(p1,p2);

}

// por favor nao inclua nenhum código abaixo da função main()
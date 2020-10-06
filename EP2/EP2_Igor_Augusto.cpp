#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>


// ######### ESCREVA O NROUSP AQUI
const char* nroUSP() {
    return("11796851");
}


// ######### ESCREVA SEU NOME AQUI
const char* nome() {
    return("Igor Augusto dos Santos");
}

// elemento da pilha
typedef struct estrutura {
	struct estrutura *prox;
       	int tipo; // 1=char e 2=float
       	union {
              	char simbolo;
              	float valor;
       	};
} NO;

typedef struct
{
    int tamanho=0;
    NO* topo=NULL;
}PILHA;


// funcao principal (retorna float e int)
float calcular(char* expressao, int* codigo);


void push(PILHA* p, int tipo, float valor, char carac){
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->tipo = tipo;
    if(tipo == 2){
        novo->valor = valor;
    }else{
        novo->simbolo = carac;
    }

    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
}

NO pop(PILHA* p){
    NO resp;
    if(p->topo == NULL) return resp;
    NO* aux;
    resp = *(p->topo);
    aux = p->topo;
    p->topo = aux->prox;
    p->tamanho--;
    free(aux);
    return resp;
}

//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------
float calcular(char* expressao, int* codigo){

	float resp = 0.0;
	*codigo = 999; 

    PILHA pi;
    int i = 0;
    char aux;

    while(expressao[i] != '\0'){
        aux = expressao[i]-48;
        if(aux<=9 && aux >= 0){
            push(&pi, 2, aux, '.');
        }else{
            push(&pi,1,0,expressao[i]);
        }

        if(expressao[i] == ')'){
            NO saida = pop(&pi);
            i=i+1;
        }
        i++;
    }

	return resp;
}



//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {


	// o EP sera testado com chamadas deste tipo

	char exp[200];
	strcpy(exp, "(7*5)");

	int codigo;

	float resp = calcular(exp,&codigo);


}

// por favor nao inclua nenhum código abaixo da função main()
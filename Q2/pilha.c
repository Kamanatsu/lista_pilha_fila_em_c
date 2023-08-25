#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "lista.h"


struct pilha{
    Lista* prim;
};


typedef struct lista Lista;
	struct lista {
	int info;
	Lista *prox;
};

Pilha* pilha_cria(void){
	Pilha *p=(Pilha*)malloc(sizeof(Pilha));
	if(p==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	p->prim=NULL;
	return p;
}

void pilha_push(Pilha *p, int info){
	Lista *l=(Lista*)malloc(sizeof(Lista));
	if(l==NULL){
		printf("Memoria insuficiente!!!\n");
		exit(1);
	}
	l->info=info;
	l->prox=p->prim;
	p->prim=l;
}

int pilha_vazia(Pilha *p){
	return p->prim==NULL;
}

int pilha_pop(Pilha *p){
	int a;
	Lista *l;
	if(pilha_vazia(p)){
		printf("Pilha Vazia!!!\n");
		exit(1);
	}
	l=p->prim;
	a=l->info;
	p->prim=l->prox;
	free(l);
	return a;
}

void pilha_imprime(Pilha *p){
	Lista *lAux=p->prim;
	while(lAux!=NULL){
		printf("%d\n", lAux->info);
		lAux=lAux->prox;
	}
}

void pilha_libera(Pilha *p){
	Lista* l=p->prim;
	Lista* lAux;
	while(l!=NULL){
		lAux=l->prox;
		free(l);
		l=lAux;
	}
	free(p);
}

Pilha* inverte_pilha(Pilha* p){
	Lista* lAux=p->prim;
	Pilha* k=pilha_cria();
	while(lAux!=NULL){
		pilha_push(k, lAux->info);
		lAux=lAux->prox;
	}
	return k;
}

Pilha* empilha_elem_comuns(Lista* l1, Lista* l2){
    Pilha* p = pilha_cria();
    Lista* lAux = l1;
    Lista* l = lst_cria();
    
    while(lAux!=NULL){
        l = lst_busca(l2,lAux->info);
        if(l != NULL){
            pilha_push(p,l->info);
        }
        lAux = lAux->prox;
    }
    return p;
    
}









#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fila2.h"
#include "lista.h"



struct fila{
    Lista *ini;
    Lista *fim;
};



/*CRIA*/

Fila* fila_cria(void){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    if(f==NULL){
        printf("Memoria insuficiente!!!\n");
        exit(1);
    }
    f->ini = NULL;
    f->fim = NULL;
    return f;
}


void fila_insere(Fila *f, int info){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    if(l==NULL){
        printf("Memoria insuficiente!!!\n");
       exit(1);
    }
    l->info = info;
    l->prox = NULL;
    if(!fila_vazia(f))
        f->fim->prox = l;
    else
        f->ini = l;
        f->fim = l;
}


int fila_vazia(Fila *f){
    return f->ini==NULL;
}


int fila_remove(Fila *f){
    Lista *l; int a;
    if(fila_vazia(f)){
        printf("Fila Vazia!!!\n");
        exit(1);
    }
    a = f->ini->info;
    l = f->ini;
    f->ini = f->ini->prox;
    free(l);
    if(fila_vazia(f))
        f->fim = NULL;
    return a;
}


void fila_imprime(Fila *f){
    Lista *lAux = f->ini;
    while(lAux!=NULL){
        printf("%d\n",lAux->info);
        lAux = lAux->prox;
    }
}

/*Libera o espaço alocado para uma fila.*/
void fila_libera(Fila *f){
    Lista* l = f->ini;
    Lista* lAux;
    while(l!=NULL){
        lAux = l->prox;
        free(l);
        l = lAux;
    }
    free(f);
}


/*RETORNA QTD DE PRIMOS*/
int qtd_primos(Fila* f){
    Lista* l = f->ini;
    Lista* lAux = l;
    int cont = 0;
	while(lAux!=NULL){
		int i, c = 2;
        for(i=2; i<((int)floor(sqrt(lAux->info)))+1; i++){
           if(lAux->info % i == 0)
           {
              c += (lAux->info/i == i) ? 1 : 2;
           }
        }
        if(c == 2){
            cont += 1;
        }
		lAux = lAux->prox;
	}
    return cont;
}

/*inverter fila*/
Fila* inverte_fila(Fila* f){
    Lista* l1 = f->ini;
    Lista* lAux = l1;
    Lista* lx = lst_cria();
    Fila* k = fila_cria();
    
    
    
    while(lAux!=NULL){
        lst_insere(lx,lAux->info);
        lAux = lAux->prox;
    }
    
    lAux = lx;
    while(lAux!=NULL){
        fila_insere(k,lAux->info);
        lAux = lAux->prox;
    }
    return k;
}



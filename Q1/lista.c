#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista.h"

/* Cria uma lista vazia.*/
Lista* lst_cria(){
	return NULL;
}

/* Testa se uma lista � vazia.*/
int lst_vazia(Lista *l){
	return (l==NULL);
}

/* Insere um elemento no in�cio da lista.*/
Lista* lst_insere(Lista *l, int info){
	Lista* ln = (Lista*)malloc(sizeof(Lista));
	ln->info = info;
	ln->prox = l;
	return ln;
}

/*insere ordenado*/

Lista* lst_insere_ordenado(Lista *l, int info){
    Lista *lNew = (Lista*)malloc(sizeof(Lista));
    lNew->info = info;
    if(l==NULL){
        lNew->prox = NULL;
        return lNew;
    }else 
        if(l->info>=info){
            lNew->prox = l;
            return lNew;
    }
    else{
        Lista *lAnt = l;
        Lista *lProx = l->prox;
        while(lProx!=NULL&&lProx->info<info){
            lAnt = lProx;
            lProx = lProx->prox;
        }
        lAnt->prox = lNew;
        lNew->prox = lProx;
        return l;
    
    }
}



/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info){

    Lista* lAux = l;
    while(lAux!=NULL){
        if(lAux->info == info){
            return lAux;
        }
        lAux = lAux->prox;
    }
    return NULL;
}


/* Imprime uma lista.*/
void lst_imprime(Lista *l){
	Lista* lAux = l;
	while(lAux!=NULL){
		printf("Info = %d\n",lAux->info);
		lAux = lAux->prox;
	}
}


/*Fun��o que remove um elemento de uma lista,
retornando a lista alterada*/
Lista* lst_remove(Lista *l, int info){
	if(l!=NULL){
		Lista* lAux = l->prox;
		if(l->info==info){
			free(l);
			return lAux;
		}
	else{
 		Lista* lAnt = l;
 		while(lAux!=NULL ){
 			if(lAux->info == info){
 				lAnt->prox = lAux->prox;
				free(lAux);
				break;
			}else{
				lAnt = lAux;
				lAux = lAux->prox;
			}
		}
	}
}
	return l;
}


/* Libera o espa�o alocado por uma lista.*/
void lst_libera(Lista *l){
	Lista* lProx;
	while(l!=NULL){
		lProx = l->prox;
		free(l);
 		l = lProx;
 	}
}

/*retornar o número de nós da lista que possuem o campo info com valor
menor que n*/
int menores(Lista* l, int n){
    Lista* lAux = l;
    int cont = 0;
	while(lAux!=NULL){
		if(lAux->info < n){
		    cont += 1;
		}
		lAux = lAux->prox;
	}
	return cont;
}


/*função para somar os valores do campo info de todos os nós*/
int soma(Lista* l){
    Lista* lAux = l;
    int soma = 0;
	while(lAux!=NULL){
		soma = lAux->info + soma;
	    lAux = lAux->prox;
	}
	return soma;
}

/*função para retornar o número de nós da lista que possuem o campo info com n
divisores positivos*/
int num_ndivp(Lista* l, int n){
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
        if(c == n){
            cont += 1;
        }
		lAux = lAux->prox;
	}
	return cont;
}


/*função para gerar uma nova lista que é a intersecção de duas listas*/

Lista* lst_intersec(Lista* l1, Lista* l2){
    Lista* lAux = l1;
    Lista* l = lst_cria();
    Lista* l3 = lst_cria();
    while(lAux!=NULL){
        l = lst_busca(l2,lAux->info);
        if(l != NULL){
            l3 = lst_insere_ordenado(l3,l->info);
        }
        lAux = lAux->prox;
    }
    return l3;
}

/*Concatena*/

Lista* lst_conc(Lista* l1, Lista* l2){
    Lista* lx = l2;
    Lista* lz = l1;
    Lista* lAux = lst_cria();
    
    while(lx != NULL){
        lAux = lst_insere(lAux,lx->info);
        lx = lx -> prox;
    }
    
    while(lz != NULL){
        lAux = lst_insere(lAux,lz->info);
        lz = lz -> prox;
    }

    return lAux;
}

/*diferença*/
Lista* lst_diferenca(Lista* l1, Lista* l2){
    Lista* l3 = lst_intersec(l1,l2);
    Lista* lAux = l3;
    Lista* l = lst_cria();
    Lista* lx = l1;
    
    while(lAux!=NULL){
        l = lst_busca(l1,lAux->info);
        if(l != NULL){
            lx = lst_remove_rec(l1,lAux->info);
        }
        lAux = lAux->prox;
    }
    l1 = lx;
}

/*Imprime invertida*/

void lst_imprime_invertida_rec(Lista* l){
    if(lst_vazia(l))
        return;
    else{
        lst_imprime_invertida_rec(l->prox);
        printf("info: %d\n",l->info);
    }
}

/*remove rec*/

Lista* lst_remove_rec(Lista *l, int info){
    if(!lst_vazia(l))
        if(l->info==info){
            Lista* lAux = l;
            l = l->prox;
            free(lAux);
        }
        else{
            l->prox = lst_remove_rec(l->prox,info);
        }
    return l;
}





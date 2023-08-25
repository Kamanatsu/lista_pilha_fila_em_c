

typedef struct lista Lista;
	struct lista {
	int info;
	Lista *prox;
};


typedef struct lista Lista;
/* Cria uma lista vazia.*/
Lista* lst_cria();
/* Testa se uma lista � vazia.*/
int lst_vazia(Lista *l);
/* Insere um elemento no in�cio da lista.*/
Lista* lst_insere(Lista *l, int info);
/*insere ordenado*/
Lista* lst_insere_ordenado(Lista *l, int info);
/* Busca um elemento em uma lista.*/
Lista* lst_busca(Lista *l, int info);
/* Imprime uma lista.*/
void lst_imprime(Lista *l);
/* Remove um elemento de uma lista.*/
Lista* lst_remove(Lista *l, int info);
/* Libera o espa�o alocado por uma lista.*/
void lst_libera(Lista *l);
/*retornar o número de nós da lista que possuem o campo info com valor
menor que n*/
int menores(Lista* l, int n);
/*função para somar os valores do campo info de todos os nós*/
int soma(Lista* l);
/*função para retornar o número de nós da lista que possuem o campo info com n
divisores positivos*/
int num_ndivp(Lista* l, int n);
/*função para gerar uma nova lista que é a intersecção de duas listas*/
Lista* lst_intersec(Lista* l1, Lista* l2);
/*concatena*/
Lista* lst_conc(Lista* l1, Lista* l2);
/*diferença*/
Lista* lst_diferenca(Lista* l1, Lista* l2);
/*imprime invertida*/
void lst_imprime_invertida_rec(Lista* l);
/*remove rec*/
Lista* lst_remove_rec(Lista *l, int info);






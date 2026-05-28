#ifndef LISTAESTATICA_H_INCLUDED
#define LISTAESTATICA_H_INCLUDED

#include "funcionario.h"

#define TamMax 100

typedef struct
{
    int qtde;
    TipoFuncionario elemt[TamMax];

} TipoListaEst;

TipoListaEst criarListaEst();

int listaVaziaEst(TipoListaEst *lista);

int listaCheiaEst(TipoListaEst *lista);

int buscaListaEst(TipoListaEst *lista,char cpf[15]);

int inserirListaEst(TipoListaEst *lista,TipoFuncionario func);

void imprimirListaEst(TipoListaEst *lista);

int removerListaEst(TipoListaEst *lista,char cpf[15]);

void salvarListaEst(TipoListaEst *lista,char nomeArquivo[]);

void carregarListaEst(TipoListaEst *lista,char nomeArquivo[]);

#endif
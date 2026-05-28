#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED

#include "funcionario.h"

typedef struct no
{
    TipoFuncionario info;
    struct no *prox;

} TipoLista;

TipoLista *criarLista();

int listaVazia(TipoLista *lista);

TipoLista *buscarLista(TipoLista *lista,char cpf[15]);

TipoLista *inserirLista(TipoLista *lista,TipoFuncionario func);

void imprimirLista(TipoLista *lista);

TipoLista *removerLista(TipoLista *lista,char cpf[15]);

TipoLista *liberarLista(TipoLista *lista);

void salvarLista(TipoLista *lista,char nomeArquivo[]);

TipoLista *carregarLista(TipoLista *lista,char nomeArquivo[]);

#endif
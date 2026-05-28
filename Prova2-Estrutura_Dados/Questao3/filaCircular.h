#ifndef FILACIRCULAR_H_INCLUDED
#define FILACIRCULAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

#define TamMax 10

typedef struct
{
    int inicio;
    int fim;
    int qtde;

    TipoFuncionario dados[TamMax];

} TipoFilaCircular;

void inicializarFilaCircular(TipoFilaCircular *fila);

int filaCircularVazia(TipoFilaCircular fila);

int filaCircularCheia(TipoFilaCircular fila);

void enfileirarFilaCircular(TipoFilaCircular *fila,TipoFuncionario func);

TipoFuncionario desenfileirarFilaCircular(TipoFilaCircular *fila);

void imprimirFilaCircular(TipoFilaCircular fila);

#endif
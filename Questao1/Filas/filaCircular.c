#include <stdio.h>
#include "filaCircular.h"

void inicializarFilaCircular(TipoFilaCircular *fila)
{
  fila->inicio = 0;
  fila->fim = -1;
  fila->total = 0;
}

int vazia(TipoFilaCircular *f) {
    return f->total == 0;
}

int cheia(TipoFilaCircular *f) {
    return f->total == MAX;
}

void enfileirar(TipoFilaCircular *f, int x) {
    if (cheia(f)) {
        printf("ERRO: fila cheia\n");
        return;
    }

    f->fim = (f->fim + 1) % MAX;
    f->dados[f->fim] = x;
    f->total++;

    printf("Enfileirado: %d\n", x);
}

int desenfileirar(TipoFilaCircular *f) {
    if (vazia(f)) {
        printf("ERRO: fila vazia\n");
        return -1;
    }

    int x = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;

    printf("Desenfileirado: %d\n", x);
    return x;
}
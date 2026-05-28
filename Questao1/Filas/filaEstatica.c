#include <stdio.h>
#include "filaEstatica.h"

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->total = 0;
    printf("Fila estatica inicializada\n");
}

int vazia(Fila *f) {
    return f->total == 0;
}

int cheia(Fila *f) {
    return f->total == MAX;
}

void enfileirar(Fila *f, int x) {
    if (cheia(f)) {
        printf("ERRO: fila cheia\n");
        return;
    }

    f->fim = (f->fim + 1) % MAX;
    f->dados[f->fim] = x;
    f->total++;

    printf("Enfileirado: %d\n", x);
}

int desenfileirar(Fila *f) {
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

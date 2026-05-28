#include <stdio.h>
#include "matriz.h"

void inicializar(Matriz *m, int l, int c) {
    m->linhas = l;
    m->colunas = c;
    printf("Matriz inicializada (%dx%d)\n", l, c);
}

void set(Matriz *m, int i, int j, int valor) {
    m->dados[i][j] = valor;
    printf("Valor inserido [%d][%d] = %d\n", i, j, valor);
}

int get(Matriz *m, int i, int j) {
    return m->dados[i][j];
}

void imprimir(Matriz *m) {
    printf("Matriz:\n");

    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            printf("%d ", m->dados[i][j]);
        }
        printf("\n");
    }
}
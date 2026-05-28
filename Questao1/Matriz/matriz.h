#ifndef MATRIZ_H
#define MATRIZ_H

#define MAX_LINHAS 10
#define MAX_COLUNAS 10

typedef struct {
    int dados[MAX_LINHAS][MAX_COLUNAS];
    int linhas;
    int colunas;
} Matriz;

void inicializar(Matriz *m, int l, int c);
void set(Matriz *m, int i, int j, int valor);
int get(Matriz *m, int i, int j);
void imprimir(Matriz *m);

#endif
#ifndef FILA_CIRCULAR_H
#define FILA_CIRCULAR_H

#define MAX 10

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int total;
} TipoFilaCircular;

void inicializar(TipoFilaCircular *f);
int vazia(TipoFilaCircular *f);
int cheia(TipoFilaCircular *f);
void enfileirar(TipoFilaCircular *f, int x);
int desenfileirar(TipoFilaCircular *f);

#endif
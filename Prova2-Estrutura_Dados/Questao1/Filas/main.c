#include <stdio.h>

#include "filaEstatica.h"
#include "filaDinamica.h"
#include "filaCircular.h"

void linha() {
    printf("\n--------------------------------------\n");
}

int main() {

    linha();
    printf("TESTE FILA ESTATICA\n");
    linha();

    Fila fe;
    inicializarFila(&fe);

    enfileirar(&fe, 1);
    enfileirar(&fe, 2);
    enfileirar(&fe, 3);

    while (!vazia(&fe)) {
        desenfileirar(&fe);
    }

    if (vazia(&fe)) printf("Fila vazia\n");

    linha();
    printf("TESTE FILA DINAMICA\n");
    linha();

    Fila fd;
    inicializar(&fd);

    enfileirar(&fd, 10);
    enfileirar(&fd, 20);

    while (!vazia(&fd)) {
        desenfileirar(&fd);
    }

    if (vazia(&fd)) printf("Fila vazia\n");

    linha();
    printf("TESTE FILA CIRCULAR\n");
    linha();

    Fila fc;
    inicializar(&fc);

    enfileirar(&fc, 100);
    enfileirar(&fc, 200);
    enfileirar(&fc, 300);

    while (!vazia(&fc)) {
        desenfileirar(&fc);
    }

    if (vazia(&fc)) printf("Fila vazia\n");

    return 0;
}
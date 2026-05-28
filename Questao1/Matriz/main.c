#include <stdio.h>
#include "matriz.h"

void linha() {
    printf("\n--------------------------------------\n");
}

int main() {

    linha();
    printf("TESTE MATRIZ\n");
    linha();

    Matriz m;
    inicializar(&m, 3, 3);

    set(&m, 0, 0, 1);
    set(&m, 0, 1, 2);
    set(&m, 0, 2, 3);

    set(&m, 1, 0, 4);
    set(&m, 1, 1, 5);
    set(&m, 1, 2, 6);

    set(&m, 2, 0, 7);
    set(&m, 2, 1, 8);
    set(&m, 2, 2, 9);

    imprimir(&m);

    return 0;
}
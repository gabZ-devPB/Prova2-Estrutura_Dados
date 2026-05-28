#include <stdio.h>

#include "pilhaEstatica.h"
#include "pilhaDinamica.h"

int main() {


    PilhaEstatica pe;

    inicializar(&pe);

    push(&pe, 10);
    push(&pe, 20);
    push(&pe, 30);

    imprimir(&pe);

    pop(&pe);

    imprimir(&pe);

    printf("\nTopo: %d\n", top(&pe));


    PilhaDinamica pd;

    inicializarDinamica(&pd);

    pushDinamica(&pd, 100);
    pushDinamica(&pd, 200);
    pushDinamica(&pd, 300);

    imprimirDinamica(&pd);
    popDinamica(&pd);
    imprimirDinamica(&pd);

    printf("\nTopo: %d\n", topDinamica(&pd));
    liberarDinamica(&pd);

    getchar();
    return 0;
}
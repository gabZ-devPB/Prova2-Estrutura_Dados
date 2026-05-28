#include "filaCircular.h"

int main()
{
  TipoFilaCircular fila;

  TipoFuncionario f1 ={"Gabriel David", "123.456.789-33", 3000, FUNCIONARIO};

  TipoFuncionario f2 ={"Jorge", "123.456.789-44", 9000, DIRETOR};

  TipoFuncionario f3 ={"Gabriel Pereira", "123.456.789-55", 5000, COORDENADOR};

  TipoFuncionario f4 ={"Pedro Rogerio", "123.456.789-66", 950000, DIRETOR};

  inicializarFilaCircular(&fila);

  enfileirarFilaCircular(&fila, f1);
  enfileirarFilaCircular(&fila, f2);
  enfileirarFilaCircular(&fila, f3);
  enfileirarFilaCircular(&fila, f4);

  imprimirFilaCircular(fila);

  printf("\nDOCUMENTO IMPRESSO:\n");

  while (!filaCircularVazia(fila))
  {
    TipoFuncionario aux;

    aux = desenfileirarFilaCircular(&fila);

    printf("%s\n", aux.nome);
  }

  return 0;
}

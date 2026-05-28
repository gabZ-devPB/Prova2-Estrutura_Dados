#include "filaCircular.h"

void inicializarFilaCircular(TipoFilaCircular *fila)
{
  fila->inicio = 0;
  fila->fim = -1;
  fila->qtde = 0;
}

int filaCircularVazia(TipoFilaCircular fila)
{
  return (fila.qtde == 0);
}

int filaCircularCheia(TipoFilaCircular fila)
{
  return (fila.qtde == TamMax);
}

void enfileirarFilaCircular(TipoFilaCircular *fila, TipoFuncionario func)
{
  int i;
  int pos;
  TipoFuncionario aux;

  if (filaCircularCheia(*fila))
  {
    printf("ERRO: FILA CHEIA\n");
    return;
  }

  fila->fim++;

  if (fila->fim == TamMax)
  {
    fila->fim = 0;
  }

  fila->dados[fila->fim] = func;

  fila->qtde++;

  for (i = 0; i < fila->qtde - 1; i++)
  {
    pos = (fila->inicio + i) % TamMax;

    if (fila->dados[pos].cargo > fila->dados[(pos + 1) % TamMax].cargo)
    {
      aux = fila->dados[pos];

      fila->dados[pos] = fila->dados[(pos + 1) % TamMax];
      fila->dados[(pos + 1) % TamMax] = aux;
    }
  }
}

TipoFuncionario desenfileirarFilaCircular(
    TipoFilaCircular *fila)
{
  TipoFuncionario func;

  if (filaCircularVazia(*fila))
  {
    printf("ERRO: FILA VAZIA\n");
    return fila->dados[0];
  }

  func = fila->dados[fila->inicio];

  fila->inicio++;

  if (fila->inicio == TamMax)
  {
    fila->inicio = 0;
  }

  fila->qtde--;

  return func;
}

void imprimirFilaCircular(TipoFilaCircular fila)
{
  int i;
  int pos;

  if (filaCircularVazia(fila))
  {
    printf("FILA VAZIA\n");
    return;
  }

  printf("\nFILA DE IMPRESSAO\n");

  for (i = 0; i < fila.qtde; i++)
  {
    pos = (fila.inicio + i) % TamMax;

    printf("\nNome: %s", fila.dados[pos].nome);

    printf("\nCPF: %s", fila.dados[pos].cpf);

    printf("\nSalario: %.2f", fila.dados[pos].salario);

    printf("\nPrioridade: %d\n", fila.dados[pos].cargo);
  }
}
#include "listaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TipoLista *criarLista()
{
    return NULL;
}

int listaVazia(TipoLista *lista)
{
    return(lista==NULL);
}

TipoLista *buscarLista(TipoLista *lista,char cpf[15])
{
    TipoLista *aux;

    for(aux=lista;aux!=NULL;aux=aux->prox)
    {
        if(strcmp(aux->info.cpf,cpf)==0)
            return aux;
    }

    return NULL;
}

TipoLista *inserirLista(TipoLista *lista,TipoFuncionario func)
{
    TipoLista *novo;
    TipoLista *ant;
    TipoLista *p;

    if(buscarLista(lista,func.cpf)!=NULL)
        return lista;

    novo = (TipoLista*) malloc(sizeof(TipoLista));

    novo->info = func;

    ant = NULL;
    p = lista;

    while(p!=NULL &&
          strcmp(p->info.nome,
                 func.nome)<0)
    {
        ant = p;
        p = p->prox;
    }

    novo->prox = p;

    if(ant==NULL)
        lista = novo;
    else
        ant->prox = novo;

    return lista;
}

void imprimirLista(TipoLista *lista)
{
    TipoLista *p;

    if(listaVazia(lista))
    {
        printf("LISTA VAZIA\n");
        return;
    }

    for(p=lista;p!=NULL;p=p->prox)
    {
        printf("\nNome: %s",p->info.nome);

        printf("\nCPF: %s",p->info.cpf);

        printf("\nSalario: %.2f\n",p->info.salario);
    }
}

TipoLista *removerLista(TipoLista *lista,char cpf[15])
{
    TipoLista *ant;
    TipoLista *p;

    ant = NULL;
    p = lista;

    while(p!=NULL &&
          strcmp(p->info.cpf,cpf)!=0)
    {
        ant = p;
        p = p->prox;
    }

    if(p==NULL)
        return lista;

    if(ant==NULL)
        lista = p->prox;
    else
        ant->prox = p->prox;

    free(p);

    return lista;
}

TipoLista *liberarLista(TipoLista *lista)
{
    TipoLista *p;

    while(lista!=NULL)
    {
        p = lista->prox;

        free(lista);

        lista = p;
    }

    return NULL;
}

void salvarLista(TipoLista *lista,char nomeArquivo[])
{
    FILE *fp;
    TipoLista *p;

    fp = fopen(nomeArquivo,"w");

    if(fp==NULL)
        return;

    for(p=lista;p!=NULL;p=p->prox)
    {
        fprintf(fp,"%s,%s,%.2f\n",
                p->info.nome,
                p->info.cpf,
                p->info.salario);
    }

    fclose(fp);
}

TipoLista *carregarLista(TipoLista *lista, char nomeArquivo[])
{
    FILE *fp;
    TipoFuncionario func;

    fp = fopen(nomeArquivo,"r");

    if(fp==NULL)
        return lista;

    while(fscanf(fp,"%99[^,],%14[^,],%f\n",
                 func.nome,
                 func.cpf,
                 &func.salario)==3)
    {
        lista = inserirLista(lista,func);
    }

    fclose(fp);

    return lista;
}
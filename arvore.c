#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

No *ab_no(int valor)
{
    No *no = malloc(sizeof(No));
    no->valor = valor;
    no->no_esquerda = NULL;
    no->no_direita = NULL;

    return no;
}

void ab_inserir_no(No **raiz, int valor)
{
    if (*raiz == NULL)
    {
        *raiz = ab_no(valor);
        printf("Criando o no: %d\n", valor);
    }
    else
    {
        if ((*raiz)->valor >= valor)
        {
            ab_inserir_no(&(*raiz)->no_esquerda, valor);
        }
        else if ((*raiz)->valor < valor)
        {
            ab_inserir_no(&(*raiz)->no_direita, valor);
        }
    }
}

void ab_buscar(No *raiz, int valor)
{

    if (raiz == NULL)
    {
        printf("\n\nValor nao encontrado\n");
        return;
    }
    if (raiz->valor != valor)
    {
        if (raiz->valor >= valor)
        {
            ab_buscar(raiz->no_esquerda, valor);
        }
        else if (raiz->valor < valor)
        {
            ab_buscar(raiz->no_direita, valor);
        }
    }
    else
    {
        printf("\n\nValor encontrado: %d\n", raiz->valor);
    }
}

void ab_imprimir_em_ordem(No *raiz)
{ // EM ORDEM
    if (raiz != NULL)
    {
        ab_imprimir_em_ordem(raiz->no_direita);
        printf("%d ", raiz->valor);
        ab_imprimir_em_ordem(raiz->no_esquerda);
    }
}

void ab_imprimir_pre_order(No *raiz)
{

    if (raiz != NULL)
    {
        printf("%d ", raiz->valor);
        ab_imprimir_em_ordem(raiz->no_direita);
        ab_imprimir_em_ordem(raiz->no_esquerda);
    }
}

void ab_imprimir_pos_order(No *raiz)
{
    if (raiz != NULL)
    {
        ab_imprimir_em_ordem(raiz->no_direita);
        ab_imprimir_em_ordem(raiz->no_esquerda);

        printf("%d ", raiz->valor);
    }
}

int ab_min(No *raiz)
{
    if (raiz->no_esquerda == NULL)
        return raiz->valor;

    return ab_min(raiz->no_esquerda);
}

int ab_max(No *raiz)
{
    if (raiz->no_direita == NULL)
        return raiz->valor;

    return ab_max(raiz->no_direita);
}

No* encontrar_menor_valor(No* no){ 
    No* atual = no;

    while (atual->no_esquerda != NULL){
        atual = atual->no_esquerda;
    }

    return atual;
}

No* ab_remover_no(No* raiz, int valor){
    if (raiz == NULL){
        return raiz;
    }

    if (valor < raiz->valor){
        raiz->no_esquerda = ab_remover_no(raiz->no_esquerda, valor);
    } else if (valor > raiz->valor){
        raiz->no_direita = ab_remover_no(raiz->no_direita, valor);
    } else {
        if (raiz->no_esquerda == NULL){
            No* temp = raiz->no_direita;
            free(raiz);
            return temp;
        } else if (raiz->no_direita == NULL){
            No* temp = raiz->no_esquerda;
            free(raiz);
            return temp;
        }

        No* temp = encontrar_menor_valor(raiz->no_direita);

        raiz->valor = temp->valor;
 
        raiz->no_direita = ab_remover_no(raiz->no_direita, temp->valor);
    }

    return raiz;
}
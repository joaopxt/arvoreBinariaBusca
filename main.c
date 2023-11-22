#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(int argc, char *argv[])
{

    No *raiz = NULL;
    ab_inserir_no(&raiz, 5);
    ab_inserir_no(&raiz, 4);
    ab_inserir_no(&raiz, 6);
    ab_inserir_no(&raiz, 3);
    ab_inserir_no(&raiz, 7);
    ab_inserir_no(&raiz, 2);
    ab_inserir_no(&raiz, 8);

    printf("\n\n");

    printf("Em ordem:  ");
    ab_imprimir_em_ordem(raiz);
    printf("\n\n");

    printf("Pre-ordem:  ");
    ab_imprimir_pre_order(raiz);
    printf("\n\n");

    printf("Pos-ordem:  ");
    ab_imprimir_pos_order(raiz);
    printf("\n\n");

    ab_buscar(raiz, 10);
    printf("\n\n");

    printf("O valor minimo da arvore e: %d", ab_min(raiz));
    printf("\n\n");
    printf("O valor maximo da arvore e: %d", ab_max(raiz));
    printf("\n\n");

    int valor_remover = 7;
    printf("Removendo o numero: %d\n\n", valor_remover);
    raiz = ab_remover_no(raiz, valor_remover);

    printf("Arvore em ordem apos remocao: ");
    ab_imprimir_em_ordem(raiz);
    printf("\n\n");

    return 0;
}
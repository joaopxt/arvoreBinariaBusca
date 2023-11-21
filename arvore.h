typedef struct No
{
    int valor;
    struct No *no_esquerda;
    struct No *no_direita;
} No;

No *ab_no(int valor);
void ab_inserir_no(No **raiz, int valor);

void ab_buscar(No *raiz, int valor);

void ab_imprimir_em_ordem(No *raiz);
void ab_imprimir_pre_order(No *raiz);
void ab_imprimir_pos_order(No *raiz);

int ab_min(No *raiz);
int ab_max(No *raiz);
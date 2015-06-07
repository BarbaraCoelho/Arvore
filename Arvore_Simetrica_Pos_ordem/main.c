/*******************************************************************

    Nome: Bárbara Coelho.
    IFSC
    Engenharia Eletrônica
    Programação de Computadores II

                    Árvore - Função 'altura'

*******************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Estrutura Árvore */
typedef struct arv Arv;
struct arv
{
    char info;
    struct arv* esq;
    struct arv* dir;
};

/* Protótipo de função */
Arv* inicializa(void);
Arv* cria(char c, Arv* sae, Arv* sad);
int vazia(Arv* a);
void imprime (Arv* a);              /* trata raiz, percorre sae, percorre sad */
Arv* libera (Arv* a);
int busca (Arv* a, char c);
int altura(Arv* a);
void imprime_simetrica (Arv* a);    /* percorre sae, trata raiz, percorre sad */
void imprime_pos (Arv* a);          /* percorre sae, percorre sad, trata raiz */

int main()
{
    Arv* a = cria('a',
                    cria('b',
                        inicializa(),
                        cria('d', inicializa(), inicializa())
                        ),
                    cria('c',
                        cria('e', inicializa(), inicializa()),
                        cria('f', inicializa(), inicializa())
                        )
                );
    printf("Pre-Ordem:\n\n");
    imprime(a);
    printf("\n\nOrdem Simetrica:\n\n");
    imprime_simetrica(a);
    printf("\n\nPos-Ordem:\n\n");
    imprime_pos(a);
    libera(a);

    return 0;
}

/* FUNÇÕES */

Arv* inicializa(void)
{
    return NULL;
}

Arv* cria(char c, Arv* sae, Arv* sad)
{
    Arv* p=(Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

int vazia(Arv* a)
{
    return a == NULL;
}

void imprime (Arv* a)
{
    if (!vazia(a))
    {
        printf("<%c", a->info); /* mostra raiz */
        if (a->esq == NULL)
            printf("<>");
        else
            imprime(a->esq);        /* mostra sae */
        if (a->dir == NULL)
            printf("<>");
        else
            imprime(a->dir);        /* mostra sad */
        printf(">");
    }
}

Arv* libera (Arv* a)
{
    if (!vazia(a))
    {
        libera(a->esq); /* libera sae */
        libera(a->dir); /* libera sad */
        free(a);        /* libera raiz */
    }
    return NULL;
}

int busca (Arv* a, char c)
{
    if (vazia(a))
        return 0; /* árvore vazia: não encontrou */
    else
        return a->info == c || busca(a->esq,c) || busca(a->dir,c);
}

int altura(Arv* a)
{
    int he, hd;
    if (a == NULL)
        return 0; // altura de árvore vazia é 0
    else
    {
        he = altura(a->esq);
        hd = altura(a->dir);
        if (he < hd) return hd + 1;
        else return he + 1;
    }
}

void imprime_simetrica (Arv* a)
{
    if (!vazia(a))
    {
        printf("<");
        if (a->esq == NULL)
            printf("<>");
        else
            imprime_simetrica(a->esq);        /* mostra sae */
        printf("<%c>", a->info);             /* mostra raiz */
        if (a->dir == NULL)
            printf("<>");
        else
            imprime_simetrica(a->dir);        /* mostra sad */
        printf(">");
    }
}

void imprime_pos (Arv* a)
{
    if (!vazia(a))
    {
        if (a->esq == NULL)
            printf("<> ");
        else
            imprime_pos(a->esq);        /* mostra sae */
        if (a->dir == NULL)
            printf("<> ");
        else
            imprime_pos(a->dir);        /* mostra sad */
        printf("<%c> ", a->info);       /* mostra raiz */
    }
}

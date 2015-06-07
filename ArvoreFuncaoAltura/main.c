/*******************************************************************

    Nome: B�rbara Coelho.
    IFSC
    Engenharia Eletr�nica
    Programa��o de Computadores II

                    �rvore - Fun��o 'altura'

*******************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Estrutura �rvore */
typedef struct arv Arv;
struct arv
{
    char info;
    struct arv* esq;
    struct arv* dir;
};

/* Prot�tipo de fun��o */
Arv* inicializa(void);
Arv* cria(char c, Arv* sae, Arv* sad);
int vazia(Arv* a);
void imprime (Arv* a);
Arv* libera (Arv* a);
int busca (Arv* a, char c);
int altura(Arv* a);

int main()
{
    int h;
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
    imprime(a);
    h = altura(a);
    printf("\n\nAltura = %d\n",h);
    libera(a);

    return 0;
}

/* FUN��ES */

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
        return 0; /* �rvore vazia: n�o encontrou */
    else
        return a->info == c || busca(a->esq,c) || busca(a->dir,c);
}

int altura(Arv* a)
{
    int he, hd;
    if (a == NULL)
        return 0; // altura de �rvore vazia � 0
    else
    {
        he = altura(a->esq);
        hd = altura(a->dir);
        if (he < hd) return hd + 1;
        else return he + 1;
    }
}

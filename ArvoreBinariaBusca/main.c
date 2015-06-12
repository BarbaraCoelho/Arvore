/***********************************************************************

    Nome: Bárbara Coelho.
    IFSC - Câmpus Florianópolis
    Engenharia Eletrônica
    Programação II

                    Atividade - Árvore binária de busca

***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct arv Arv;

struct arv
{
    int info;
    struct arv* esq;
    struct arv* dir;
};

Arv* inicializa (void);
Arv* cria(int c, Arv* sae, Arv* sad);
int vazia(Arv* a);
Arv* libera (Arv* a);
void imprime (Arv* a);
Arv* busca (Arv* r, int v);
Arv* insere (Arv* a, int v);
Arv* retira (Arv* r, int v);

int main()
{
    Arv* EBusca = inicializa();
    Arv* a = cria(3,
                    cria(1,
                        inicializa(),
                        cria(2, inicializa(), inicializa())
                        ),
                    cria(5,
                        cria(4, inicializa(), inicializa()),
                        cria(6, inicializa(), inicializa())
                        )
                );
    printf("Arvore inicial:\n");
    imprime(a);
    ////////////////////////////////////////////////////////////////
    EBusca = busca(a,5);
    if (EBusca != NULL)
        printf("\nElemento na posicao %p.\n\n",EBusca);
    else
        printf("\nElemento nao encontrado.\n\n");
    ////////////////////////////////////////////////////////////////
    printf("Insere elemento:\n");
    insere(a,7);
    imprime(a);
    ////////////////////////////////////////////////////////////////
    printf("\nRetira elemento:\n");
    retira(a,3);
    imprime(a);
    ////////////////////////////////////////////////////////////////
    libera(a);
    return 0;
}

Arv* inicializa (void)
{
    return NULL;
}

Arv* cria(int c, Arv* sae, Arv* sad)
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

void imprime (Arv* a)
{
    if (a != NULL)
    {
        imprime(a->esq);
        printf("  %d\n",a->info);
        imprime(a->dir);
    }
}

Arv* busca (Arv* r, int v)
{
    if (r == NULL) return NULL;
    else if (r->info > v) return busca (r->esq, v);
    else if (r->info < v) return busca (r->dir, v);
    else return r;
}

Arv* insere (Arv* a, int v)
{
    if (a==NULL)
    {
        a = (Arv*)malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if (v < a->info)
        a->esq = insere(a->esq,v);
    else
        a->dir = insere(a->dir,v);
    return a;
}

Arv* retira (Arv* r, int v)
{
    if (r == NULL)
        return NULL;
    else if (r->info > v)
        r->esq = retira(r->esq, v);
    else if (r->info < v)
        r->dir = retira(r->dir, v);
    else /* achou o elemento */
    {
        if (r->esq == NULL && r->dir == NULL) /* elemento sem filhos */
        {
            free (r);
            r = NULL;
        }
        else if (r->esq == NULL) /* só tem filho à direita */
        {
            Arv* t = r;
            r = r->dir;
            free (t);
        }
        else if (r->dir == NULL) /* só tem filho à esquerda */
        {
            Arv* t = r;
            r = r->esq;
            free (t);
        }
        else /* tem os dois filhos */
        {
            Arv* pai = r;
            Arv* f = r->esq;
            while (f->dir != NULL)
            {
                pai = f;
                f = f->dir;
            }
            r->info = f->info; /* troca as informações */
            f->info = v;
            r->esq = retira(r->esq,v);
        }
    }
    return r;
}

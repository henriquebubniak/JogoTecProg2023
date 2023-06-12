#include "ConjuntoPlataformas.h"
#include <stdlib.h>
#include "Fase.h"

ConjuntoPlataformas::ConjuntoPlataformas(Fase* pF, GerenciadorGrafico* pgg, int f):
    nPlataformas(10),
    listapPlataformas(),
    posicoesPossiveis(),
    fase(f)
{
    posicoesPossiveis.push_back(Vector2f(0.f,1450.f));
    posicoesPossiveis.push_back(Vector2f(1600.f,1450.f));
    posicoesPossiveis.push_back(Vector2f(2900.f,1000.f));
    posicoesPossiveis.push_back(Vector2f(4100.f,550.f));
    posicoesPossiveis.push_back(Vector2f(5800.f,1000.f));
    posicoesPossiveis.push_back(Vector2f(7000.f,1450.f));
    posicoesPossiveis.push_back(Vector2f(8200.f,1450.f));
    posicoesPossiveis.push_back(Vector2f(10300.f,1450.f));
    posicoesPossiveis.push_back(Vector2f(11500.f,1450.f));
    posicoesPossiveis.push_back(Vector2f(13100.f,1450.f));
    if (f == 1)
        for (int i = 0; i < nPlataformas; i++)
        {
            listapPlataformas.push_back(new Plataforma(posicoesPossiveis[i], "./imagens/plataformaCidade.png", pF, pgg));
        }
    if (f == 2)
        for (int i = 0; i < nPlataformas; i++)
        {
            listapPlataformas.push_back(new Plataforma(posicoesPossiveis[i], "./imagens/plataformaMar.png", pF, pgg));
        }
    
}

ConjuntoPlataformas::~ConjuntoPlataformas()
{
    for (list<Plataforma*>::iterator i = listapPlataformas.begin(); i != listapPlataformas.end(); i++)
    {
        delete(*i);
    }
}

void ConjuntoPlataformas::adPlataforma(Fase* pF)
{
    for (list<Plataforma*>::iterator i = listapPlataformas.begin(); i != listapPlataformas.end(); i++)
    {
        pF->adEntidade(static_cast<Entidade*>(*i));
    }
}
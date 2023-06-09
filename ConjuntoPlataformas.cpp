#include "ConjuntoPlataformas.h"
#include <stdlib.h>
#include "Fase.h"

ConjuntoPlataformas::ConjuntoPlataformas(Fase* pF, GerenciadorGrafico* pgg):
    nPlataformas(12),
    listapPlataformas(),
    posicoesPossiveis()
{
    posicoesPossiveis.push_back(Vector2f(0.f,1450.f));
    posicoesPossiveis.push_back(Vector2f(1600.f,1450.f));
    posicoesPossiveis.push_back(Vector2f(2900.f,1000.f));
    posicoesPossiveis.push_back(Vector2f(4100.f,550.f));
    posicoesPossiveis.push_back(Vector2f(5800.f,1000.f));
    posicoesPossiveis.push_back(Vector2f(7000.f,1000.f));
    posicoesPossiveis.push_back(Vector2f(8200.f,1450.f));
    posicoesPossiveis.push_back(Vector2f(9800.f,1450.f));
    posicoesPossiveis.push_back(Vector2f(11500.f,1450.f));
    posicoesPossiveis.push_back(Vector2f(12700.f,1450.f));
    posicoesPossiveis.push_back(Vector2f(14300.f,1450.f));
    posicoesPossiveis.push_back(Vector2f(15500.f,1450.f));

    for (int i = 0; i < nPlataformas; i++)
    {
        listapPlataformas.push_back(new Plataforma(posicoesPossiveis[i], pF, pgg));
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
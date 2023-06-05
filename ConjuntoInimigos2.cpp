#include "ConjuntoInimigos2.h"
#include <stdlib.h>
#include "Fase.h"

ConjuntoInimigos2::ConjuntoInimigos2(Fase* pF, GerenciadorGrafico* pgg, Jogador1* pJ1, Jogador2* pJ2):
    nInimigos(0),
    listapInis(),
    posicoesPossiveis()
{
    srand(time(NULL));
    nInimigos = rand()%7 + 4;
    posicoesPossiveis.push_back(Vector2f(2000.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(2300.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(2600.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(3400.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(3700.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(4000.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(4300.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(4600.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(4900.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(5200.f, 0.f));
    for (int i = 0; i < nInimigos; i++)
    {
        listapInis.push_back(new Inimigo2(posicoesPossiveis[i], pF, pgg, pJ1, pJ2));
    }
    
}

ConjuntoInimigos2::~ConjuntoInimigos2()
{
}

void ConjuntoInimigos2::adInimigos2(Fase* pF)
{
    for (list<Inimigo2*>::iterator i = listapInis.begin(); i != listapInis.end(); i++)
    {
        pF->adEntidade(static_cast<Entidade*>(*i));
    }
}
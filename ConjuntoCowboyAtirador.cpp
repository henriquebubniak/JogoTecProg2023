#include "ConjuntoCowboyAtirador.h"
#include <stdlib.h>
#include "Fase.h"

ConjuntoCowboyAtirador::ConjuntoCowboyAtirador(Fase* pF, GerenciadorGrafico* pgg, HeroiPreto* pJ1, HeroiVerde* pJ2):
    nInimigos(0),
    listapInis(),
    posicoesPossiveis()
{
    srand(time(NULL));
    rand();
    nInimigos = (rand()%7) + 4;//de 4 a 10 inimigos2
    cout << nInimigos << " INIMIGOS2" << endl;
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
        listapInis.push_back(new CowboyAtirador(posicoesPossiveis[i], pF, pgg, pJ1, pJ2));
    }
    
}

ConjuntoCowboyAtirador::~ConjuntoCowboyAtirador()
{
}

void ConjuntoCowboyAtirador::adInimigos1(Fase* pF)
{
    for (list<CowboyAtirador*>::iterator i = listapInis.begin(); i != listapInis.end(); i++)
    {
        pF->adEntidade(static_cast<Entidade*>(*i));
    }
}
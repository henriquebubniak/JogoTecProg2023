#include "ConjuntoCowboyPerseguidor.h"
#include <stdlib.h>
#include "Fase.h"

ConjuntoCowboyPerseguidor::ConjuntoCowboyPerseguidor(Fase* pF, GerenciadorGrafico* pgg, HeroiPreto* pJ1, HeroiVerde* pJ2):
    nInimigos(0),
    listapInis(),
    posicoesPossiveis()
{
    srand(time(NULL));
    rand();
    nInimigos = (rand()%7) + 4;//de 4 a 10 CowboyPerseguidor
    cout << nInimigos << " CowboyPerseguidor" << endl;
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
        listapInis.push_back(new CowboyPerseguidor(posicoesPossiveis[i], pF, pgg, pJ1, pJ2));
    }
    
}

ConjuntoCowboyPerseguidor::~ConjuntoCowboyPerseguidor()
{
}

void ConjuntoCowboyPerseguidor::adCowboyPerseguidor(Fase* pF)
{
    for (list<CowboyPerseguidor*>::iterator i = listapInis.begin(); i != listapInis.end(); i++)
    {
        pF->adEntidade(static_cast<Entidade*>(*i));
    }
}
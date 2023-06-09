#include "ConjuntoCowboyPerseguidor.h"
#include <stdlib.h>
#include "Fase.h"

ConjuntoCowboyPerseguidor::ConjuntoCowboyPerseguidor(Fase* pF, GerenciadorGrafico* pgg, HeroiPreto* pJ1, HeroiVerde* pJ2):
    nInimigos(0),
    listapInis()
{
    srand(time(NULL));
    rand();
    nInimigos = (rand()%7) + 4;//de 4 a 10 CowboyPerseguidor
    cout << nInimigos << " CowboyPerseguidor" << endl;
    //5800 - 8200
    int delta = (8200-5200)/nInimigos;
    for (float i = 5800.0; i < 8200.0; i+=(float)delta)
    {
        listapInis.push_back(new CowboyPerseguidor(Vector2f(i, 700.f), pF, pgg, pJ1, pJ2));
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
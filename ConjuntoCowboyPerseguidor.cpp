#include "ConjuntoCowboyPerseguidor.h"
#include <stdlib.h>
#include "Fase.h"

ConjuntoCowboyPerseguidor::ConjuntoCowboyPerseguidor(Fase* pF, GerenciadorGrafico* pgg, HeroiPreto* pJ1, HeroiVerde* pJ2):
    nInimigos(0),
    listapInis()
{
    srand(time(NULL));
    rand();
    nInimigos = (rand()%8) + 3;//de 3 a 10 CowboyPerseguidor
    cout << nInimigos << " CowboyPerseguidor" << endl;
    //5800 - 8200
    int delta = (7000-4100)/nInimigos;
    for (float i = 4100.0; i < 6900.0; i+=(float)delta)
    {
        listapInis.push_back(new CowboyPerseguidor(Vector2f(i, 100.f), pF, pgg, pJ1, pJ2));
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
#include "ConjuntoCowboyAtirador.h"
#include <stdlib.h>
#include "Fase.h"

ConjuntoCowboyAtirador::ConjuntoCowboyAtirador(Fase* pF, GerenciadorGrafico* pgg, HeroiPreto* pJ1, HeroiVerde* pJ2):
    nInimigos(0),
    listapInis()
{
    srand(time(NULL));
    rand();
    nInimigos = (rand()%7) + 4;//de 4 a 10 CowboyPerseguidor
    cout << nInimigos << " CowboyPerseguidor" << endl;
    //11500 - 14300
    int delta = (14300-11500)/nInimigos;
    for (float i = 11500.0; i < 14300.0; i+=(float)delta)
    {
        listapInis.push_back(new CowboyAtirador(Vector2f(i, 700.f), pF, pgg, pJ1, pJ2));
    }    
}

ConjuntoCowboyAtirador::~ConjuntoCowboyAtirador()
{
}

void ConjuntoCowboyAtirador::adCowboyAtirador(Fase* pF)
{
    for (list<CowboyAtirador*>::iterator i = listapInis.begin(); i != listapInis.end(); i++)
    {
        pF->adEntidade(static_cast<Entidade*>(*i));
    }
}
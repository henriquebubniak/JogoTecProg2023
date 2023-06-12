#include "ConjuntoCowboyAtirador.h"
#include <stdlib.h>
#include "Fase.h"

ConjuntoCowboyAtirador::ConjuntoCowboyAtirador(Fase* pF, GerenciadorGrafico* pgg, HeroiPreto* pJ1, HeroiVerde* pJ2):
    nInimigos(0),
    listapInis()
{
    srand(time(NULL));
    rand();
    nInimigos = (rand()%8) + 3;//de 4 a 10 CowboyPerseguidor
    cout << nInimigos << " CowboyPerseguidor" << endl;
    //10300 - 13100
    int delta = (13100-10300)/nInimigos;
    for (float i = 10300.0; i < 13100.0; i+=(float)delta)
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
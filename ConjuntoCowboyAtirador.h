#pragma once
#include "CowboyAtirador.h"
#include <stdlib.h>
#include <time.h>
class ConjuntoCowboyAtirador
{
private:
    list<CowboyAtirador*> listapInis;
    int nInimigos;
public:
    ConjuntoCowboyAtirador(Fase* pF = NULL, GerenciadorGrafico* pgg = NULL, HeroiPreto* pJ1 = NULL, HeroiVerde* pJ2 = NULL);
    ~ConjuntoCowboyAtirador();
    void adCowboyAtirador(Fase* pF);
};


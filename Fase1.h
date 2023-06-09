#pragma once

#include "Fase.h"
#include "ConjuntoPlataformas.h"
#include "HeroiPreto.h"
#include "HeroiVerde.h"
#include "ConjuntoCowboyAtirador.h"
#include "ConjuntoCowboyPerseguidor.h"
#include "ConjuntoMinas.h"
#include "SuperVilao.h"
#include <algorithm>

class Fase1: public Fase
{
private:
    float gravidade;
    ConjuntoPlataformas conjPlataformas;
    HeroiPreto heroiPreto;
    HeroiVerde heroiVerde;
    ConjuntoCowboyAtirador conjCowboyAtirador;
    ConjuntoCowboyPerseguidor conjCowboyPerseguidor;
    SuperVilao superVilao;
    ConjuntoMinas conjMinas;
public:
    //Construtora e destrutora
    Fase1(GerenciadorGrafico* pgg = NULL, TelaMorte* tm = NULL);
    ~Fase1(){}
    Ente* getEnderecoJog2();
    float getG();
};


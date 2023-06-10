#pragma once

#include "Fase.h"
#include "ConjuntoPlataformas.h"
#include "HeroiPreto.h"
#include "HeroiVerde.h"
#include "ConjuntoCowboyAtirador.h"
#include "ConjuntoCowboyPerseguidor.h"
#include "ConjuntoMinas.h"
#include "ConjuntoLamas.h"
#include "SuperVilao.h"
#include <algorithm>

class Cidade: public Fase
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
    ConjuntoLamas conjLamas;
public:
    //Construtora e destrutora
    Cidade(GerenciadorGrafico* pgg = NULL, TelaMorte* tm = NULL);
    ~Cidade(){}
    Ente* getEnderecoJog2();
    float getG();
};


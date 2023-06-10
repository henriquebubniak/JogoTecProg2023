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

class Mar: public Fase
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
    Mar(GerenciadorGrafico* pgg = NULL, TelaMorte* tm = NULL);
    ~Mar(){}
    Ente* getEnderecoJog2();
    float getG();
    bool verificaAvancoDeFase();
};


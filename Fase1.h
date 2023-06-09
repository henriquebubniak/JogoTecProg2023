#pragma once

#include "Fase.h"
#include "Plataforma.h"
#include "HeroiPreto.h"
#include "HeroiVerde.h"
#include "CowboyAtirador.h"
#include "ConjuntoCowboyPerseguidor.h"
#include "SuperVilao.h"
#include <algorithm>

class Fase1: public Fase
{
private:
    float gravidade;
    Plataforma plataforma1;
    Plataforma plataforma2;
    Plataforma plataforma3;
    Plataforma plataforma4;
    Plataforma plataforma5;
    Plataforma plataforma6;
    Plataforma plataforma7;
    HeroiPreto heroiPreto;
    HeroiVerde heroiVerde;
    CowboyAtirador cowboyAtirador;
    ConjuntoCowboyPerseguidor conjCowboyPerseguidor;
    SuperVilao superVilao;
public:
    //Construtora e destrutora
    Fase1(GerenciadorGrafico* pgg = NULL, TelaMorte* tm = NULL);
    ~Fase1(){}
    Ente* getEnderecoJog2();
    float getG();
};


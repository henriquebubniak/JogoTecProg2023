#pragma once

#include "Inimigo.h"
#include "HeroiPreto.h"
#include "HeroiVerde.h"

class CowboyAtirador: public Inimigo
{
protected:
    int tirosTambor;
    float freqDisparos;
public:
    //Construtora e destrutora
    CowboyAtirador(Vector2f p = Vector2f(0.f, 0.f), Fase* f = NULL, GerenciadorGrafico* pgg = NULL, HeroiPreto* pJ1 = NULL, HeroiVerde* j = NULL);
    ~CowboyAtirador() {}
    //Funcionalidades
    void atacar();
    void mover();
    void morrer();
};
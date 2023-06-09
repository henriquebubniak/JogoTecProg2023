#pragma once

#include "Inimigo.h"
#include "HeroiPreto.h"
#include "HeroiVerde.h"

class CowboyPerseguidor: public Inimigo
{
protected:
    float alcance;
public:
    //Construtora e destrutora
    CowboyPerseguidor(Vector2f p = Vector2f(0.f, 0.f), Fase* f = NULL, GerenciadorGrafico* pgg = NULL, HeroiPreto* pJ1 = NULL, HeroiVerde* j = NULL);
    ~CowboyPerseguidor() {}
    //Funcionalidades
    void atacar();
    void mover();
    void morrer();
};
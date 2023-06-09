#pragma once

#include "Inimigo.h"
#include "HeroiPreto.h"
#include "HeroiVerde.h"

class SuperVilao: public Inimigo
{
protected:
    float forcaProj;
    int tirosTambor;
public:
    //Construtora e destrutora
    SuperVilao(Vector2f p = Vector2f(0.f, 0.f), Fase* f = NULL, GerenciadorGrafico* pgg = NULL, HeroiPreto* pJ1 = NULL, HeroiVerde* j = NULL);
    ~SuperVilao() {}
    //Funcionalidades
    void atacar();
    void mover();
    void morrer();
};
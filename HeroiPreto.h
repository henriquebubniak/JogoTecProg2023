#pragma once

#include "Jogador.h"
#include "HeroiVerde.h"

class HeroiPreto: public Jogador
{
protected:
    HeroiVerde* jog2;
    float freqDisparos;
public:
    //Construtora e destrutora
    HeroiPreto(Vector2f p = Vector2f(0.f, 0.f), Fase* f = NULL, GerenciadorGrafico* pgg = NULL, HeroiVerde* j = NULL);
    ~HeroiPreto() {}
    //Funcionalidades
    void atacar();
    void mover();
    void morrer();
};
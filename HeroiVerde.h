#pragma once

#include "Personagem.h"

class HeroiPreto;
class HeroiVerde: public Personagem
{
protected:
    float auxTempo;
    int tirosTambor;
    HeroiPreto* jog1;
public:
    //Construtora e destrutora
    HeroiVerde(Vector2f p = Vector2f(0.f, 0.f), Fase* f = NULL, GerenciadorGrafico* pgg = NULL, HeroiPreto* j = NULL);
    ~HeroiVerde() {}
    //Funcionalidades
    void atacar();
    void mover();
    void morrer();
};
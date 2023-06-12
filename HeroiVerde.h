#pragma once

#include "Jogador.h"

class HeroiPreto;
class HeroiVerde: public Jogador
{
protected:
    HeroiPreto* jog1;
    int forcaProjetil;
public:
    //Construtora e destrutora
    HeroiVerde(Vector2f p = Vector2f(0.f, 0.f), Fase* f = NULL, GerenciadorGrafico* pgg = NULL, HeroiPreto* j = NULL);
    ~HeroiVerde() {}
    //Funcionalidades
    void atacar();
    void mover();
    void morrer();
};
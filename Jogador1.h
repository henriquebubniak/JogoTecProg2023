#pragma once

#include "Personagem.h"
#include "Jogador2.h"

class Jogador1: public Personagem
{
protected:
    float auxTempo;
    int tirosTambor;
    Jogador2* jog2;
public:
    //Construtora e destrutora
    Jogador1(Vector2f p = Vector2f(0.f, 0.f), Fase* f = NULL, GerenciadorGrafico* pgg = NULL, Jogador2* j = NULL);
    ~Jogador1() {}
    //Funcionalidades
    void atacar();
    void mover();
    void morrer();
};
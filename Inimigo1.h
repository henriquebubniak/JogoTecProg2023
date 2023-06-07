#pragma once

#include "Inimigo.h"
#include "Jogador1.h"
#include "Jogador2.h"

class Inimigo1: public Inimigo
{
protected:
    int tirosTambor;
    float freqDisparos;
public:
    //Construtora e destrutora
    Inimigo1(Vector2f p = Vector2f(0.f, 0.f), Fase* f = NULL, GerenciadorGrafico* pgg = NULL, Jogador1* pJ1 = NULL, Jogador2* j = NULL);
    ~Inimigo1() {}
    //Funcionalidades
    void atacar();
    void mover();
    void morrer();
};
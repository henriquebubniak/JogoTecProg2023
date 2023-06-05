#pragma once

#include "Personagem.h"

class Jogador1;
class Jogador2: public Personagem
{
protected:
    float auxTempo;
    int tirosTambor;
    Jogador1* jog1;
public:
    //Construtora e destrutora
    Jogador2(Vector2f p = Vector2f(0.f, 0.f), Fase* f = NULL, GerenciadorGrafico* pgg = NULL, Jogador1* j = NULL);
    ~Jogador2() {}
    //Funcionalidades
    void atacar();
    void mover();
    void morrer();
};
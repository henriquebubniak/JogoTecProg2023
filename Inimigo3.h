#pragma once

#include "Inimigo.h"
#include "Jogador1.h"
#include "Jogador2.h"

class Inimigo3: public Personagem
{
protected:
    float auxTempo;
    int tirosTambor;
    Jogador1* pJog1;
    Jogador2* pJog2;
public:
    //Construtora e destrutora
    Inimigo3(Vector2f p = Vector2f(0.f, 0.f), Fase* f = NULL, GerenciadorGrafico* pgg = NULL, Jogador1* pJ1 = NULL, Jogador2* j = NULL);
    ~Inimigo3() {}
    //Funcionalidades
    void atacar();
    void mover();
    void morrer();
};
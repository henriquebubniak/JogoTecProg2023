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
    Jogador1(Vector2f p = Vector2f(0.f, 0.f), const char* cT = "./imagens/padrao.png", Fase* f = NULL, GerenciadorGrafico* pgg = NULL, int hp = 10, float v = 1, Jogador2* j = NULL);
    ~Jogador1() {}
    //Funcionalidades
    void ataca();
    void move();
    void morrer();
};
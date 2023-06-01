#pragma once

#include "Personagem.h"
#include "Jogador1.h"
#include "Jogador2.h"

class Inimigo: public Personagem
{
protected:
    float auxTempo;
    int tirosTambor;
    Jogador1* pJog1;
    Jogador2* pJog2;
public:
    //Construtora e destrutora
    Inimigo(Vector2f p = Vector2f(0.f, 0.f), const char* cT = "./imagens/padrao.png", Fase* f = NULL, GerenciadorGrafico* pgg = NULL, int hp = 10, float v = 1, Jogador1* pJ1 = NULL, Jogador2* j = NULL);
    ~Inimigo() {}
    //Funcionalidades
    void atacar();
    void mover();
    void morrer();
};
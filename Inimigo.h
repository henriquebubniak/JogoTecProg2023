#pragma once

#include "Personagem.h"
#include "Jogador1.h"
#include "Jogador2.h"

class Inimigo: public Personagem
{
protected:
    float auxTempo;
    Jogador1* pJog1;
    Jogador2* pJog2;
public:
    //Construtora e destrutora
    Inimigo(Vector2f p = Vector2f(0.f, 0.f), Fase* f = NULL, GerenciadorGrafico* pgg = NULL, int hp = 10, float v = 0.1, const char* cT = "./imagens/padrao.png", Jogador1* pJ1 = NULL, Jogador2* j = NULL);
    ~Inimigo() {}
    //Funcionalidades
    virtual void atacar() = 0;
    virtual void mover() = 0;
    virtual void morrer() = 0;
};
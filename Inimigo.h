#pragma once

#include "Personagem.h"
#include "HeroiPreto.h"
#include "HeroiVerde.h"

class Inimigo: public Personagem
{
protected:
    float auxTempo;
    HeroiPreto* pJog1;
    HeroiVerde* pJog2;
public:
    //Construtora e destrutora
    Inimigo(Vector2f p = Vector2f(0.f, 0.f), Fase* f = NULL, GerenciadorGrafico* pgg = NULL, int hp = 10, float v = 0.1, const char* cT = "./imagens/padrao.png", HeroiPreto* pJ1 = NULL, HeroiVerde* j = NULL);
    ~Inimigo() {}
    //Funcionalidades
    virtual void atacar() = 0;
    virtual void mover() = 0;
    virtual void morrer() = 0;
};
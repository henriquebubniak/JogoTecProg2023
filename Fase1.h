#pragma once

#include "Fase.h"
#include "Plataforma.h"
#include "Jogador1.h"
#include "Jogador2.h"
#include <algorithm>

class Fase1: public Fase
{
private:
    float gravidade;
    Plataforma plataforma1;
    Plataforma plataforma2;
    Plataforma plataforma3;
    Plataforma plataforma4;
    Plataforma plataforma5;
    Plataforma plataforma6;
    Jogador1 jogador1;
    Jogador2 jogador2;
public:
    //Construtora e destrutora
    Fase1(GerenciadorGrafico* pgg = NULL, TelaMorte* tm = NULL);
    ~Fase1(){}
    Ente* getEnderecoJog2();
    float getG();
};


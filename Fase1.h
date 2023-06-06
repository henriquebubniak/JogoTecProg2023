#pragma once

#include "Fase.h"
#include "Plataforma.h"
#include "Jogador1.h"
#include "Jogador2.h"
#include "Inimigo1.h"
#include "ConjuntoInimigos2.h"
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
    Plataforma plataforma7;
    Jogador1 jogador1;
    Jogador2 jogador2;
    Inimigo1 inimigo1;
    ConjuntoInimigos2 conjInis2;
public:
    //Construtora e destrutora
    Fase1(GerenciadorGrafico* pgg = NULL, TelaMorte* tm = NULL);
    ~Fase1(){}
    Ente* getEnderecoJog2();
    float getG();
};


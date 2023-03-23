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
    Ente fundoFase1;
    Jogador1 jogador1;
    Jogador2 jogador2;
public:
    //Construtora e destrutora
    Fase1(GerenciadorGrafico* pgg = NULL, Menu* m = NULL);
    ~Fase1(){}

    void adicionaJogador(int n);
    void adicionaPlataformas();
    float getG();
};


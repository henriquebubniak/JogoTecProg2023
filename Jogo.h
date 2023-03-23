#pragma once

#include "GerenciadorGrafico.h"
#include "Menu.h"
#include "Fase1.h"
#include <list>
#include <iostream>

using namespace std;

class Jogo
{
private:
    GerenciadorGrafico gg;
    Menu menu;
    Fase1 fase1;
public:
    //construtora e destrutora
    Jogo();
    ~Jogo();
    //carrega fases
    void carregaFase1(int nJ);
    void carregaFase2(int nJ);
};

#pragma once

#include "GerenciadorGrafico.h"
#include "Menu.h"
#include "Cidade.h"
#include "Mar.h"
#include "TelaMorte.h"
#include <list>
#include <iostream>

using namespace std;

class Jogo
{
private:
    GerenciadorGrafico gg;
    Menu menu;
    Cidade fase1;
    Mar fase2;
    TelaMorte telaMorte;
public:
    //construtora e destrutora
    Jogo();
    ~Jogo();
    //carrega fases
    void executar();
};

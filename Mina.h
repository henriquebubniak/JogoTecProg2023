#pragma once

#include "Obstaculo.h"


class Mina : public Obstaculo
{
private:
    int dano;
public:
    //construtora e destrutora
    Mina(Vector2f p = Vector2f(0.f, 0.f), Fase* pF = NULL, GerenciadorGrafico* pgg = NULL, int d = 10);
    ~Mina();

    //Funcoes
    void obstacular (Entidade* ent);
};



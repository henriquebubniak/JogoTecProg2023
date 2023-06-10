#pragma once

#include "Obstaculo.h"


class Lama : public Obstaculo
{
private:
    float viscosidade;
public:
    //construtora e destrutora
    Lama(Vector2f p = Vector2f(0.f, 0.f), Fase* pF = NULL, GerenciadorGrafico* pgg = NULL, float v = 0.07);
    ~Lama();

    //Funcoes
    void obstacular (Entidade* ent);
};



#pragma once

#include "Entidade.h"

class Plataforma: public Entidade
{
private:
    float empuxo;
public:
    //Construtora e destrutora
    Plataforma(Vector2f pos = Vector2f(0.f, 0.f), Fase* pf = NULL, GerenciadorGrafico* pgg = NULL);
    ~Plataforma(){}

    //Funcionalidades
    void dano(int d) {}
};


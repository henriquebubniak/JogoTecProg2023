#pragma once

#include "Obstaculo.h"

class Plataforma: public Obstaculo
{
private:
    float empuxo;
public:
    //Construtora e destrutora
    Plataforma(Vector2f pos = Vector2f(0.f, 0.f), const char* cT = "./imagens/padrao.png", Fase* pf = NULL, GerenciadorGrafico* pgg = NULL);
    ~Plataforma(){}

    //Funcionalidades
    void dano(int d) {}
};


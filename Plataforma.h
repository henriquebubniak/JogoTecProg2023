#pragma once

#include "Entidade.h"

class Plataforma: public Entidade
{
private:
public:
    //Construtora e destrutora
    Plataforma(Vector2f pos = Vector2f(0.f, 0.f), const char* cT = "./imagens/plataforma1.png", Fase* pf = NULL, GerenciadorGrafico* pgg = NULL);
    ~Plataforma(){}

    //Funcionalidades
    void dano(int d) {}
};


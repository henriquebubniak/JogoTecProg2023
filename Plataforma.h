#pragma once

#include "Entidade.h"

class Plataforma: public Entidade
{
private:
public:
    //Construtora e destrutora
    Plataforma(Vector2f pos, const char* cT = "./imagens/plataforma1.png", Fase* pf = NULL, GerenciadorGrafico* pgg = NULL);
    ~Plataforma(){}

    //Funcionalidades
    void ataca(){}
    void move(){}
    void dano(int d) {}
};


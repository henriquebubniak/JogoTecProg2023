#pragma once

#include "Entidade.h"

class Obstaculo: public Entidade
{
protected:
    bool danoso;
public:

    //construtora e destrutora
    Obstaculo(Vector2f pos, const char* caminhoTextura = "imagens/padrao.png", bool t = true);
    ~Obstaculo();

    //Fun��es
    virtual void aplicaEfeito(Entidade* ent) {}
    bool getDanoso();
};

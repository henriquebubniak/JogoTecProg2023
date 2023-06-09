#pragma once

#include "Personagem.h"

class Obstaculo: public Entidade
{
protected:
    bool danoso;
public:

    //construtora e destrutora
    Obstaculo(Vector2f pos = Vector2f(0.f, 0.f), const char* cT = "./imagens/padrao.png", Fase* f = NULL, GerenciadorGrafico* pgg = NULL, bool d = true);
    ~Obstaculo();

    //Fun��es
    virtual void obstacular(Entidade* ent) = 0;
    bool getDanoso();
};

#pragma once

#include "Personagem.h"

class Obstaculo: public Entidade
{
protected:
    bool danoso;
    bool perene;
public:

    //construtora e destrutora
    Obstaculo(Vector2f pos = Vector2f(0.f, 0.f), const char* cT = "./imagens/padrao.png", Fase* f = NULL, GerenciadorGrafico* pgg = NULL, bool d = true, bool p = true);
    ~Obstaculo();

    //Fun��es
    const bool getDanoso() const;
    const bool getPerene() const;
    void morrer();
    void mover();
};

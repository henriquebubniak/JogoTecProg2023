#pragma once

#include "Ente.h"
#include <iostream>
#include <list>

using namespace std;
using namespace sf;

class Fase;
class Entidade: public Ente
{
protected:
    Fase* pfase;
public:
    //Construtora e Destrutora
    Entidade(Vector2f p = Vector2f(0.f, 0.f), const char* cT = "./imagens/padrao.png", Fase* f = NULL, GerenciadorGrafico* pgg = NULL);
    virtual ~Entidade();

    //Funcionalidades
    virtual void morrer() {};
    virtual void ataca() {};
    virtual void move() {};

    //Sets e gets
    void setFase(Fase* f);
    virtual Vector2f getVelocidade();
    virtual void setVelocidadeX(float v){}
    virtual void setVelocidadeY(float v){}
    virtual void setPodePular(bool p){}
};
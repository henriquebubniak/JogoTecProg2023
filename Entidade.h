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
    Vector2f velocidade;
public:
    //Construtora e Destrutora
    Entidade(Vector2f p = Vector2f(0.f, 0.f), const char* cT = "./imagens/padrao.png", Fase* f = NULL, GerenciadorGrafico* pgg = NULL, Vector2f v = Vector2f(0.f, 0.f));
    virtual ~Entidade();

    //Funcionalidades
    virtual void morrer() {};
    virtual void atacar() {};
    virtual void mover() {};
    void executar();

    //Sets e gets
    void setFase(Fase* f);
    virtual Vector2f getVelocidade();
    virtual void setVelocidadeX(float v){}
    virtual void setVelocidadeY(float v){}
    virtual void setPodePular(bool p){}
};
#pragma once

#include "Entidade.h"

class Personagem: public Entidade
{
protected:
    int hp;
    bool vivo;
    float velPadrao;
    Vector2f velocidade;
    bool podePular;
    bool podeAtirar;
public:
    //construtora e destrutora
    Personagem(Vector2f p = Vector2f(0.f, 0.f),  const char* cT = "./imagens/padrao.png", Fase* f = NULL, GerenciadorGrafico* pgg = NULL, int h = 0, float v = 1);
    virtual ~Personagem();

    //Fun��es
    virtual void move() = 0;
    virtual void ataca() = 0;
    void recebeDano(int d);

    //Sets e gets
    void setPodePular (bool p);
    void setVelocidadeX(float v) {velocidade.x = 0;}
    void setVelocidadeY(float v) {velocidade.y = 0;}
    bool getVida() {return vivo;}
    void setVivo(bool v) {vivo = v;}
    void setHp(int h) {hp = h;}
};


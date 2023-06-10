#pragma once

#include "Entidade.h"

class Personagem: public Entidade
{
protected:
    int hp;
    bool vivo;
    float velPadrao;
    bool podePular;
    bool podeAtirar;
public:
    //construtora e destrutora
    Personagem(Vector2f p = Vector2f(0.f, 0.f), Fase* f = NULL, GerenciadorGrafico* pgg = NULL, int h = 0, float v = 1,  const char* cT = "./imagens/padrao.png");
    virtual ~Personagem();

    //Fun��es
    void receberDano(int d);

    //Sets e gets
    void setPodePular (bool p);
    void setVelocidadeX(float v) {velocidade.x = v;}
    void setVelocidadeY(float v) {velocidade.y = v;}
    bool getVida() {return vivo;}
    void setVivo(bool v) {vivo = v;}
    void setHp(int h) {hp = h;}
    int getHp() const {return hp;}
};


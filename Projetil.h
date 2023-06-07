#pragma once

#include "Entidade.h"
#include "Jogador.h"

class Projetil: public Entidade
{
private:
    int forca;
    Personagem* atirador;
public:
    //Construtora e destrutora
    Projetil(int f, Vector2f pos, Fase* pf = NULL, GerenciadorGrafico* pgg = NULL, float vel_x = 0.f, float vel_y = 0.0, Jogador* atirador = NULL);
    ~Projetil();

    //Funcionalidades
    void morrer();
    void setVelocidadeX(float v) {velocidade.x = v;}
    void setVelocidadeY(float v) {velocidade.y = v;}
    void mover();
    bool colide(Entidade* ent);
    void dano(int d) {}
    int getForca() const;
};


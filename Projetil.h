#pragma once

#include "Entidade.h"

class Projetil: public Entidade
{
private:
    int forca;
    Vector2f velocidade;
public:
    //Construtora e destrutora
    Projetil(int f, Vector2f pos, const char* caminhoTextura = "imagens/projetil.png", Fase* pf = NULL, GerenciadorGrafico* pgg = NULL, float vel_x = 0.f, float vel_y = 0.0);
    ~Projetil();

    //Funcionalidades
    void ataca(){}
    void morrer();
    void setVelocidadeX(float v) {velocidade.x = v;}
    void setVelocidadeY(float v) {velocidade.y = v;}
    void move();
    bool colide(Entidade* ent);
    void dano(int d) {}
    int get_forca ();
};


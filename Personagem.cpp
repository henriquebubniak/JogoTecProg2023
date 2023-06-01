#include "Personagem.h"
#include "Fase.h"

//Construtora e destrutora
Personagem::Personagem(Vector2f p, const char* cT, Fase* f, GerenciadorGrafico* pgg, int h, float v):
    Entidade(p, cT, f, pgg),
    hp(h),
    velPadrao(v),
    podePular(false),
    vivo(false)
{
    setID(1);
}
Personagem::~Personagem(){}

//Funcionalidades
void Personagem::receberDano(int d)
{
    hp -= d;
    velocidade = Vector2f(0.f, 0.f);
}

//Sets e gets
void Personagem:: setPodePular (bool p) {podePular = p;}
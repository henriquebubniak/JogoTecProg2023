#include "Mina.h"

Mina::Mina(Vector2f p, Fase* pF, GerenciadorGrafico* pgg, int d):
    Obstaculo(p, "imagens/mina.png", pF, pgg, true),
    dano(d)
{
}

Mina::~Mina()
{

}

void Mina:: obstacular(Entidade* ent){

    ent->receberDano(dano);
    ent->setVelocidadeY(-10.0f);
}

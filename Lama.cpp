#include "Lama.h"

Lama::Lama(Vector2f p, Fase* pF, GerenciadorGrafico* pgg, float v):
    Obstaculo(p, "imagens/mina.png", pF, pgg, true, false),
    viscosidade(v)
{
}

Lama::~Lama()
{

}

void Lama::obstacular(Entidade* ent)
{
    if (abs(ent->getVelocidade().x) > viscosidade)
    {
        if (ent->getVelocidade().x > 0)
        {
            ent->setVelocidadeX(viscosidade);
        }
        else
        {
            ent->setVelocidadeX(-viscosidade);
        }
    }
}
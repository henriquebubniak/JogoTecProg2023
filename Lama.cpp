#include "Lama.h"

Lama::Lama(Vector2f p, Fase* pF, GerenciadorGrafico* pgg, float v):
    Obstaculo(p, "imagens/lama.png", pF, pgg, false, true),
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
        ent->setPodePular(false);
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
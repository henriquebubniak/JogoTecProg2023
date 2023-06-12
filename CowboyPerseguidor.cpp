#include "CowboyPerseguidor.h"
#include "Fase.h"
#include <cmath>

CowboyPerseguidor::CowboyPerseguidor(Vector2f p, Fase* f, GerenciadorGrafico* pgg, HeroiPreto* pJ1, HeroiVerde* pJ2):
Inimigo (p, f, pgg, 20, 0.01, "./imagens/cowboyPerseguidor.png", pJ1, pJ2),
alcance(1250.0)
{
    setID(4);
}

void CowboyPerseguidor::mover()
{
    bool esquerda = true;
    Vector2f posicaoJog1 = pJog1->getPosicao();
    Vector2f posicaoIni = this->getPosicao();
    float dist = sqrt(((posicaoJog1.x-posicaoIni.x)*(posicaoJog1.x-posicaoIni.x)) +
                  ((posicaoJog1.y-posicaoIni.y)*(posicaoJog1.y-posicaoIni.y)));
    if (posicaoJog1.x < posicaoIni.x)
        esquerda = true;
    else
        esquerda = false;
    
    if (dist <= alcance)
    {
        if (esquerda)  
            velocidade.x -= velPadrao;

        else
            velocidade.x += velPadrao;
    }

    else
        velocidade.x -= velocidade.x*0.1;
    
    if (velocidade.x > 20*velPadrao)
        velocidade.x = 20*velPadrao;

    if (velocidade.x < -20*velPadrao)
        velocidade.x = -20*velPadrao;

    caixa.move(velocidade);
    velocidade.y += pfase->getG() * (0.016);
    podePular = false;
}
void CowboyPerseguidor::morrer()
{
    hp = 0;
    vivo = false;
    pfase->rmEntidade(static_cast <Entidade*> (this));
}
void CowboyPerseguidor::atacar()
{
}
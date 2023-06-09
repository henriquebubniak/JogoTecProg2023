#include "SuperVilao.h"
#include "Fase.h"
#include <cmath>

SuperVilao::SuperVilao(Vector2f p, Fase* f, GerenciadorGrafico* pgg, HeroiPreto* pJ1, HeroiVerde* pJ2):
Inimigo (p, f, pgg, 150, 0.01, "./imagens/superVilao.png", pJ1, pJ2),
tirosTambor(10),
forcaProj(7.0)
{
    setID(4);
}

void SuperVilao::mover()
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
    
    if (dist <= 1500)
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
void SuperVilao::morrer()
{
    hp = 0;
    vivo = false;
    pfase->rmEntidade(static_cast <Entidade*> (this));
}
void SuperVilao::atacar()
{
    Vector2f posicaoJog1 = pJog1->getPosicao();
    Vector2f posicaoIni = this->getPosicao();
    float dist = sqrt(((posicaoJog1.x-posicaoIni.x)*(posicaoJog1.x-posicaoIni.x)) +
                  ((posicaoJog1.y-posicaoIni.y)*(posicaoJog1.y-posicaoIni.y)));

    if ((dist < 1500) && podeAtirar)
    {
        float v = 10;
        float vx, vy;
        posicaoJog1.y+=200;
        float tg = (posicaoJog1.y - getPosicao().y - 50) / (posicaoJog1.x - getPosicao().x);
        if (tg < -0.08)
        {
            if(posicaoJog1.y < getPosicao().y)
                vx = v/sqrt(tg*tg + 1);
            else 
                vx = -v/sqrt(tg*tg + 1);
            vy = tg*vx;
        }
        else if (tg > 0.08)
        {
            if(posicaoJog1.y > getPosicao().y)
                vx = v/sqrt(tg*tg + 1);
            else 
                vx = -v/sqrt(tg*tg + 1);
            vy = tg*vx;
        }
        else
        {
            if (posicaoJog1.x > getPosicao().x)
                vx = v;
            else
                vx = -v;
            vy = 0;
        }
        Projetil* proj = new Projetil(forcaProj, Vector2f(getPosicao().x, getPosicao().y - 50), pfase, pGerenciadorGrafico, vx, vy);
        pfase->adEntidade(static_cast<Entidade*> (proj));
        podeAtirar = false;
        auxTempo = pfase->get_tempo();
        tirosTambor--;
    }

    else if ((pfase->get_tempo() - auxTempo) > 2000.0)
    {
        if (tirosTambor <= 0 && (pfase->get_tempo() - auxTempo) > 5000.0)
        {
            podeAtirar = true;
        }
        if (tirosTambor > 0)
            podeAtirar = true;
    }
}
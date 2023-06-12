#include "HeroiPreto.h"
#include "Fase.h"
#include <cmath>

HeroiPreto::HeroiPreto(Vector2f p, Fase* f, GerenciadorGrafico* pgg, HeroiVerde* j):
    Jogador (p, f, pgg, 1000, 0.1, "./imagens/heroiPreto.png"),
    jog2(j),
    freqDisparos(300.0)
{}

void HeroiPreto::mover()
{
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        velocidade.x += velPadrao;
    }
    else if (Keyboard::isKeyPressed(Keyboard::A))
    {
        velocidade.x -= velPadrao;
    }
    else
        velocidade.x -= velocidade.x*0.1;
    if (Keyboard::isKeyPressed(Keyboard::Space) && podePular)
    {
        velocidade.y = -40*velPadrao;
    }
    if (velocidade.x > 20*velPadrao)
        velocidade.x = 20*velPadrao;
    if (velocidade.x < -20*velPadrao)
        velocidade.x = -20*velPadrao;
    caixa.move(velocidade);
    velocidade.y += pfase->getG() * (0.016);
    podePular = false;
    pGerenciadorGrafico->setPosicaoView(Vector2f(getPosicao().x + 600, 650.0));
}
void HeroiPreto::morrer()
{
    hp = 0;
    vivo = false;
    pfase->rmEntidade(static_cast <Entidade*> (this));
    if (!jog2->getVida())
        pfase->carregaTelaMorte();
}
void HeroiPreto::atacar()
{
    if (Keyboard::isKeyPressed(Keyboard::F) && podeAtirar)
    {
        float v = 4;
        float vx, vy;
        Vector2f posicaoMouse = pGerenciadorGrafico->converteCoord(Mouse::getPosition());
        posicaoMouse.y-=1875;
        float tg = (posicaoMouse.y - getPosicao().y - 50) / (posicaoMouse.x - getPosicao().x);
        if (tg < -0.08)
        {
            if(posicaoMouse.y < getPosicao().y)
                vx = v/sqrt(tg*tg + 1);
            else 
                vx = -v/sqrt(tg*tg + 1);
            vy = tg*vx;
        }
        else if (tg > 0.08)
        {
            if(posicaoMouse.y > getPosicao().y)
                vx = v/sqrt(tg*tg + 1);
            else 
                vx = -v/sqrt(tg*tg + 1);
            vy = tg*vx;
        }
        else
        {
            if (posicaoMouse.x > getPosicao().x)
                vx = v;
            else
                vx = -v;
            vy = 0;
        }
        Projetil* proj = new Projetil(7, Vector2f(getPosicao().x, getPosicao().y - 50), pfase, pGerenciadorGrafico, vx, vy);
        pfase->adEntidade(static_cast<Entidade*> (proj));
        podeAtirar = false;
        auxTempo = pfase->get_tempo();
        tirosTambor--;
    }

    else if ((pfase->get_tempo() - auxTempo) > freqDisparos && !Keyboard::isKeyPressed(Keyboard::F))
    {
        if (tirosTambor > 0)
            podeAtirar = true;
        tirosTambor = 10;
    }
}
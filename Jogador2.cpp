#include "Jogador2.h"
#include "Jogador1.h"
#include "Fase.h"
#include <cmath>

Jogador2::Jogador2(Vector2f p, Fase* f, GerenciadorGrafico* pgg, Jogador1* j):
Personagem (p, f, pgg, 10, 0.1, "./imagens/jogador2.png"),
tirosTambor(5),
jog1(j)
{}

void Jogador2::mover()
{
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        velocidade.x += velPadrao;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        velocidade.x -= velPadrao;
    }
    else
        velocidade.x -= velocidade.x*0.1;
    if (Keyboard::isKeyPressed(Keyboard::Up) && podePular)
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
    pGerenciadorGrafico->setPosicaoView(Vector2f(getPosicao().x, getPosicao().y - 700));
}
void Jogador2::morrer()
{
    hp = 0;
    vivo = false;
    pfase->rmEntidade(static_cast <Entidade*> (this));
    if (!jog1->getVida())
        pfase->carregaTelaMorte();
}
void Jogador2::atacar()
{
    if (Keyboard::isKeyPressed(Keyboard::K) && podeAtirar)
    {
        float v = 10.0;
        float vx, vy;
        Vector2f posicaoMouse = pGerenciadorGrafico->converteCoord(Mouse::getPosition());
        posicaoMouse.y-=2500;
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
        cout << "velocidade" << vx << ", " << vy << endl;
        Projetil* proj = new Projetil(7, Vector2f(getPosicao().x, getPosicao().y - 50), "./imagens/projetil.png", pfase, pGerenciadorGrafico, vx, vy);
        pfase->adEntidade(static_cast<Entidade*> (proj));
        podeAtirar = false;
        auxTempo = pfase->get_tempo();
        tirosTambor--;
    }

    else if ((pfase->get_tempo() - auxTempo) > 300.0 && !Keyboard::isKeyPressed(Keyboard::F))
    {
        if (tirosTambor > 0)
            podeAtirar = true;
    }
}
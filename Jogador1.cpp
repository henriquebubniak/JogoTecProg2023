#include "Jogador1.h"
#include "Fase.h"
#include <cmath>

Jogador1::Jogador1(Vector2f p, const char* cT, Fase* f, GerenciadorGrafico* pgg , int h, float v, Jogador2* j):
Personagem (p, cT, f, pgg, h, v),
tirosTambor(10),
jog2(j),
auxTempo(0.0)
{}

void Jogador1::mover()
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
    pGerenciadorGrafico->setPosicaoView(Vector2f(getPosicao().x, getPosicao().y - 200));
}
void Jogador1::morrer()
{
    hp = 0;
    vivo = false;
    pfase->rmEntidade(static_cast <Entidade*> (this));
    if (!jog2->getVida())
        pfase->carregaTelaMorte();
}
void Jogador1::atacar()
{
    if (Keyboard::isKeyPressed(Keyboard::F) && podeAtirar)
    {
        float vx, vy;
        Vector2f posicaoMouse = pGerenciadorGrafico->converteCoord(Mouse::getPosition());
        posicaoMouse.y-=2500;
        float tg = (posicaoMouse.y - getPosicao().y - 50) / (posicaoMouse.x - getPosicao().x);
        cout << "mouse " << posicaoMouse.x << ", " << posicaoMouse.y - 50 << endl;
        cout << "personagem " << getPosicao().x << ", " << getPosicao().y << endl;
        cout << "tangente " << tg << endl;
        if (tg < -0.08)
        {
            if(posicaoMouse.y < getPosicao().y)
                vx = 14/sqrt(tg*tg + 1);
            else 
                vx = -14/sqrt(tg*tg + 1);
            vy = tg*vx;
        }
        else if (tg > 0.08)
        {
            if(posicaoMouse.y > getPosicao().y)
                vx = 14/sqrt(tg*tg + 1);
            else 
                vx = -14/sqrt(tg*tg + 1);
            vy = tg*vx;
        }
        else
        {
            if (posicaoMouse.x > getPosicao().x)
                vx = 14;
            else
                vx = -14;
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
        if (tirosTambor <= 0 && (pfase->get_tempo() - auxTempo) > 2000.0)
        {
            podeAtirar = true;
            tirosTambor = 10;
        }
        if (tirosTambor > 0)
            podeAtirar = true;
    }
}
#include "Fase1.h"

Fase1::Fase1(GerenciadorGrafico* pgg, TelaMorte* tm):
Fase(pgg, tm),
gravidade(2),
plataforma1(Vector2f(0.f,1450.f), "./imagens/plataforma1.png", static_cast <Fase*> (this), pgg),
plataforma2(Vector2f(1600.f,1300.f), "./imagens/plataforma2.png", static_cast <Fase*> (this), pgg),
plataforma3(Vector2f(1700.f,1450.f), "./imagens/plataforma3.png", static_cast <Fase*> (this), pgg),
jogador1(Vector2f(0.f,0.f), "./imagens/jogador1.png", static_cast <Fase*> (this), pgg, 10, 0.1, &jogador2),
jogador2(Vector2f(300.f,0.f), "./imagens/jogador2.png", static_cast <Fase*> (this), pgg, 10, 0.1, &jogador1)
{
    setImagem("./imagens/fundoFase1.png");
    adEntidade(static_cast <Entidade*> (&plataforma1));
    adEntidade(static_cast <Entidade*> (&plataforma2));
    adEntidade(static_cast <Entidade*> (&plataforma3));
    adEntidade(static_cast <Entidade*> (&jogador1));
    adEntidade(static_cast <Entidade*> (&jogador2));
}

float Fase1::getG() {return gravidade;}

void Fase1::removeJogador2()
{
    listaEntidade.remove(&jogador2);
}

void Fase1::adicionaJogador2()
{
    if (find(listaEntidade.begin(), listaEntidade.end(), &jogador2) == listaEntidade.end())
        listaEntidade.push_front(&jogador2);
}
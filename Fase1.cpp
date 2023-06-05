#include "Fase1.h"

Fase1::Fase1(GerenciadorGrafico* pgg, TelaMorte* tm):
Fase(pgg, tm),
gravidade(1),
plataforma1(Vector2f(0.f,1450.f), "./imagens/plataforma1.png", static_cast <Fase*> (this), pgg),
plataforma2(Vector2f(1600.f,1300.f), "./imagens/plataforma2.png", static_cast <Fase*> (this), pgg),
plataforma3(Vector2f(1700.f,1450.f), "./imagens/plataforma1.png", static_cast <Fase*> (this), pgg),
plataforma4(Vector2f(3300.f,1450.f), "./imagens/plataforma1.png", static_cast <Fase*> (this), pgg),
plataforma5(Vector2f(4500.f,1450.f), "./imagens/plataforma1.png", static_cast <Fase*> (this), pgg),
plataforma6(Vector2f(3900.f,1000.f), "./imagens/plataforma1.png", static_cast <Fase*> (this), pgg),
jogador1(Vector2f(0.f,0.f), static_cast <Fase*> (this), pgg, &jogador2),
jogador2(Vector2f(300.f,0.f), static_cast <Fase*> (this), pgg, &jogador1),
inimigo1(Vector2f(1600.f, 0.f), static_cast <Fase*> (this), pgg, &jogador1, &jogador2),
inimigo2(Vector2f(4000.f, 0.f), static_cast <Fase*> (this), pgg, &jogador1, &jogador2)
{
    setImagem("./imagens/fundoFase1.png");
    adEntidade(static_cast <Entidade*> (&plataforma1));
    adEntidade(static_cast <Entidade*> (&plataforma2));
    adEntidade(static_cast <Entidade*> (&plataforma3));
    adEntidade(static_cast <Entidade*> (&plataforma4));
    adEntidade(static_cast <Entidade*> (&plataforma5));
    adEntidade(static_cast <Entidade*> (&plataforma6));
    adEntidade(static_cast <Entidade*> (&jogador1));
    adEntidade(static_cast <Entidade*> (&jogador2));
    adEntidade(static_cast <Entidade*> (&inimigo1));
    adEntidade(static_cast <Entidade*> (&inimigo2));
}

float Fase1::getG() {return gravidade;}

Ente* Fase1::getEnderecoJog2()
{
    return static_cast<Ente*>(&jogador2);
}
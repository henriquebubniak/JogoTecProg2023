#include "Fase1.h"

Fase1::Fase1(GerenciadorGrafico* pgg, TelaMorte* tm):
Fase(pgg, tm, "./imagens/fundoFase1.jpg"),
gravidade(1),
plataforma1(Vector2f(0.f,1450.f), "./imagens/plataforma1.png", static_cast <Fase*> (this), pgg),
plataforma3(Vector2f(1500.f,1450.f), "./imagens/plataforma1.png", static_cast <Fase*> (this), pgg),
plataforma4(Vector2f(3300.f,1450.f), "./imagens/plataforma1.png", static_cast <Fase*> (this), pgg),
plataforma5(Vector2f(4500.f,1450.f), "./imagens/plataforma1.png", static_cast <Fase*> (this), pgg),
plataforma6(Vector2f(3900.f,1000.f), "./imagens/plataforma1.png", static_cast <Fase*> (this), pgg),
plataforma7(Vector2f(5700.f,1000.f), "./imagens/plataforma1.png", static_cast <Fase*> (this), pgg),
heroiPreto(Vector2f(0.f,0.f), static_cast <Fase*> (this), pgg, &heroiVerde),
heroiVerde(Vector2f(300.f,0.f), static_cast <Fase*> (this), pgg, &heroiPreto),
cowboyAtirador(Vector2f(1600.f, 0.f), static_cast <Fase*> (this), pgg, &heroiPreto, &heroiVerde),
conjCowboyPerseguidor(static_cast <Fase*> (this), pgg, &heroiPreto, &heroiVerde),
superVilao(Vector2f(5900.f, 0.f), static_cast <Fase*> (this), pgg, &heroiPreto, &heroiVerde),
conjMinas(static_cast<Fase*>(this), pgg)

{
    adEntidade(static_cast <Entidade*> (&plataforma1));
    adEntidade(static_cast <Entidade*> (&plataforma3));
    adEntidade(static_cast <Entidade*> (&plataforma4));
    adEntidade(static_cast <Entidade*> (&plataforma5));
    adEntidade(static_cast <Entidade*> (&plataforma6));
    adEntidade(static_cast <Entidade*> (&plataforma7));
    adEntidade(static_cast <Entidade*> (&heroiPreto));
    adEntidade(static_cast <Entidade*> (&heroiVerde));
    adEntidade(static_cast <Entidade*> (&cowboyAtirador));
    conjCowboyPerseguidor.adCowboyPerseguidor(static_cast <Fase*> (this));
    adEntidade(static_cast <Entidade*> (&superVilao));
    conjMinas.adMina(static_cast<Fase*>(this));
}

float Fase1::getG() {return gravidade;}

Ente* Fase1::getEnderecoJog2()
{
    return static_cast<Ente*>(&heroiVerde);
}
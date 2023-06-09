#include "Fase1.h"

Fase1::Fase1(GerenciadorGrafico* pgg, TelaMorte* tm):
Fase(pgg, tm, "./imagens/fundoFase1.jpg"),
gravidade(1),
conjPlataformas(static_cast<Fase*>(this), pgg),
heroiPreto(Vector2f(0.f,0.f), static_cast <Fase*> (this), pgg, &heroiVerde),
heroiVerde(Vector2f(300.f,0.f), static_cast <Fase*> (this), pgg, &heroiPreto),
conjCowboyAtirador(static_cast <Fase*> (this), pgg, &heroiPreto, &heroiVerde),
conjCowboyPerseguidor(static_cast <Fase*> (this), pgg, &heroiPreto, &heroiVerde),
superVilao(Vector2f(15500.f, 0.f), static_cast <Fase*> (this), pgg, &heroiPreto, &heroiVerde),
conjMinas(static_cast<Fase*>(this), pgg)

{
    conjPlataformas.adPlataforma(static_cast<Fase*>(this));
    adEntidade(static_cast <Entidade*> (&heroiPreto));
    adEntidade(static_cast <Entidade*> (&heroiVerde));
    conjCowboyAtirador.adCowboyAtirador(static_cast<Fase*>(this));
    conjCowboyPerseguidor.adCowboyPerseguidor(static_cast <Fase*> (this));
    adEntidade(static_cast <Entidade*> (&superVilao));
    conjMinas.adMina(static_cast<Fase*>(this));
}

float Fase1::getG() {return gravidade;}

Ente* Fase1::getEnderecoJog2()
{
    return static_cast<Ente*>(&heroiVerde);
}
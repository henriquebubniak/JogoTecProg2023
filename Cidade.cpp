#include "Cidade.h"

Cidade::Cidade(GerenciadorGrafico* pgg, TelaMorte* tm, Fase* proxF):
Fase(pgg, tm, "./imagens/fundoCidade.jpg", proxF),
gravidade(1),
conjPlataformas(static_cast<Fase*>(this), pgg),
heroiPreto(Vector2f(0.f,0.f), static_cast <Fase*> (this), pgg, &heroiVerde),
heroiVerde(Vector2f(300.f,0.f), static_cast <Fase*> (this), pgg, &heroiPreto),
conjCowboyAtirador(static_cast <Fase*> (this), pgg, &heroiPreto, &heroiVerde),
conjCowboyPerseguidor(static_cast <Fase*> (this), pgg, &heroiPreto, &heroiVerde),
superVilao(Vector2f(13300.f, 0.f), static_cast <Fase*> (this), pgg, &heroiPreto, &heroiVerde),
conjMinas(static_cast<Fase*>(this), pgg),
conjLamas(static_cast<Fase*>(this), pgg)

{
    conjPlataformas.adPlataforma(static_cast<Fase*>(this));
    conjMinas.adMina(static_cast<Fase*>(this));
    conjLamas.adLama(static_cast<Fase*>(this));
    adEntidade(static_cast <Entidade*> (&heroiPreto));
    adEntidade(static_cast <Entidade*> (&heroiVerde));
    conjCowboyAtirador.adCowboyAtirador(static_cast<Fase*>(this));
    conjCowboyPerseguidor.adCowboyPerseguidor(static_cast <Fase*> (this));
    adEntidade(static_cast <Entidade*> (&superVilao));
}

float Cidade::getG() {return gravidade;}

Ente* Cidade::getEnderecoJog2()
{
    return static_cast<Ente*>(&heroiVerde);
}

bool Cidade::verificaAvancoDeFase()
{
    if (heroiPreto.getPosicao().x >= 13300)
    {
        return true;
    }
    return false;
    
}
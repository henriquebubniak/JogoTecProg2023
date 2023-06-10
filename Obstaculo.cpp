#include "Obstaculo.h"
#include "Fase.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Obstaculo::Obstaculo(Vector2f pos, const char* cT, Fase* f, GerenciadorGrafico* pgg, bool d, bool p):
Entidade(pos, cT, f, pgg, Vector2f(0.f, 0.f)),
danoso(d),
perene(p)
{
    setID(5);
}

Obstaculo::~Obstaculo()
{
}

/*===================================================================*/

const bool Obstaculo:: getDanoso() const{
    return danoso;
}
const bool Obstaculo:: getPerene() const{
    return perene;
}

void Obstaculo::morrer()
{
    pfase->rmEntidade(static_cast<Entidade*>(this));
    delete(this);
}

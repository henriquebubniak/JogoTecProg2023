#include "Obstaculo.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Obstaculo::Obstaculo(Vector2f pos, const char* cT, Fase* f, GerenciadorGrafico* pgg, bool d):
Entidade(pos, cT, f, pgg, Vector2f(0.f, 0.f)),
danoso(d)
{
}

Obstaculo::~Obstaculo()
{
}

/*===================================================================*/

bool Obstaculo:: getDanoso(){
    return danoso;
}

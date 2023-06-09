#include "Obstaculo.h"

/*==================CONSTRUTORA E DESTRUTORA=========================*/

Obstaculo::Obstaculo(Vector2f pos, const char* caminhoTextura,  bool d):
Entidade(pos, caminhoTextura)
{
    danoso = d;
}

Obstaculo::~Obstaculo()
{
}

/*===================================================================*/

bool Obstaculo:: getDanoso(){
    return danoso;
}

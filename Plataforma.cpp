#include "Plataforma.h"
#include "Fase.h"

Plataforma::Plataforma(Vector2f pos, const char* cT, Fase* pf, GerenciadorGrafico* pgg):
Obstaculo(pos, cT, pf, pgg, false, true)
{
    empuxo = pfase->getG() * (0.016);
}

void Plataforma::mover()
{
    caixa.move(velocidade);
    velocidade.y += pfase->getG() * (0.016);
    velocidade.y -= empuxo;
    velocidade.x *= 0.999;
}
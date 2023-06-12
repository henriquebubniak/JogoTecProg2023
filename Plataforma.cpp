#include "Plataforma.h"

Plataforma::Plataforma(Vector2f pos, const char* cT, Fase* pf, GerenciadorGrafico* pgg):
Obstaculo(pos, cT, pf, pgg, false, true)
{}
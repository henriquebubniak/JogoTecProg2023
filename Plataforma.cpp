#include "Plataforma.h"

Plataforma::Plataforma(Vector2f pos, Fase* pf, GerenciadorGrafico* pgg):
Obstaculo(pos, "./imagens/plataforma.png", pf, pgg, false, true)
{}
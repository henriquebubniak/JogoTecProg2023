#include "Inimigo.h"
#include "Fase.h"
#include <cmath>

Inimigo::Inimigo(Vector2f p, Fase* f, GerenciadorGrafico* pgg, int hp, float v, const char* cT, Jogador1* pJ1, Jogador2* pJ2):
Personagem (p, f, pgg, hp, v, cT),
pJog1(pJ1),
pJog2(pJ2),
auxTempo(0.0)
{
    setID(4);
}
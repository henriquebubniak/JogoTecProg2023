#include "Jogador.h"

Jogador::Jogador(Vector2f p, Fase* f, GerenciadorGrafico* pgg, int h, float v,  const char* cT):
    Personagem(p, f, pgg, h, v, cT),
    auxTempo(0.0),
    tirosTambor(5)
{
    setID(3);
}

Jogador::~Jogador()
{
}
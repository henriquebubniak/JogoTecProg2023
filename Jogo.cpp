#include "Jogo.h"

//Construtora e destrutora
Jogo::Jogo():
gg(),
menu(&gg, &fase1),
fase1(&gg, &telaMorte),
telaMorte(&gg, &fase1)
{menu.executar();}
Jogo::~Jogo()
{}

void Jogo::carregaFase1(int nJ)
{
    fase1.executaFase(nJ);
}
void Jogo::carregaFase2(int nJ)
{
}
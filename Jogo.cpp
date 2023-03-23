#include "Jogo.h"

//Construtora e destrutora
Jogo::Jogo():
gg(),
menu(&gg, this),
fase1(&gg, &menu)
{menu.executa_menu();}
Jogo::~Jogo()
{}

void Jogo::carregaFase1(int nJ)
{
    fase1.executaFase(nJ);
}
void Jogo::carregaFase2(int nJ)
{
}
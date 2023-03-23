#include "Botao.h"
#include "Menu.h"

//Construtora
Botao::Botao (const char* cT, Vector2f p, Menu* m, int i):
Ente(cT), menu(m), id(i)
{
    caixa.setPosition (p);
}

//Funcionalidades
void Botao::acao()
{
    if (id == 1)
        menu->selecaoNJogadores1();
    if (id == 2)
        menu->selecaoNJogadores2();
    if (id == 3)
    {}
    if (id == 4)
    {}
    if (id == 5)
        menu->carregaFase1(1);
    if (id == 6)
        menu->carregaFase1(2);
}
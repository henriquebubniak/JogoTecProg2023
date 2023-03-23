#pragma once

#include "Ente.h"
#include "GerenciadorGrafico.h"
#include "Botao.h"
#include "CursorMenu.h"
#include <list>
using namespace std;

class Jogo;
class Menu
{
private:
    GerenciadorGrafico* pGerenciadorGrafico;
    Ente planoDeFundo;
    Ente voceMorreu;
    Jogo* jogo;
    list<Botao*> listaBotoes;
    CursorMenu cursor;
public:
    //construtora e destrutora
    Menu(GerenciadorGrafico* pgg, Jogo* j);
    ~Menu();

    //metodos
    void executa_menu();
    void selecaoNJogadores1();
    void selecaoNJogadores2();
    void carregaFase1(int nJ);
    void carregaFase2(int nJ);
    void telaMorte();
};

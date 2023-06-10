#pragma once
#include "Ente.h"
#include "Botao.h"
#include "CursorBot.h"
#include "GerenciadorGrafico.h"
#include <list>
using namespace std;
class Cidade;
class Menu;
class TelaMorte: public Ente 
{
private:
    int nJogadores;
    list<Botao<TelaMorte>*> listaBotoes;
    CursorBot<TelaMorte> cursor;
    Cidade* pFase1;
    Menu* menu;
public:
    TelaMorte(GerenciadorGrafico* pgg = NULL, Cidade* pf1 = NULL);
    ~TelaMorte();
    void executar(int nJ = 1);
    void desenhar();
    void recomecarFase();
    void salvarPontuacao();
    void voltarMenu();

};
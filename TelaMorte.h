#pragma once
#include "Ente.h"
#include "Botao.h"
#include "CursorBot.h"
#include "GerenciadorGrafico.h"
#include <list>
using namespace std;
class Fase1;
class Menu;
class TelaMorte: public Ente 
{
private:
    int nJogadores;
    list<Botao<TelaMorte>*> listaBotoes;
    CursorBot<TelaMorte> cursor;
    Fase1* pFase1;
    Menu* menu;
public:
    TelaMorte(GerenciadorGrafico* pgg = NULL, Fase1* pf1 = NULL);
    ~TelaMorte();
    void executar(int nJ = 1);
    void incluirEntes();
    void recomecarFase();
    void salvarPontuacao();
    void voltarMenu();

};
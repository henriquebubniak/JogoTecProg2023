#pragma once

#include "Ente.h"
#include "GerenciadorGrafico.h"
#include "Botao.h"
#include "Cidade.h"
#include "Fase2.h"
#include "CursorBot.h"
#include <list>
using namespace std;

class Menu: public Ente
{
private:
    Cidade* pFase1;
    list<Botao<Menu>*> listaBotoes;
    CursorBot<Menu> cursor;
    bool clique;
public:
    //construtora e destrutora
    Menu(GerenciadorGrafico* pgg = NULL, Cidade* pf1 = NULL);
    ~Menu();

    //metodos
    void executar();
    void desenhar();
    void carrega1Fase1jog();
    void carrega1Fase2jog();
    void carrega2Fase1jog();
    void carrega2Fase2jog();
};

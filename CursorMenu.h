#pragma once
#include "Ente.h"
#include "Botao.h"
#include <list>
using namespace std;

class CursorMenu: public Ente
{
protected:    
    list<Botao*>::iterator iteradorb;
    list<Botao*>* pListaBotoes;
public:
    CursorMenu(const char* cT = "imagens/cursor.png", list<Botao*>* plb = NULL);
    ~CursorMenu() {}
    void setIterador(list<Botao*>::iterator ib);
    void avanca();
    void volta();
    void acao();
};
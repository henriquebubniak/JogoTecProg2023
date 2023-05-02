#pragma once
#include "Ente.h"
#include "Botao.h"
#include <list>
using namespace std;

class CursorBot: public Ente
{
protected:    
    list<Botao*>::iterator iteradorb;
    list<Botao*>* pListaBotoes;
public:
    CursorBot(const char* cT = "imagens/CursorBot.png", list<Botao*>* plb = NULL);
    ~CursorBot() {}
    void setIterador(list<Botao*>::iterator ib);
    void avanca();
    void volta();
    void acao();
};
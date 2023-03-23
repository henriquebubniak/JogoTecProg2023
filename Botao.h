#pragma once
#include "Ente.h"
#include <iostream>
using namespace std;

class Menu;
class Botao: public Ente
{
protected:    
    int id;
    Menu* menu;
public:
    Botao(const char* cT = "imagens/padrao.png", Vector2f p = Vector2f(0.f, 0.f), Menu* m = NULL, int i = -1);
    ~Botao() {menu = NULL;}
    void acao();
};
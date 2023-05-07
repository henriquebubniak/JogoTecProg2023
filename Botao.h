#pragma once
#include "Ente.h"
#include <iostream>
#include <functional>
using namespace std;

template <typename T>
class Botao: public Ente
{
protected:    
    void (T::*funcao)();
    T* tipo;
public:
    Botao(const char* cT = "imagens/padrao.png", GerenciadorGrafico* pgg = NULL, Vector2f p = Vector2f(0.f, 0.f), T* t = NULL, void (T::*f)() = NULL):
    Ente(cT, pgg), tipo(t), funcao(f)
    {
        caixa.setPosition (p);
    }
    ~Botao() {tipo = NULL;}
    void acao()
    {
        (tipo->*funcao)();
    }
};
#pragma once
#include "Ente.h"
#include "Botao.h"
#include <list>
using namespace std;

template <typename T>
class CursorBot: public Ente
{
protected:    
    typename list<Botao<T>*>::iterator iteradorb;
    list<Botao<T>*>* pListaBotoes;
public:
    CursorBot(const char* cT = "imagens/CursorBot.png", GerenciadorGrafico* pgg = NULL,list<Botao<T>*>* plb = NULL):
    Ente (cT, pgg), pListaBotoes(plb)
    {}
    ~CursorBot() {}
    void setIterador(typename list<Botao<T>*>::iterator ib)
    {
        iteradorb = ib;
        caixa.setPosition((*iteradorb)->getPosicao() - Vector2f(100.f, 0.f));
    }
    void avanca()
    {
        if(iteradorb != --pListaBotoes->end())
        {
            iteradorb++;
            caixa.setPosition((*iteradorb)->getPosicao() - Vector2f(100.f, 0.f));
        }    
    }
    void volta()
    {
        if(iteradorb != pListaBotoes->begin())
        {
            iteradorb--;
            caixa.setPosition((*iteradorb)->getPosicao() - Vector2f(100.f, 0.f));
        }    
    }
    void acao()
    {
        (*iteradorb)->acao();
    }
};
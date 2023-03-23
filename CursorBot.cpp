#include "CursorBot.h"

//Construtora
CursorBot::CursorBot (const char* cT, list<Botao*>* plb):
Ente (cT), pListaBotoes(plb)
{}

//Sets
void CursorBot::setIterador (list<Botao*>::iterator ib)
{
    iteradorb = ib;
    caixa.setPosition((*iteradorb)->getPosicao() - Vector2f(100.f, 0.f));
}

//Funcionalidades
void CursorBot::avanca()
{
    if(iteradorb != --pListaBotoes->end())
    {
        iteradorb++;
        caixa.setPosition((*iteradorb)->getPosicao() - Vector2f(100.f, 0.f));
    }    
}
void CursorBot::volta()
{
    if(iteradorb != pListaBotoes->begin())
    {
        iteradorb--;
        caixa.setPosition((*iteradorb)->getPosicao() - Vector2f(100.f, 0.f));
    }    
}
void CursorBot::acao() {(*iteradorb)->acao();}
#include "CursorMenu.h"

//Construtora
CursorMenu::CursorMenu (const char* cT, list<Botao*>* plb):
Ente (cT), pListaBotoes(plb)
{}

//Sets
void CursorMenu::setIterador (list<Botao*>::iterator ib)
{
    iteradorb = ib;
    caixa.setPosition((*iteradorb)->getPosicao() - Vector2f(100.f, 0.f));
}

//Funcionalidades
void CursorMenu::avanca()
{
    if(iteradorb != --pListaBotoes->end())
    {
        iteradorb++;
        caixa.setPosition((*iteradorb)->getPosicao() - Vector2f(100.f, 0.f));
    }    
}
void CursorMenu::volta()
{
    if(iteradorb != pListaBotoes->begin())
    {
        iteradorb--;
        caixa.setPosition((*iteradorb)->getPosicao() - Vector2f(100.f, 0.f));
    }    
}
void CursorMenu::acao() {(*iteradorb)->acao();}
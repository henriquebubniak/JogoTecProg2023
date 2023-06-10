#include "TelaMorte.h"
#include "Cidade.h"
#include "Menu.h" 

TelaMorte::TelaMorte(GerenciadorGrafico* pgg, Cidade* pf1):
Ente("./imagens/TelaMorte.png", pgg),
listaBotoes(),
cursor("./imagens/cursor.png", pgg, &listaBotoes),
nJogadores(1)
{
    listaBotoes.push_back(new Botao<TelaMorte>("./imagens/Recomecar.png", pgg, Vector2f(1400.f,400.f), this, &TelaMorte::recomecarFase));
    listaBotoes.push_back(new Botao<TelaMorte>("./imagens/SalvarPontuacao.png", pgg, Vector2f(1400.f,700.f), this, &TelaMorte::salvarPontuacao));
    listaBotoes.push_back(new Botao<TelaMorte>("./imagens/VoltarMenu.png", pgg, Vector2f(1400.f,1000.f), this, &TelaMorte::voltarMenu));
    cursor.setIterador(listaBotoes.begin());
}

TelaMorte::~TelaMorte()
{
    list<Botao<TelaMorte>*>::iterator ib = listaBotoes.begin();
    while (ib != listaBotoes.end())
    {
        if (*ib)
            delete(*ib);
        ib++;
    }
}

void TelaMorte::recomecarFase()
{
    setAtivo(false);
    pFase1->setAtivo(true);
}

void TelaMorte::voltarMenu()
{
    menu->executar();
}

void TelaMorte::executar(int nJ)
{
    nJogadores = nJ;
    bool clique = true;
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        if (clique)
        {
            cursor.avanca();
            clique = false;
        }
    }
    else if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        if (clique)
        {
            cursor.volta();
            clique = false;
        }
    }
    else if (Keyboard::isKeyPressed(Keyboard::Enter))
    {
        if (clique)
        {
            cursor.acao();
            clique = false;
        }
    }
    else
        clique = true;

    desenhar();
    
}

void TelaMorte::desenhar()
{
    pGerenciadorGrafico->desenharEnte(static_cast<Ente*>(this));
    list<Botao<TelaMorte>*>::iterator bi = listaBotoes.begin();
    for(bi = listaBotoes.begin(); bi != listaBotoes.end(); bi++)
        (*bi)->desenhar();
    cursor.desenhar();
}

void TelaMorte::salvarPontuacao()
{

}
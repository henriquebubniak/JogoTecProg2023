#include "TelaMorte.h"
#include "Fase1.h"
#include "Menu.h" 

TelaMorte::TelaMorte(GerenciadorGrafico* pgg, Fase1* pf1):
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
    pFase1->executaFase(nJogadores);
}

void TelaMorte::voltarMenu()
{
    menu->executar();
}

void TelaMorte::executar(int nJ)
{
    nJogadores = nJ;
    pGerenciadorGrafico->removerTodosEntes();
    incluirEntes();
    bool clique = true;
    while (pGerenciadorGrafico->get_JanelaAberta())
    {
        Event ev;
        while (pGerenciadorGrafico->pega_evento(&ev))
            if (ev.type == Event::Closed)
                pGerenciadorGrafico->fecha_janela();
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

        pGerenciadorGrafico->atualizaJanela();
    }
}

void TelaMorte::incluirEntes()
{
    pGerenciadorGrafico->incluiEnte(static_cast<Ente*>(this));
    list<Botao<TelaMorte>*>::iterator bi = listaBotoes.begin();
    for(bi = listaBotoes.begin(); bi != listaBotoes.end(); bi++)
        pGerenciadorGrafico->incluiEnte(static_cast<Ente*>(*bi));
    pGerenciadorGrafico->incluiEnte(static_cast<Ente*>(&cursor));
}

void TelaMorte::salvarPontuacao()
{

}
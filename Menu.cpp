#include "Menu.h"
#include "Jogo.h"

//Construtora e destrutora
Menu::Menu(GerenciadorGrafico* pgg, Fase1* pf1):
Ente("./imagens/menu.png", pgg),
pFase1(pf1),
listaBotoes(),
cursor("./imagens/cursor.png", pgg, &listaBotoes)
{
    listaBotoes.push_back(new Botao<Menu>("./imagens/botao1Fase1Jog.png", pgg, Vector2f(1400.f,400.f), this, &Menu::carrega1Fase1jog));
    listaBotoes.push_back(new Botao<Menu>("./imagens/botao1Fase2Jog.png", pgg, Vector2f(1400.f,700.f), this, &Menu::carrega1Fase2jog));
    listaBotoes.push_back(new Botao<Menu>("./imagens/botao2Fase1Jog.png", pgg, Vector2f(1400.f,1000.f), this, &Menu::carrega2Fase1jog));
    listaBotoes.push_back(new Botao<Menu>("./imagens/botao2Fase2Jog.png", pgg, Vector2f(1400.f,1300.f), this, &Menu::carrega2Fase2jog));
    cursor.setIterador(listaBotoes.begin());

}
Menu::~Menu(){}

void Menu::incluirEntes()
{
    pGerenciadorGrafico->incluiEnte(static_cast<Ente*>(this));
    list<Botao<Menu>*>::iterator bi = listaBotoes.begin();
    for(bi = listaBotoes.begin(); bi != listaBotoes.end(); bi++)
        pGerenciadorGrafico->incluiEnte(static_cast<Ente*>(*bi));
    pGerenciadorGrafico->incluiEnte(static_cast<Ente*>(&cursor));
}

//Loop eventos
void Menu::executar()
{
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



void Menu::carrega1Fase1jog()
{
    pFase1->executaFase(1);
}
void Menu::carrega1Fase2jog()
{
    pFase1->executaFase(2);
}
void Menu::carrega2Fase1jog()
{
}
void Menu::carrega2Fase2jog()
{
}


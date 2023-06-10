#include "Menu.h"
#include "Jogo.h"

//Construtora e destrutora
Menu::Menu(GerenciadorGrafico* pgg, Cidade* pf1):
Ente("./imagens/menu.png", pgg),
pFase1(pf1),
listaBotoes(),
cursor("./imagens/cursor.png", pgg, &listaBotoes),
clique(true)
{
    listaBotoes.push_back(new Botao<Menu>("./imagens/botao1Fase1Jog.png", pgg, Vector2f(0.f,100.f), this, &Menu::carrega1Fase1jog));
    listaBotoes.push_back(new Botao<Menu>("./imagens/botao1Fase2Jog.png", pgg, Vector2f(0.f,700.f), this, &Menu::carrega1Fase2jog));
    listaBotoes.push_back(new Botao<Menu>("./imagens/botao2Fase1Jog.png", pgg, Vector2f(0.f,1000.f), this, &Menu::carrega2Fase1jog));
    listaBotoes.push_back(new Botao<Menu>("./imagens/botao2Fase2Jog.png", pgg, Vector2f(0.f,1300.f), this, &Menu::carrega2Fase2jog));
    cursor.setIterador(listaBotoes.begin());
}
Menu::~Menu(){}

void Menu::executar()
{
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

void Menu::desenhar()
{
    pGerenciadorGrafico->desenharEnte(static_cast<Ente*>(this));

    for (list<Botao<Menu>*>::iterator it = listaBotoes.begin(); it != listaBotoes.end(); it++)
        (*it)->desenhar();
    
    cursor.desenhar();
    
}



void Menu::carrega1Fase1jog()
{
    setAtivo(false);
    pFase1->setAtivo(true);
}
void Menu::carrega1Fase2jog()
{
    setAtivo(false);
    pFase1->setDoisJogadores(true);
    pFase1->setAtivo(true);
}
void Menu::carrega2Fase1jog()
{
}
void Menu::carrega2Fase2jog()
{
}


#include "Menu.h"
#include "Jogo.h"

//Construtora e destrutora
Menu::Menu(GerenciadorGrafico* pgg, Jogo* j):
pGerenciadorGrafico(pgg),
jogo(j),
planoDeFundo("./imagens/menu.png"),
voceMorreu("./imagens/voceMorreu.png"),
cursor("./imagens/cursor.png", &listaBotoes)
{
    listaBotoes.push_back(new Botao("./imagens/botao1.png", Vector2f(1400.f,400.f), this, 1));
    listaBotoes.push_back(new Botao("./imagens/botao2.png", Vector2f(1400.f,700.f), this, 2));
    listaBotoes.push_back(new Botao("./imagens/botao3.png", Vector2f(1400.f,1000.f), this, 3));
    listaBotoes.push_back(new Botao("./imagens/botao4.png", Vector2f(1400.f,1300.f), this, 4));
    pGerenciadorGrafico->incluiEnte(&planoDeFundo);
    list<Botao*>::iterator bi = listaBotoes.begin();
    for(bi = listaBotoes.begin(); bi != listaBotoes.end(); bi++)
        pGerenciadorGrafico->incluiEnte(static_cast<Ente*>(*bi));
    cursor.setIterador(listaBotoes.begin());
    pGerenciadorGrafico->incluiEnte(static_cast<Ente*>(&cursor));

}
Menu::~Menu(){}

//Loop eventos
void Menu::executa_menu()
{
    while (pGerenciadorGrafico->get_JanelaAberta())
    {
        Event ev;
        while (pGerenciadorGrafico->pega_evento(&ev))
            if (ev.type == Event::Closed)
                pGerenciadorGrafico->fecha_janela();
        if (Keyboard::isKeyPressed(Keyboard::Down))
            cursor.avanca();
        if (Keyboard::isKeyPressed(Keyboard::Up))
            cursor.volta();
        if (Keyboard::isKeyPressed(Keyboard::Enter))
            cursor.acao();
        pGerenciadorGrafico->atualizaJanela();
        sleep(milliseconds(100));
    }
}

//Selecao do numero de jogadores
void Menu::selecaoNJogadores1()
{
    list <Botao*>::iterator ib;
    for(ib = listaBotoes.begin(); ib != listaBotoes.end(); ib++)
    {
        pGerenciadorGrafico->removerEnte(static_cast<Ente*>(*ib));
        delete(*ib);
    }
    listaBotoes.clear();
    listaBotoes.push_back(new Botao("./imagens/botao1Jog.png", Vector2f(1400.f,400.f), this, 5));
    listaBotoes.push_back(new Botao("./imagens/botao2Jog.png", Vector2f(1400.f,700.f), this, 6));
    list<Botao*>::iterator bi = listaBotoes.begin();
    for(bi = listaBotoes.begin(); bi != listaBotoes.end(); bi++)
        pGerenciadorGrafico->incluiEnte(static_cast<Ente*>(*bi));
    cursor.setIterador(listaBotoes.begin());
}
void Menu::selecaoNJogadores2()
{
    list <Botao*>::iterator ib;
    for(ib = listaBotoes.begin(); ib != listaBotoes.end(); ib++)
    {
        pGerenciadorGrafico->removerEnte(static_cast<Ente*>(*ib));
        delete(*ib);
    }
    listaBotoes.clear();
    listaBotoes.push_back(new Botao("./imagens/botao1Jog.png", Vector2f(1400.f,400.f), this, 7));
    listaBotoes.push_back(new Botao("./imagens/botao2Jog.png", Vector2f(1400.f,700.f), this, 8));
    list<Botao*>::iterator bi = listaBotoes.begin();
    for(bi = listaBotoes.begin(); bi != listaBotoes.end(); bi++)
        pGerenciadorGrafico->incluiEnte(static_cast<Ente*>(*bi));
    cursor.setIterador(listaBotoes.begin());
}

void Menu::carregaFase1(int nJ)
{
    jogo->carregaFase1(nJ);
}
void Menu::carregaFase2(int nJ)
{
    jogo->carregaFase2(nJ);
}
void Menu::telaMorte()
{
    pGerenciadorGrafico->removerTodosEntes();
    pGerenciadorGrafico->setPosicaoView(Vector2f(1280.f,800.f));
    listaBotoes.clear();
    pGerenciadorGrafico->incluiEnte(static_cast<Ente*>(&planoDeFundo));
    pGerenciadorGrafico->incluiEnte(static_cast<Ente*>(&voceMorreu));
    pGerenciadorGrafico->incluiEnte(static_cast<Ente*>(&cursor));
    listaBotoes.push_back(new Botao("./imagens/botaoRecomecar.png", Vector2f(1400.f,400.f), this, 1));
    listaBotoes.push_back(new Botao("./imagens/botaoMenuPrincipal.png", Vector2f(1400.f,700.f), this, 10));
    list<Botao*>::iterator bi = listaBotoes.begin();
    for(bi = listaBotoes.begin(); bi != listaBotoes.end(); bi++)
        pGerenciadorGrafico->incluiEnte(static_cast<Ente*>(*bi));
    cursor.setIterador(listaBotoes.begin());
    while (pGerenciadorGrafico->get_JanelaAberta())
    {
        Event ev;
        while (pGerenciadorGrafico->pega_evento(&ev))
            if (ev.type == Event::Closed)
                pGerenciadorGrafico->fecha_janela();
        if (Keyboard::isKeyPressed(Keyboard::Down))
            cursor.avanca();
        if (Keyboard::isKeyPressed(Keyboard::Up))
            cursor.volta();
        if (Keyboard::isKeyPressed(Keyboard::Enter))
            cursor.acao();
        pGerenciadorGrafico->atualizaJanela();
        sleep(milliseconds(100));
    }

}


#include "Fase.h"

//Construtora e destrutora
Fase::Fase(GerenciadorGrafico* pgg, Menu* m):
pGerenciadorGrafico(pgg),
gdc(&listaEntidade, pgg),
menu(m),
tempo(0)
{}

//Funcionalidades
void Fase::atualiza()
{
    moveEntidades();
    atacaEntidades();
    gdc.testaColisoes();
    pGerenciadorGrafico->atualizaJanela();
    tempo += 3;
}
void Fase::atacaEntidades()
{
    for (list<Entidade*>::iterator i = listaEntidade.begin(); i != listaEntidade.end(); i++)
        (*i)->ataca();
}
void Fase::moveEntidades()
{
    for (list<Entidade*>::iterator i = listaEntidade.begin(); i != listaEntidade.end(); i++)
        (*i)->move();
}
void Fase::executaFase(int nJ)
{
    adicionaPlataformas();
    adicionaJogador(nJ);
    pGerenciadorGrafico->removeTodosEntes();
    pGerenciadorGrafico->incluiEnte(&listaEnte);
    pGerenciadorGrafico->incluiEnte(&listaEntidade);
    while (pGerenciadorGrafico->get_JanelaAberta())
    {
        Event event;
        while (pGerenciadorGrafico->pega_evento(&event))
            if (event.type == Event::Closed)
                pGerenciadorGrafico->fecha_janela();
        atualiza();
    }
}
void Fase::carregaTelaMorte()
{
    menu->telaMorte();
}

//Adiciona e remove entes
void Fase::adEntidade(Entidade* e) {listaEntidade.push_front(e);}
void Fase::rmEntidade(Entidade* e) {listaEntidade.remove(e);}
void Fase::adEnte(Ente* e) {listaEnte.push_back(e);}
void Fase::rmEnte(Ente* e) {listaEnte.remove(e);}

//Gets
float Fase:: get_tempo() {return tempo;}
list<Entidade*>* Fase::get_lista_ent() {return &listaEntidade;}
GerenciadorGrafico* Fase::get_gerenciador_grafico() {return pGerenciadorGrafico;}
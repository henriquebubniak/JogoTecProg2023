#include "Fase.h"

//Construtora e destrutora
Fase::Fase(GerenciadorGrafico* pgg, TelaMorte* tm):
Ente("./imagens/FasePadrao.png", pgg),
listaEntidade(),
gdc(&listaEntidade, pgg),
telaMorte(tm),
tempo(0)
{}

//Funcionalidades
void Fase::atualiza()
{
    moverEntidades();
    atacaEntidades();
    gdc.testaColisoes();
    pGerenciadorGrafico->atualizaJanela();
    tempo += 3;
}
void Fase::atacaEntidades()
{
    for (list<Entidade*>::iterator i = listaEntidade.begin(); i != listaEntidade.end(); i++)
        (*i)->atacar();
}
void Fase::moverEntidades()
{
    for (list<Entidade*>::iterator i = listaEntidade.begin(); i != listaEntidade.end(); i++)
        (*i)->mover();
}
void Fase::executaFase(int nJ)
{
    pGerenciadorGrafico->removerTodosEntes();
    if(nJ == 1)
        removeJogador2();
    if(nJ == 2)
        adicionaJogador2();
    pGerenciadorGrafico->incluiEnte(&listaEntidade);
    pGerenciadorGrafico->incluiEnte(static_cast<Ente*>(this));

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
    telaMorte->executar();
}

//Adiciona e remove entes
void Fase::adEntidade(Entidade* e) {listaEntidade.push_front(e);}
void Fase::rmEntidade(Entidade* e) {listaEntidade.remove(e);}

//Gets
float Fase:: get_tempo() {return tempo;}
list<Entidade*>* Fase::get_lista_ent() {return &listaEntidade;}
GerenciadorGrafico* Fase::get_gerenciador_grafico() {return pGerenciadorGrafico;}

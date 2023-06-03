#include "Fase.h"

//Construtora e destrutora
Fase::Fase(GerenciadorGrafico* pgg, TelaMorte* tm):
Ente("./imagens/FasePadrao.png", pgg),
listaEntidades(),
gdc(&listaEntidades, pgg),
telaMorte(tm),
tempo(0),
doisJogadores(false)
{}

//Funcionalidades
void Fase::atualiza()
{
    
}

void Fase::executar()
{
    //lista entidades, this
    listaEntidades.executarEntidades();
    gdc.testaColisoes();
    listaEntidades.desenhar();
    tempo += 3;

}

void Fase::carregaTelaMorte()
{
    setAtivo(false);
    telaMorte->setAtivo(true);
    telaMorte->executar();
}

//Adiciona e remove entes
void Fase::adEntidade(Entidade* e) {listaEntidades.incluir(&e);}
void Fase::rmEntidade(Entidade* e) {listaEntidades.remover(&e);}

//Gets
float Fase:: get_tempo() {return tempo;}
ListaEntidades* Fase::get_lista_ent() {return &listaEntidades;}
GerenciadorGrafico* Fase::get_gerenciador_grafico() {return pGerenciadorGrafico;}
void Fase::setDoisJogadores(bool b) {doisJogadores = b;}

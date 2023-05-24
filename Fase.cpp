#include "Fase.h"

//Construtora e destrutora
Fase::Fase(GerenciadorGrafico* pgg, TelaMorte* tm):
Ente("./imagens/FasePadrao.png", pgg),
listaEntidade(),
gdc(&listaEntidade, pgg),
telaMorte(tm),
tempo(0),
doisJogadores(false)
{}

//Funcionalidades
void Fase::atualiza()
{
    
}
void Fase::executarEntidades()
{
    for (list<Entidade*>::iterator i = listaEntidade.begin(); i != listaEntidade.end(); i++)
        (*i)->executar();
}

void Fase::executar()
{
    //lista entidades, this
    executarEntidades();
    gdc.testaColisoes();
    desenhar();
    tempo += 3;

}

void Fase::desenhar()
{
    for (list<Entidade*>::iterator it = listaEntidade.begin(); it != listaEntidade.end(); it++)
    {
        if(doisJogadores)
            (*it)->desenhar();
        else
            if(*it != static_cast<Ente*>(getEnderecoJog2()))
                (*it)->desenhar();
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

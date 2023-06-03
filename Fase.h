#pragma once

#include <list>
#include "ListaEntidades.h"
#include "Entidade.h"
#include "Projetil.h"
#include "Obstaculo.h"
#include "GerenciadorColisoes.h"
#include "GerenciadorGrafico.h"
#include "TelaMorte.h"

using namespace std;

class Fase: public Ente
{
protected:
    ListaEntidades listaEntidades;
    GerenciadorDeColisoes gdc;
    TelaMorte* telaMorte;
    float tempo;
    bool doisJogadores;
public:
    //Construtora e eestrutora
    Fase(GerenciadorGrafico* pgg = NULL, TelaMorte* tm = NULL);
    ~Fase(){}

    //Funcionalidades
    void atualiza();
    void executar();
    void carregaTelaMorte();
    void desenhar();

    //Adiciona e remove
    void adEntidade(Entidade* e);
    void rmEntidade(Entidade* e);

    //Gets
    float get_tempo();
    ListaEntidades* get_lista_ent();
    GerenciadorGrafico* get_gerenciador_grafico();
    virtual Ente* getEnderecoJog2() = 0;
    void setDoisJogadores(bool b);

    virtual float getG() = 0;
};


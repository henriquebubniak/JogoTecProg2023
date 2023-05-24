#pragma once

#include <list>
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
    list<Entidade*> listaEntidade;
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
    void executarEntidades();
    void executar();
    void carregaTelaMorte();
    void desenhar();

    //Adiciona e remove
    void adEntidade(Entidade* e);
    void rmEntidade(Entidade* e);

    //Gets
    float get_tempo();
    list<Entidade*>* get_lista_ent();
    list<Projetil*>* get_lista_proj();
    list<Obstaculo*>* get_lista_obst();
    GerenciadorGrafico* get_gerenciador_grafico();
    virtual Ente* getEnderecoJog2() = 0;

    virtual float getG() = 0;
};


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
    Fase* proximaFase;
    float tempo;
    bool doisJogadores;
public:
    //Construtora e eestrutora
    Fase(GerenciadorGrafico* pgg = NULL, TelaMorte* tm = NULL, const char* cT = "./imagens/padrao.png", Fase* proxF = NULL);
    ~Fase(){}

    //Funcionalidades
    void executar();
    void carregaTelaMorte();
    void desenhar();

    //Adiciona e remove
    void adEntidade(Entidade* e);
    void rmEntidade(Entidade* e);

    //Getters e Setters 
    float get_tempo() const;
    const list<Entidade*>* get_lista_ent();
    GerenciadorGrafico* get_gerenciador_grafico() const;
    virtual Ente* getEnderecoJog2() = 0;
    void setDoisJogadores(bool b);
    virtual float getG() = 0;
    virtual bool verificaAvancoDeFase() = 0;
};


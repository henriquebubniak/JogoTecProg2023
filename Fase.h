#pragma once

#include <list>
#include "Entidade.h"
#include "Projetil.h"
#include "Obstaculo.h"
#include "GerenciadorColisoes.h"
#include "GerenciadorGrafico.h"
#include "Menu.h"

using namespace std;

class Fase
{
protected:
    list<Entidade*> listaEntidade;
    list<Ente*> listaEnte;
    GerenciadorDeColisoes gdc;
    GerenciadorGrafico* pGerenciadorGrafico;
    Menu* menu;
    float tempo;
public:
    //Construtora e eestrutora
    Fase(GerenciadorGrafico* pgg = NULL, Menu* m = NULL);
    ~Fase(){}

    //Funcionalidades
    void atualiza();
    void moverEntidades();
    void atacaEntidades();
    void executaFase(int nJ);
    virtual void adicionaJogador(int n){}
    virtual void adicionaPlataformas(){}
    void carregaTelaMorte();

    //Adiciona e remove
    void adEntidade(Entidade* e);
    void adEnte(Ente* e);
    void rmEntidade(Entidade* e);
    void rmEnte(Ente* e);

    //Gets
    float get_tempo();
    list<Entidade*>* get_lista_ent();
    list<Projetil*>* get_lista_proj();
    list<Obstaculo*>* get_lista_obst();
    GerenciadorGrafico* get_gerenciador_grafico();

    virtual float getG() = 0;
};


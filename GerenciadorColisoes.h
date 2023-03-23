#pragma once

#include "Projetil.h"
#include "Obstaculo.h"
#include "GerenciadorGrafico.h"
#include<list>

using namespace std;

class GerenciadorDeColisoes
{
private:
    list<Entidade*>* entidades;
    GerenciadorGrafico* pGerenciadorGrafico;
public:
    //construtora e destrutora
    GerenciadorDeColisoes(list<Entidade*>* ple = NULL, GerenciadorGrafico* pgg = NULL);
    ~GerenciadorDeColisoes();

    //testes
    void testaColisoes ();
    //void testaColisoesProjeteis();
    void testaColisoesEntidades ();
    //void testaColisoesObstaculos ();

    //sets
    void setListaEntidades (list<Entidade*>* ent);
    //void setListaProjeteis(list<Projetil*>* proj);
};


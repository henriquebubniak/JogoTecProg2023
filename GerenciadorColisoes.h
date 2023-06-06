#pragma once

#include "Projetil.h"
#include "Obstaculo.h"
#include "GerenciadorGrafico.h"
#include<list>
#include<iterator>

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
    void testaColisoesEntidades ();
    void testaColisaoPersonagemProjetil (list<Entidade*>::iterator i, list<Entidade*>::iterator j, list<Entidade*>* pListaMorte);
    void testaColisaoJogadorInimigo (list<Entidade*>::iterator i, list<Entidade*>::iterator j, list<Entidade*>* pListaMorte);

    //sets
    void setListaEntidades (list<Entidade*>* ent);
};


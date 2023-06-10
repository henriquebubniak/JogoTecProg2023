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
    void testeColisaoPersonagemObstaculo (list<Entidade*>::iterator i, list<Entidade*>::iterator j, list<Entidade*>* pListaMorte);
    void colisaoEsquerda(Entidade* e1, Entidade* e2);
    void colisaoDireita(Entidade* e1, Entidade* e2);
    void colisaoAcima(Entidade* e1, Entidade* e2);
    void colisaoAbaixo(Entidade* e1, Entidade* e2);

    //sets
    void setListaEntidades (list<Entidade*>* ent);
};


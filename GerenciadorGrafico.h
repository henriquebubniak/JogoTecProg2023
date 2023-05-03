#pragma once

#include "Ente.h"
#include<list>

using namespace std;
using namespace sf;

class Entidade;
class Obstaculo;
class Projetil;
class GerenciadorGrafico
{
private:
    list<Ente*> entes;
    RenderWindow janela;
    View view;
public:
    //construtora e destrutora
    GerenciadorGrafico();
    ~GerenciadorGrafico();

    //Funcionalidades
    void atualizaJanela();
    bool pega_evento(Event* ev);
    void fecha_janela();

    //Inclui e remove entidades
    void incluiEnte(Ente* e);
    void incluiEnte(list<Ente*>* ple);
    void incluiEnte(list<Entidade*>* ple);
    void removerEnte(Ente* e);
    void removerTodosEntes();

    //Sets e gets
    bool get_JanelaAberta();
    RenderWindow* getJanela();
    Vector2f converteCoord(Vector2i p);
    void setPosicaoView(Vector2f p = Vector2f(0.f,0.f));
    void moveView(Vector2f p);
};
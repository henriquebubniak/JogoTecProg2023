#pragma once

#include "Ente.h"
#include "ListaEnte.h"
#include<list>

using namespace std;
using namespace sf;

class Entidade;
class Obstaculo;
class Projetil;
class GerenciadorGrafico
{
private:
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
    void desenharEnte(Ente* e);
    void limpaJanela();

    //Sets e gets
    bool get_JanelaAberta() const;
    RenderWindow* getJanela();
    Vector2f converteCoord(Vector2i p);
    void setPosicaoView(Vector2f p = Vector2f(0.f,0.f));
    void moveView(Vector2f p);
};

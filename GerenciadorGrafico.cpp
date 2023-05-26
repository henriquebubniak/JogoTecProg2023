#include "GerenciadorGrafico.h"
#include "Entidade.h"
#include "Projetil.h"
#include "Obstaculo.h"

//Construra e destrutora
GerenciadorGrafico::GerenciadorGrafico():
    janela(VideoMode(800, 600, 32), "GREG", Style::Fullscreen),
    view(Vector2f(1280.f, 800.f), Vector2f(4000.f, 2500.f))
{
    janela.setPosition(Vector2i(0.f, 0.f));
    janela.setFramerateLimit(600);
    janela.setView(view);
}
GerenciadorGrafico::~GerenciadorGrafico(){}



//Funcionalidades
void GerenciadorGrafico:: atualizaJanela()
{
    janela.setView(view);
    janela.display();
}
bool GerenciadorGrafico::pega_evento(Event* ev) {return janela.pollEvent(*ev);}
void GerenciadorGrafico::fecha_janela() {janela.close();}
void GerenciadorGrafico::desenharEnte(Ente* e)
{
    janela.draw(e->getCaixa());
}
void GerenciadorGrafico::limpaJanela() {janela.clear();}

//Sets e gets
bool GerenciadorGrafico::get_JanelaAberta() {return janela.isOpen();}
RenderWindow* GerenciadorGrafico::getJanela() {return &janela;}
void GerenciadorGrafico::setPosicaoView(Vector2f p) {view.setCenter(p);}

void GerenciadorGrafico::moveView(Vector2f p) {view.move(p);}
Vector2f GerenciadorGrafico::converteCoord(Vector2i p) {return janela.mapPixelToCoords(p);}


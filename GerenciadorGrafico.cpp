#include "GerenciadorGrafico.h"
#include "Entidade.h"
#include "Projetil.h"
#include "Obstaculo.h"

//Construra e destrutora
GerenciadorGrafico::GerenciadorGrafico():
    janela(VideoMode(800, 600, 32), "GREG", Style::Fullscreen),
    entes(),
    view(Vector2f(1280.f, 800.f), Vector2f(4000.f, 2500.f))
{
    janela.setPosition(Vector2i(0.f, 0.f));
    janela.setFramerateLimit(600);
    janela.setView(view);
}
GerenciadorGrafico::~GerenciadorGrafico(){}

//Inclui e remove
void GerenciadorGrafico::incluiEnte(list<Entidade*>* ple)
{
    list<Entidade*>:: iterator enti;
    for (enti = ple->begin(); enti != ple->end(); enti++)
    {
        if(*enti)
            entes.push_back(static_cast<Ente*>(*enti));    
        else 
            cout << "ENTIDADE NULA NA LISTA PASSADA PARA GERENCIADOR GRAFICO" << endl;
    }
}
void GerenciadorGrafico::incluiEnte(list<Ente*>* ple)
{
    list<Ente*>:: iterator enti;
    for (enti = ple->begin(); enti != ple->end(); enti++)
    {
        if(*enti)
            entes.push_back(*enti);    
        else 
            cout << "ENTE NULO NA LISTA PASSADA PARA GERENCIADOR GRAFICO" << endl;
    }
}
void GerenciadorGrafico::incluiEnte(Ente* e) 
{
    if(e)
        entes.push_back(e);
    else
        cout << "ENTE NULO PASSADO PARA GERENCIADOR GRAFICO" << endl;
}
void GerenciadorGrafico::removerTodosEntes() {entes.clear();}
void GerenciadorGrafico::removerEnte(Ente* e) {entes.remove(e);}

//Funcionalidades
void GerenciadorGrafico:: atualizaJanela()
{
    janela.clear();
    janela.setView(view);
    list<Ente*>::iterator ente;
    for (ente = entes.begin(); ente != entes.end(); ente++)
        janela.draw((*ente)->getCaixa());
    janela.display();
}
bool GerenciadorGrafico::pega_evento(Event* ev) {return janela.pollEvent(*ev);}
void GerenciadorGrafico::fecha_janela() {janela.close();}

//Sets e gets
bool GerenciadorGrafico::get_JanelaAberta() {return janela.isOpen();}
RenderWindow* GerenciadorGrafico::getJanela() {return &janela;}
void GerenciadorGrafico::setPosicaoView(Vector2f p) {view.setCenter(p);}

void GerenciadorGrafico::moveView(Vector2f p) {view.move(p);}
Vector2f GerenciadorGrafico::converteCoord(Vector2i p) {return janela.mapPixelToCoords(p);}


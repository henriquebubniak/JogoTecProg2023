#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class GerenciadorGrafico;
class Ente
{
protected:    
    Sprite caixa;
    Texture textura;
    GerenciadorGrafico* pGerenciadorGrafico;
public:
    Ente(const char* cT = "./imagens/padrao.png", GerenciadorGrafico* pgg = NULL, Vector2f p = Vector2f(0.f,0.f));
    ~Ente();
    Sprite getCaixa();
    Vector2f getPosicao();
    FloatRect getGlobalBounds();
    void setPosicao (Vector2f p);
    void setImagem(const char* cT = "./imagens/padrao.png");
    void seImprimir();
};



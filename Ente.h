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
    bool ativo;
public:
    Ente(const char* cT = "./imagens/padrao.png", GerenciadorGrafico* pgg = NULL, Vector2f p = Vector2f(0.f,0.f));
    ~Ente();
    Sprite getCaixa() const;
    Vector2f getPosicao() const;
    FloatRect getGlobalBounds() const;
    bool getAtivo() const;
    void setPosicao (Vector2f p);
    void setImagem(const char* cT = "./imagens/padrao.png");
    void setAtivo(bool b);
    virtual void desenhar();
};



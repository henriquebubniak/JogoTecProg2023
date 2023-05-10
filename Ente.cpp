#include "Ente.h"
#include "GerenciadorGrafico.h"

//Construtora e destrutora
Ente::Ente(const char* caminhoTextura, GerenciadorGrafico* pgg, Vector2f p):
pGerenciadorGrafico(pgg)
{
    if (caminhoTextura)
    {
        if(!textura.loadFromFile(caminhoTextura))
            cerr << "ERRO: Nao foi possivel carregar a textura"<< endl;

        caixa.setTexture(textura);
    }
    caixa.setPosition(p);
}
Ente::~Ente(){}

//Gets e sets
Sprite Ente::getCaixa () {return caixa;}
Vector2f Ente::getPosicao () {return caixa.getPosition();}
FloatRect Ente::getGlobalBounds () {return caixa.getGlobalBounds();}
void Ente::setPosicao(Vector2f p) {caixa.setPosition(p);}
void Ente::setImagem(const char* cT)
{
    if (cT)
    {
        if(!textura.loadFromFile(cT))
            cerr << "ERRO: Nao foi possivel carregar a textura"<< endl;

        caixa.setTexture(textura);
    }
}
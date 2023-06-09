#include "Entidade.h"
#include "Fase.h"

//Constutora e destrutora
Entidade::Entidade(Vector2f p, const char* caminhoTextura, Fase* f, GerenciadorGrafico* pgg, Vector2f v):
Ente(caminhoTextura, pgg, p), pfase(f), velocidade(v), ID(0)
{}
Entidade::~Entidade() {pfase = nullptr;}

//Sets e gets
void Entidade:: setFase(Fase* f) 
{
    if (f)
        pfase = f;
    else
        cout << "FASE NULA EM setFase() DE ENTIDADE" << endl;
}
Vector2f Entidade::getVelocidade() const {return velocidade;}

void Entidade::setID(int i)
{
    ID = i;
}

int Entidade::getID() const
{
    return ID;
}

void Entidade::executar()
{
    mover();
    atacar();
}

void Entidade::setVelocidadeX(float v)
{
    velocidade.x = v;
}
void Entidade::setVelocidadeY(float v)
{
    velocidade.y = v;
}
